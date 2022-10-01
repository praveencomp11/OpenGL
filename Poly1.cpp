#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<glut.h>

#define MAX 10

using namespace std;

int i=0,n=0,flag=0,count=0;

/*need some modifications like better gui............
  not displaying initial plotpoints.......
  yepppppppppppeeeeeeeeeeeeeeeeeeeeeeeeeee
*/


class Polygon
{
public:
	GLint edges[10][2];
	Polygon()
	{
		for(int a=0;a<MAX;a++)
			for(int b=0;b<2;b++)
				edges[a][b]=0;
	}
	void drawpoly();
	void boundaryfill(int x,int y,int fillcolor);
	void floodfill(int x,int y,int fillcolor);
	void scanline(int arr[][2]);
}poly;
void Polygon::drawpoly()
{
	glColor3f(0.0,1.0,0.0);
	if(flag)
	{
	glBegin(GL_LINE_LOOP);
	for(i=0;i<n;i++)
		glVertex3f(edges[i][0],edges[i][1],0.0);
	glEnd();
	}
}
void Polygon::boundaryfill(int x,int y,int fillcolor)
{

}
void Polygon::scanline(int arr[10][2])				
{
	int   j,k,ymax=0,ymin=500,dx,dy,interx[10],temp;
	float m[10];
	glColor3f(0,1,0);
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
					glVertex3f(interx[j],y,0.0);
				    glVertex3f(interx[j+1]+1,y,0.0);
					glutPostRedisplay();

				}
			}
	}
	glEnd();
}
void init()
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void renderscene()
{
	poly.drawpoly();
	if(count>1)
		{
			poly.scanline(poly.edges);
			glutPostRedisplay();
		}
	glFlush();
}
void handleWindowResize(int width,int height)
{
		float ratio=1.0*width/height;

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glViewport(0,0,width,height);
		//gluPerspective(45.0,ratio,1,1000);
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
									  poly.edges[i][0]=x;
									  poly.edges[i][1]=y;
									  glPointSize(8);
									  glColor3f(1,1,1);
									  glBegin(GL_POINTS);
									  glVertex3f(x,y,0.0);//yepeeeeeeeeeeeeeee
									  glEnd();
									  if(i>0)
									  {
									  glBegin(GL_LINES);
									  glVertex3f(poly.edges[i-1][0],poly.edges[i-1][1],0);
									  glVertex3f(poly.edges[i][0],poly.edges[i][1],0);
									  glEnd();
									  }
									  cout<<i<<","<<poly.edges[i][0]<<","<<poly.edges[i][1];
									  cout<<endl;
									  i++;
									  //glutPostRedisplay();
								  }

								
								break;
		case GLUT_RIGHT_BUTTON:if(state==GLUT_DOWN)
								   {
									   poly.edges[i][0]=poly.edges[0][0];
									   poly.edges[i][1]=poly.edges[0][1];
									   flag=1;
									   n=i;
									   count++;
							       }

				break;

	}
	glutPostRedisplay();
}

void main(int argc,char **argv)
{
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("POLYGON FILLING");
	init();
	glutReshapeFunc(handleWindowResize);
	glutMouseFunc(handleMouse);
	glutDisplayFunc(renderscene);
	glutMainLoop();
}