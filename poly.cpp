#include<stdlib.h>
#include<glut.h>
#include<iostream>
#include<conio.h>

# include<Windows.h>

using namespace std;


GLint seedx=0,seedy=0;
GLint edges[10][2]={0};
int i=0,n=0,flag=0,count=0;

struct Color
{

    float red, green, blue;
}cg;

Color getPixel(int x, int y)
{                   // gets the color of the pixel at (x,y) 
    Color c;
    float color[4];
    glReadPixels(x,y,1,1,GL_RGBA, GL_FLOAT, color);
    c.red = color[0];   
    c.green = color[1];         
    c.blue = color[2];  
    return c;
}

void setPixel(int x, int y, Color c)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glColor3f(c.red, c.green, c.blue);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glPopAttrib();
    glFlush();
}


void scanline(int arr[10][2])				
{
	int   j,k,ymax=0,ymin=500,dx,dy,interx[10],temp;
	float m[10];
	glColor3f(1,0,0);
	
	glBegin(GL_LINES);
	
	//code for finding ymax and slopes of edges
	for(int j=0;j<n;j++)
	{
		if(arr[j][1]>=ymax)ymax=arr[j][1];
	    if(arr[j][1]<=ymin)ymin=arr[j][1];

		dx=arr[j+1][0]-arr[j][0];
		dy=arr[j+1][1]-arr[j][1];

		if(dx==0)m[j]=0;
		if(dy==0)m[j]=1;

		if(dx!=0&&dy!=0)
			m[j]=(float)dx/dy;

	}
	int cnt;
	for(int y=ymax;y>=ymin;y--)
	{
		cnt=0;
		
			for(k=0;k<n;k++)
			{
					if((arr[k][1]>y&&arr[k+1][1]<=y)||(arr[k][1]<=y&&arr[k+1][1]>y))
					{
						interx[cnt]=(arr[k][0]+(m[k]*(y-arr[k][1])));
						cnt++;
					}
			}
			for(k=0;k<cnt-1;k++)
			{
				for(j=0;j<cnt-1;j++)
				{
						if(interx[j]>interx[j+1])
						{
							temp=interx[j];
							interx[j]=interx[j+1];
							interx[j+1]=temp;
						}
				}
			
				for(j=0;j<cnt-1;j+=2)
				{	
					glBegin(GL_LINES);
					glVertex3f(interx[j],y,0.0);
					glVertex3f(interx[j+1]+1,y,0.0);
					glEnd();
					Sleep(10);

				}
			}
	}
	glEnd();
}

void Boundary_fill(int x,int y,Color thisColor){
    Color boundary_color;
    boundary_color.red=0.0;
    boundary_color.green=1.0;
    boundary_color.blue=0.0;
    Color nextpixel=getPixel(x,y);
    if((nextpixel.red!=boundary_color.red)&&(nextpixel.blue!=boundary_color.blue)&&(nextpixel.green!=boundary_color.green) && (nextpixel.red!=thisColor.red)&& (nextpixel.blue!=thisColor.blue)&& (nextpixel.green!=thisColor.green)){
        setPixel(x,y,thisColor);
		Sleep(20);
        Boundary_fill((x+1),y,thisColor);
        Boundary_fill((x-1),y,thisColor);
        Boundary_fill(x,(y+1),thisColor);
        Boundary_fill(x,(y-1),thisColor);
    }

}

void ffill(int x,int y,Color col)
{
	Color nextpixel=getPixel(x,y);
	if((nextpixel.green != col.green)&&(nextpixel.red!=col.red)&&(nextpixel.blue!=col.blue))
	{
		
		setPixel(x,y,col);
		Sleep(5);
		ffill(x-1,y,col);
		ffill(x+1,y,col);
		ffill(x,y-1,col);
		ffill(x,y+1,col);
	}



}


void display()
{
	Color thiscol;
	thiscol.red=0.0;
	thiscol.green=1.0;
	thiscol.blue=0.0;
	
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glColor3f(1.0,0.0,0.0);
	if(flag)
	{
	glBegin(GL_LINE_LOOP);
	for(i=0;i<n;i++)
		glVertex3f(edges[i][0],edges[i][1],0.0);
	if(count==2)
		{
			scanline(edges);
			glutPostRedisplay();
		}
	/*else if(count==3)
	{
		Boundary_fill(seedx,seedy,thiscol);
		glutPostRedisplay();
	}
	else if(count==4)
	{
		ffill(seedx,seedy,thiscol);
		glutPostRedisplay();
	}*/
	glutPostRedisplay();
	glEnd();
	}
	glFlush();
}
void handleWindowResize(int width,int height)
{
		float ratio=1.0*width/height;

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glViewport(0,0,width,height);
		
		glOrtho(0,width,height,0,-500,500);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
}
void handleMouse(int button,int state,int x,int y)
{
	switch(button)
	{
	    case GLUT_LEFT_BUTTON:if(state==GLUT_DOWN&&flag!=1)
							     {
									  edges[i][0]=x;
									  edges[i][1]=y;
									  cout<<"Mouse Co-ordinates : \n";
									  cout<<i<<","<<edges[i][0]<<","<<edges[i][1];
									  cout<<endl;
									  i++;
									  
								  }
							  if(flag==1&&state==GLUT_DOWN)
								{  seedx=x;
									seedy=y;
							  }
								
								break;
		case GLUT_RIGHT_BUTTON:if(state==GLUT_DOWN)
								   {
									   edges[i][0]=edges[0][0];
									   edges[i][1]=edges[0][1];
									   flag=1;
									   n=i;
									   count++;
							       }

				break;

	}
	glutPostRedisplay();
}

void menu()
{
	int choice;
	
	cout<<"\n1. Scan Line Filling";
	cout<<"\n2. Boundary Filling";
	cout<<"\n3. Flood Filling";
	cout<<"\n4. Exit";
	cout<<"\n\t\tEnter your choice: ";
	cin>>choice;
	switch(choice)
	{
	case 1:
		scanline(edges);
		glutPostRedisplay();
		break;

	case 2:
		Boundary_fill(seedx,seedy,cg);
		glutPostRedisplay();
		break;


	case 3:
		ffill(seedx,seedy,cg);
		glutPostRedisplay();
		break;

	case 4:
		exit(1);
		break;

	}

}

void keyboard(unsigned char key, int x, int y)
{

	switch(key)
	{
	case 13:
		menu();
		break;

	case 27:
		exit(1);
		break;
	}
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("POLYGON FILLING");
	glutReshapeFunc(handleWindowResize);
	glutMouseFunc(handleMouse);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;
}