#include<iostream>
#include <GL\glut.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define W 500
#define H 500

void initialize()
{
	glClearColor( 0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(-W, W,-H,H);
}

void setpixel(GLint,GLint);

class circle
{	public:
	int xc,yc,r;
	void midptcircle();
	void circlesymm(int,int,int,int);
	void bresenhem();
};

void circle::circlesymm(int xc,int yc,int x,int y)
{
	setpixel(xc+x,yc+y);
	setpixel(xc-x,yc+y);
	setpixel(xc+x,yc-y);
	setpixel(xc-x,yc-y);
	setpixel(xc+y,yc+x);
	setpixel(xc-y,yc+x);
	setpixel(xc+y,yc-x);
	setpixel(xc-y,yc-x);
}

void setpixel(GLint x, GLint y)
{	
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
}

void circle::midptcircle()
{
	int x,y,p;
	
	cout<<"\nEnter the centre coordinate of circle : ";
	cin>>xc>>yc;
	cout<<"\nEnter the radius of circle to be drawn : ";
	cin>>r;
	
	x=0;
	y=r;
	p=1-r;
	circlesymm(xc,yc,x,y);
	while(x<y)
	{
		x++;
		if(p<=0)
			p=p+(2*x)+1;
		else
		{
			y--;
			p=p+(2*(x-y))+1;
		}
		circlesymm(xc,yc,x,y);
	}
}

void circle::bresenhem()
{
	int x,y,s;
	
	cout<<"\nEnter the centre coordinate of circle : ";
	cin>>xc>>yc;
	cout<<"\nEnter the radius of circle to be drawn : ";
	cin>>r;
	
	x=0;
	y=r;
	s=3-(2*r);
	circlesymm(xc,yc,x,y);
	while(x<y)
	{
		x++;
		if(s<=0)
			s=s+(4*x)+6;
		else
		{
			s=s+(4*(x-y))+10;
			y--;
		}
		circlesymm(xc,yc,x,y);
	}
}

void choice()
{
	circle c;
	int ch,ch1=1,i;
	glClear(GL_COLOR_BUFFER_BIT);
   
	glPointSize(2+.0);
	for(i=-500;i<500;i++)
	{
		setpixel(i,0);
		setpixel(0,i);
	}
	while(1)
	{	if(ch1!=1)
		exit(0);
		cout<<"\t\t\t\t\tCIRCLE GENRATION\n1.mid point\n2.Bresenhem's\n3.Exit\n";
		cout<<"\Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			glClear(GL_COLOR_BUFFER_BIT);
			for(i=-500;i<500;i++)
			{
				setpixel(i,0);
				setpixel(0,i);
			}
			c.midptcircle();
		break;
		case 2:
			glClear(GL_COLOR_BUFFER_BIT);
			for(i=-500;i<500;i++)
			{
				setpixel(i,0);
				setpixel(0,i);
			}
			c.bresenhem();
		break;
		case 3:
			exit(0);
		break;
		}
		cout<<"\n\nEnter 1 to continue:";
		cin>>ch1;
	}
}




int main(int argc, char** argv) 
{	
	
		
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(W,H);
	glutCreateWindow("\t\t\tOPENGL CIRCLE GENERATION");
	initialize();
	glutDisplayFunc(choice);
	glutMainLoop();
	return(0);
}
