#include<iostream>
#include<math.h>
#include<GL\glut.h>

#define MAX 10
#define width 640
#define height 480
#define PI 3.141

using namespace std;

static int index=0;
int flag=0,done=0;
int xPrev,yPrev,xEnd,yEnd;
class Transformations
{
private:
	GLfloat  points[MAX][3];							//this will store point coordinates
	GLfloat  res_points[MAX][3];						//transformations will work on these
	GLfloat  trans_arr[3][3];
	GLfloat  temp_arr[MAX][3];							//temp array
	GLint    tx,ty;
	GLint    sx,sy;
	GLdouble theta;									//rotation angle
public:
	int      n;											//total no of points

	Transformations()								// constructor to create identity matrix
	{
		for(int i=0;i<MAX;i++)
		{
			for(int j=0;j<3;j++)
			{
				temp_arr[i][j]=0;
			}
		}
		
	}

	void   Identity();
	void   setpoints(int x,int y);
	void   draw(); 
	void   translate();
	void   rotate();
	void   scale();
	void   shear();
	void   reflection();
	void multiply(GLfloat points[][3],GLfloat trans[3][3],int n);
	friend void renderscene();
	friend void menu();
}t;
//gui related functions
/*======================================================================================================================*/
void Transformations::Identity()
{
	for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(i==j)
				trans_arr[i][j]=1;
				else
				trans_arr[i][j]=0;
			}
		}
}
void Transformations::setpoints(int x,int y)
{
	points[index][0]=x;
	points[index][1]=y;
	points[index][2]=1;

	index++;
	n=index;
}
void Transformations::draw()
{
	int i=0;
	glColor3f(0.0,0.6,0.0);
	glBegin(GL_LINE_LOOP);
	for(i=0;i<n;i++)
	{
		glVertex3f(points[i][0],points[i][1],0.0);
	}
	glEnd();
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_LINE_LOOP);
	for(i=0;i<n;i++)
	{
		glVertex3f(res_points[i][0],res_points[i][1],0.0);
	}
	glEnd();
}
void Transformations::multiply(GLfloat points[][3],GLfloat trans[3][3],int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
				res_points[i][j]=0;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
				res_points[i][j]+=points[i][k]*trans[k][j];
		}
	}
}
void menu()
{
	cout<<"\n\n\t\t\tMENU";
	cout<<"\nTRANSLATION(t)";
	cout<<"\nROTATION(r)";
	cout<<"\nSCALE(s)";
	cout<<"\nSHEAR(S)";
	cout<<"\nREFLECTION(R)";
	cout<<"\nSelect option in brackets\n";
}
//======================================================================================================================
void Transformations::translate()
{
	cout<<"\nEnter the value of tx,ty:";
	cin>>tx>>ty;
	this->Identity();
	this->trans_arr[2][0]=tx;
	this->trans_arr[2][1]=ty;
	/*cout<<"\nTranslation Matrix\n";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<this->trans_arr[i][j]<<",";
		}
		cout<<endl;
	}*/
	/*cout<<"\nPoints\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<points[i][j]<<",";
		}
		cout<<endl;
	}*/
	multiply(points,trans_arr,n);
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<points[i][j]<<",";
		}
		cout<<endl;
	}*/
}
void Transformations::rotate()
{
	this->Identity();
	cout<<"\nEnter the rotation angle(anticlockwise,-ve values for clockwise rotation):";
	cin>>theta;
	theta=PI*theta/180;
	this->trans_arr[0][0]=cos(theta);
	this->trans_arr[0][1]=sin(theta);
	this->trans_arr[1][0]=-sin(theta);
	this->trans_arr[1][1]=trans_arr[0][0];

	/*cout<<"\nRotation Matrix\n";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<this->trans_arr[i][j]<<",";
		}
		cout<<endl;
	}*/
	/*cout<<"\nPoints\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<points[i][j]<<",";
		}
		cout<<endl;
	}*/
	multiply(points,trans_arr,n);
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<points[i][j]<<",";
		}
		cout<<endl;
	}*/
}						//no problem with drawing funtions check for exceptions
void Transformations::scale()
{
	this->Identity();
	cout<<"\nEnter sx and sy:";
	cin>>sx>>sy;
	this->trans_arr[0][0]=sx;
	this->trans_arr[1][1]=sy;

	/*cout<<"\nScaling Matrix\n";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<this->trans_arr[i][j]<<",";
		}
		cout<<endl;
	}
	cout<<"\nPoints\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<points[i][j]<<",";
		}
		cout<<endl;
	}*/
	multiply(points,trans_arr,n);
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<points[i][j]<<",";
		}
		cout<<endl;
	}*/
}
void Transformations::shear()
{
	this->Identity();
	int a=0,b=1;
	int s;
	char dir;
	cout<<"\nX-Shear or Y-Shear(x/y)?";
	cin>>dir;
	cout<<"\nEnter shearing factor:";
	cin>>s;
	if(dir=='x')
		b=s;
	if(dir=='y')
		a=s;

	this->trans_arr[0][1]=a;
	this->trans_arr[1][0]=b;

	/*cout<<"\nShearing Matrix\n";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<this->trans_arr[i][j]<<",";
		}
		cout<<endl;
	}
	cout<<"\nPoints\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<points[i][j]<<",";
		}
		cout<<endl;
	}*/
	multiply(points,trans_arr,n);
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<points[i][j]<<",";
		}
		cout<<endl;
	}*/
}
void Transformations::reflection()
{
	this->Identity();
	int a=-1,b=-1;
	char dir;
	cout<<"\nReflection Menu\n";
	cout<<"\nx=>X-Axis";
	cout<<"\ny=>Y-Axis";
	cout<<"\no=>Origin";
	cout<<"\n/=>Y=X";
	cin>>dir;

	if(dir=='x')
		a=-a;
	if(dir=='y')
		b=-b;
	this->trans_arr[0][0]=a;
	this->trans_arr[1][1]=b;

	if(dir=='/')
	{
		this->trans_arr[0][0]=0;
		this->trans_arr[1][1]=0;
		this->trans_arr[0][1]=1;
		this->trans_arr[1][0]=1;
	}
	/*cout<<"\nReflection Matrix\n";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<this->trans_arr[i][j]<<",";
		}
		cout<<endl;
	}
	cout<<"\nPoints\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<points[i][j]<<",";
		}
		cout<<endl;
	}*/
	multiply(points,trans_arr,n);
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<points[i][j]<<",";
		}
		cout<<endl;
	}*/
}
//=======================================================================================================================
void updatescreen()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glutPostRedisplay();
}

void handleResize(int w,int h)
{
	if(h==0)
		h=1;					//divide by zero escape
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,(GLdouble)(w/h),-5,5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void handleMouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:if(state==GLUT_DOWN&&flag==0)
				   {
					   x=2*x-width;
					   y=height-2*y;
					   glColor3f(1,1,1);
					   glPointSize(4);
					   glBegin(GL_POINTS);
					   glVertex3f(x,y,0.0);
					   glEnd();

					   if(t.n==0)
					   {
					   xPrev=x;
					   yPrev=y;
					   }
					   else
					   {
						   xPrev=xEnd;
						   yPrev=yEnd;
					   }
					   xEnd=x;
					   yEnd=y;

					   if(t.n>0)
					   {
						   glBegin(GL_LINES);
						   glVertex3f(xPrev,yPrev,0.0);
						   glVertex3f(xEnd,yEnd,0.0);
					       glEnd();
					   }
					   t.setpoints(x,y);
				   }
				   break;
	case GLUT_RIGHT_BUTTON:if(state==GLUT_DOWN&&!flag)
					{
						flag=1;
					}
				   break;
	}
	glutPostRedisplay();
}
void handlekeyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
	case 't':t.translate();
			break;
	case 'r':t.rotate();
		    break; 
	case 's':t.scale();
			break;
	case 'S':t.shear();
			break;
	case 'R':t.reflection();
			break;
	}
updatescreen();
}
void init()
{
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(-width,width,-height,height,-100,100);
}
void renderscene()
{
	glColor3f(0.5,0,0);
	glBegin(GL_LINES);
	glVertex3f(-width,0,0);
	glVertex3f(width,0,0);

	glVertex3f(0,height,0);
	glVertex3f(0,-height,0);

	glEnd();
	if(flag)
	t.draw();
	
glFlush();
glutSwapBuffers();
}
void main(int argc,char **argv)
{
	menu();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_SINGLE);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(width,height);
	glutCreateWindow("TRANSFORMATIONS");
	init();
	glutMouseFunc(handleMouse);
	glutKeyboardFunc(handlekeyboard);
	glutDisplayFunc(renderscene);
	glutMainLoop();
}
