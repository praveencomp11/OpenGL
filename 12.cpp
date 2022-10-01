#include<windows.h>
#include<iostream>
using namespace std;
#include<gl/glut.h>

#define W 500
#define H 500
#define MAX_PTS 50
#define PI 3.1415926535898

int w=W,h=H;
float initial_fig[MAX_PTS][2],final_fig[MAX_PTS][2];
static int index;
static int figure;

int flag=0;
float pt[2];

void display_axes();

void transform(float a[3],float trans[3][3],float final_pt[3])
{
	for(int i=0;i<3;i++)
	{
		final_pt[i]=0;
		for(int j=0;j<3;j++)
			final_pt[i]=final_pt[i]+a[j]*trans[j][i];
	}
}

void display_fig(float fig[MAX_PTS][2])
{
	for(int i=1;i<=figure;i++)
	{
		glBegin(GL_POINTS);
			glVertex2fv(fig[i-1]);
		glEnd();
		if(i>1)
		{
			glBegin(GL_LINES);
				glVertex2fv(fig[i-2]);
				glVertex2fv(fig[i-1]);
			glEnd();
		}
	}
	glBegin(GL_LINES);
		glVertex2f(fig[figure-1][0],final_fig[figure-1][1]);
		glVertex2f(fig[0][0],final_fig[0][1]);
	glEnd();
	glFlush();
}

void translate()
{
	float x,y;
	cout<<"\nEnter translation distances ( Tx & Ty) : ";
	cin>>x>>y;
	float trans[3][3]={1,0,0,0,1,0,x,y,1},fin[3],ini[3];
	for(int i=0;i<figure;i++)
	{
		ini[0]=initial_fig[i][0];
		ini[1]=initial_fig[i][1];
		ini[2]=1;
		transform(ini,trans,fin);
		final_fig[i][0]=fin[0];
		final_fig[i][1]=fin[1];
	}
	display_fig(final_fig);
}

void scale()
{
	float x,y;
	cout<<"\nEnter Scaling factors ( Sx & Sy) : ";
	cin>>x>>y;
	float trans[3][3]={x,0,0,0,y,0,0,0,1},fin[3],ini[3];
	for(int i=0;i<figure;i++)
	{
		ini[0]=initial_fig[i][0];
		ini[1]=initial_fig[i][1];
		ini[2]=1;
		transform(ini,trans,fin);
		final_fig[i][0]=fin[0];
		final_fig[i][1]=fin[1];
	}
	display_fig(final_fig);
}

void rotate(float theta,float x,float y)
{
	float cos_theta,sin_theta;
	theta=theta*PI/180;
	cos_theta=cos(theta);
	sin_theta=sin(theta);
	float trans[3][3]={cos_theta,sin_theta,0,-sin_theta,cos_theta,0,-x*cos_theta+y*sin_theta+x,-x*sin_theta-y*cos_theta+y,1},fin[3],ini[3];
	for(int i=0;i<figure;i++)
	{
		ini[0]=initial_fig[i][0];
		ini[1]=initial_fig[i][1];
		ini[2]=1;
		transform(ini,trans,fin);
		final_fig[i][0]=fin[0];
		final_fig[i][1]=fin[1];
	}
	display_fig(final_fig);
}

void reflect(int option)
{
	float fin[3],ini[3],trans[3][3]={1,0,0,0,-1,0,0,0,1};
	switch(option)
	{
	case 1:
		break;
	case 2:
		trans[0][0]=-1;
		trans[1][1]=1;
		break;
	case 3:
		trans[0][0]=-1;
		trans[1][1]=-1;
		break;
	case 4:
		trans[0][0]=0;
		trans[0][1]=1;
		trans[1][0]=1;
		trans[1][1]=0;
		break;
	case 5:
		trans[0][0]=0;
		trans[0][1]=-1;
		trans[1][0]=-1;
		trans[1][1]=0;
		break;
	}
	for(int i=0;i<figure;i++)
	{
		ini[0]=initial_fig[i][0];
		ini[1]=initial_fig[i][1];
		ini[2]=1;
		transform(ini,trans,fin);
		final_fig[i][0]=fin[0];
		final_fig[i][1]=fin[1];
	}
	display_fig(final_fig);
}

void shear(int option)
{
	float a,b,fin[3],ini[3];
	switch(option)
	{
	case 1:
		cout<<"\nEnter the shear factor : ";
		cin>>b;
		a=0;
		break;
	case 2:
		cout<<"\nEnter the shear factor : ";
		cin>>a;
		b=0;
		break;
	}
	float trans[3][3]={1,a,0,b,1,0,0,0,1};
	for(int i=0;i<figure;i++)
	{
		ini[0]=initial_fig[i][0];
		ini[1]=initial_fig[i][1];
		ini[2]=1;
		transform(ini,trans,fin);
		final_fig[i][0]=fin[0];
		final_fig[i][1]=fin[1];
	}
	display_fig(final_fig);
}


void processMainMenu(int option)
{
	switch(option)
	{
	case 1:
		translate();
		break;
	case 2:
		scale();
		break;
	}
}

void processRotateMenu(int option)
{
	float theta;
	switch(option)
	{
	case 1:
		cout<<"\nEnter Angle of Rotation (degrees) : ";
		cin>>theta;
		rotate(theta,0.0,0.0);
		break;
	case 2:
		cout<<"\n\tSelect the base point on the screen ";
		flag=1;
		break;
	}
}

void processReflectMenu(int option)
{
	reflect(option);
}

void processShearMenu(int option)
{
	shear(option);
}

void MainMenu()
{
	int menu,reflectmenu,rotatemenu,shearmenu;
	menu=glutCreateMenu(processMainMenu);
	rotatemenu=glutCreateMenu(processRotateMenu);
	reflectmenu=glutCreateMenu(processReflectMenu);
	shearmenu=glutCreateMenu(processShearMenu);
	glutSetMenu(menu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddMenuEntry("Translate",1);
	glutAddMenuEntry("Scale",2);
	glutAddSubMenu("Rotate",rotatemenu);
	glutAddSubMenu("Reflect",reflectmenu);
	glutAddSubMenu("Shear",shearmenu);
	glutSetMenu(rotatemenu);
	glutAddMenuEntry("About Origin",1);
	glutAddMenuEntry("About Arbit. Point",2);
	glutSetMenu(reflectmenu);
	glutAddMenuEntry("About X-Axis",1);
	glutAddMenuEntry("About Y-Axis",2);
	glutAddMenuEntry("About Origin",3);
	glutAddMenuEntry("About Line y=x",4);
	glutAddMenuEntry("About Line y=-x",5);
	glutSetMenu(shearmenu);
	glutAddMenuEntry("X Shear",1);
	glutAddMenuEntry("Y Shear",2);
}

void keyboard(unsigned char key,int x,int y)
{
	GLint circle_points;
	GLfloat angle,transx,transy,d;
	switch(key) 
	{
	case 8:
		glClear(GL_COLOR_BUFFER_BIT);
		display_axes();
		figure=0;
		index=0;
		break;
	case 13:
		if(index>2)
		{
			glBegin(GL_LINES);
				glVertex2f(initial_fig[index-1][0],initial_fig[index-1][1]);
				glVertex2f(initial_fig[0][0],initial_fig[0][1]);
			glEnd();
			glFlush();
		}
		index=0;
		break;
	case 'c':
		if(index==2)
		{
			//glClear(GL_COLOR_BUFFER_BIT);
			display_axes();
			d=pow((initial_fig[0][0]-initial_fig[1][0]),2)+pow((initial_fig[0][1]-initial_fig[1][1]),2);
			d=sqrt(d)/2;
			transx=(initial_fig[0][0]+initial_fig[1][0])/2;
			transy=(initial_fig[0][1]+initial_fig[1][1])/2;
			circle_points=d*2/3;
			glBegin(GL_POINTS);
				glVertex2f(transx,transy);
			glEnd();
			glPointSize(0.3);
			glBegin(GL_POINTS);
			for(int i=0;i<circle_points;i++)
			{       
				angle=2*PI*i/circle_points;
				glVertex2f(transx+d*cos(angle),transy+d*sin(angle));
			} 
			glEnd();
			glFlush();
			glPointSize(3.0);
			index=0;			
		}
		break;
	case 'l':
		index=0;
		break;
	case 27:			
		exit(0);
		break;
	}
}

void mouse(int button,int state,int x,int y) 
{
	if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && flag==0)
	{
		figure=index;
		y=h-y*h/(h-1);
		initial_fig[index][0]=x*2-w;
		initial_fig[index][1]=y*2-h;
		glBegin(GL_POINTS);
			glVertex2fv(initial_fig[index]);
		glEnd();
		glFlush();
		index++;
		figure++;
		if(index>1&&index<MAX_PTS+1)
		{
			glBegin(GL_LINES);
				glVertex2fv(initial_fig[index-2]);
				glVertex2fv(initial_fig[index-1]);
			glEnd();
			glFlush();
			if(index==MAX_PTS)
			{
				glBegin(GL_LINES);
					glVertex2f(initial_fig[MAX_PTS-1][0],initial_fig[MAX_PTS-1][1]);
					glVertex2f(initial_fig[0][0],initial_fig[0][1]);
				glEnd();
				glFlush();
				index=0;
			}
		}
	}
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && flag==1)
	{
		float theta;
		y=H-y*H/(H-1);
		pt[0]=x*2-W;
		pt[1]=y*2-H;
		cout<<"\nEnter Angle of Rotation (degrees) : ";
		cin>>theta;
		rotate(theta,pt[0],pt[1]);
		flag=0;
	}	
}

void init(int w,int h)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w, w,-h,h);
	glPointSize(3.0);
	glLineWidth(1.0);
	glColor3f(1.0,0.3,0.0);
}

void display_axes()
{
	glBegin(GL_LINES);
		glVertex2f(-w,0);
		glVertex2f(w,0);
		glVertex2f(0,-h);
		glVertex2f(0,h);
	glEnd();
	glFlush();
}

void disp()
{
	MainMenu();
	display_axes();
}

void resize(int w, int h)
{
	init(w,h);
	::w=w;
	::h=h;
	index=0;
	figure=0;
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glClear(GL_COLOR_BUFFER_BIT);
	glutPostRedisplay();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(65,0);
	glutInitWindowSize(W,H);
	glutCreateWindow("2-D Transformations");
	init(w,h);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);	
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(disp);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}