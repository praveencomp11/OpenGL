
#include<iostream>
#include <glut.h>
#include <math.h>

using namespace std;
#define W 600
#define H 600

void initialize()
{
	glClearColor( 0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(-W, W,-H,H);
}

void setPixel(GLint,GLint);

class line
{	
public:
	int x0,x1,y0,y1;
	void Bresenhem()
	{	
		cout<<"\nEnter the starting coordinates: \n";
		cin>>x0;
		cin>>y0;
		cout<<"\nEnter the ending coordinates:\n";
		cin>>x1;
		cin>>y1;
		GLint dx,dy,stp,i=0,x,y,g;
		if(x0>=x1 && y0>=y1)
		{
			x=x1;
			y=y1;
		}
		else
		{
			x=x0;
			y=y0;
		}
		dx=abs(x1-x0);
		dy=abs(y1-y0);
		if(x0>x1 && y0<y1)
		{
			if(dx>=dy)
			{
				g=2*dy-dx;
				stp=dx;
				while(i<=stp)
				{
					if(g>0)
					{
						y--;
						g+=2*(dy-dx);
					}
					else
					{
						g+=2*dy;
					}
				x++;
				i++;
				setPixel(x,y);

				}
			}
			else
			{
				i=0;
				g=2*dx-dy;
				stp=dy;
				while(i<=stp)
				{
					if(g>0)
					{
						x--;
						g+=2*(dy-dx);
					}
					else
					{
						g+=2*dx;
					}
					y++;
					i++;
					setPixel(x,y);
				}
			}
		}
		else
		if(x0<x1&&y0>y1)
		{
			if(dx>=dy)

			{
				g=dx-2*dy;
				stp=dx;
				while(i<=stp)
				{
					if(g>0)
					{
						y--;
						g+=2*(dx-dy);
					}
					else
					{
						g+=2*dy;
					}
					x++;
					i++;
					setPixel(x,y);
				}
			}
			else
			{
				i=0;
				g=2*dy-dx;
				stp=dy;
				while(i<=stp)
				{
					if(g>0)
					{
						x--;
						g+=2*(dx-dy);
					}
					else
					{
						g+=2*dx;
					}
					y++;
					i++;
					setPixel(x,y);
				}
			}
		}
		else
		{
			if(dx>=dy)
			{	g=2*dy-dx;
				stp=dx;
				while(i<=stp)
				{
				if(g>0)
				{
					y++;
					g+=2*(dy-dx);
				}
				else
				{
					g+=2*dy;
				}
				x++;
				i++;
				setPixel(x,y);
				}
			}
			else
			{
				i=0;
				g=2*dx-dy;
				stp=dy;
				while(i<=stp)
				{
					if(g>0)
					{
						x++;
						g+=2*(dy-dx);
					}
					else
					{
						g+=2*dx;
					}
					y++;
					i++;
					setPixel(x,y);
				}
			}
		}
	}	

	void DDA()
	{	
		cout<<"Enter the starting coordinates:";
		cin>>x0>>y0;
		cout<<"Enter the ending coordinates:";
		cin>>x1>>y1;
		GLint dy = y1 - y0;
		GLint dx = x1 - x0;
		GLint stp,i;
		GLfloat xinc,yinc,x=x0,y=y0;
		if( abs(dx) >= abs(dy))
		{
			stp=abs(dx);
		}
		else
		{
			 stp=abs(dy);
		}
		xinc=(float) dx/ (float) stp;
		yinc=(float) dy/ (float) stp;
		setPixel(x,y);
		for(i=0;i<stp;i++)
		{
			 x+=xinc;
			 y+=yinc;
			 setPixel(x,y);
		}
	}
};

void setPixel(GLint x, GLint y)
{	
	glColor3f(7,0,0);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
}

void choice()
{
	line l;
	int ch,ch1=1,i;
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3+.0);
	for(i=-900;i<900;i++)
	{
		setPixel(i,0);
	}
	for(i=-600;i<600;i++)
	{
		setPixel(0,i);
	}
	while(1)
	{	
		if(ch1!=1)
			exit(0);
		system("cls");
		cout<<"\n\n\n\nLine Generation";
		cout<<"\n\n 1.Bresenhem's";
		cout<<"\n\n 2.DDA";
		cout<<"\n\n 3.Exit";
		cout<<"\n\n Enter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1 :
				glClear(GL_COLOR_BUFFER_BIT);
				for(i=-900;i<900;i++)
				{
					setPixel(i,0);
				}
				for(i=-600;i<600;i++)
				{
					setPixel(0,i);
				}
				l.Bresenhem();
				break;
		case 2 :
				glClear(GL_COLOR_BUFFER_BIT);
				for(i=-900;i<900;i++)
				{
					setPixel(i,0);
				}
				for(i=-600;i<600;i++)
				{
					setPixel(0,i);
				}
				l.DDA();
				break;
		case 3 :
				exit(0);
				break;
		}
		cout<<"Enter 1 to continue:";
		cin>>ch1;
	}
}

int main(int argc, char** argv) 
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(600,100);
	glutInitWindowSize(W,H);
	glutCreateWindow("OpenGL line generation");
	initialize();
	glutDisplayFunc(choice);
	glutMainLoop();
	return(0);
}
