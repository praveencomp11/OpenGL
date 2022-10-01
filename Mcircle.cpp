3#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
#include<glut.h>

void init()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,1.0,0.0,0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
	glColor3f(1,0,0);
}

void pixel(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
}

void sym(int x,int y,int x1,int y1)
{
	pixel(x+x1,y+y1);
	pixel(x+x1,y-y1);
	pixel(x-x1,y+y1);
	pixel(x-x1,y-y1);
	pixel(x+y1,y+x1);
	pixel(x+y1,y-x1);
	pixel(x-y1,y+x1);
	pixel(x-y1,y-x1);
}

void mid()
{
	int x,y,x1,y1,rad,p;
	cout<<"\nEnter the radius\n";
	cin>>rad;
	cout<<"\nEnter the centre\n";
	cin>>x>>y;
	p=1-rad;
	x1=0;
	y1=rad;
	while(x1<=y1)
	{
		if(p<=0)
		{
			x1++;
			p=p+(2*x1)+1;
		}
		else
		{
			x1++;
			y1--;
			p=p+2*x1-2*y1+1;
		}
		sym(x,y,x1,y1);
		//pixel(x1,y1);
	}
}

void bres()
{
	int x,y,x1,y1,rad,p;
	cout<<"\nEnter the radius\n";
	cin>>rad;
	cout<<"\nEnter the centre\n";
	cin>>x>>y;
	p=3-2*rad;
	x1=0;
	y1=rad;
	while(x1<=y1)
	{
		if(p<=0)
		{
			x1++;
			p=p+4*x1+6;
		}
		else
		{
			x1++;
			y1--;
			p=p+4*(x1-y1)+10;
		}
		sym(x,y,x1,y1);
		//pixel(x1,y1);
	}
}

void display()
{
	int ch,i;
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	do
	{
	cout<<"\n1. Mid point\n2. Bresnam\n3. exit\n\nEnter your choice\t";
	cin>>ch;
	glClear(GL_COLOR_BUFFER_BIT);
	switch(ch)
	{
	case 1:for(i=-500;i<=500;i++)
		   {
			   pixel(i,0);
			   pixel(0,i);
		   }
		   mid();
		   break;
	case 2:for(i=-500;i<=500;i++)
		   {
			   pixel(i,0);
			   pixel(0,i);
		   }
		  bres();
		   break;
	case 3:exit(0);
	}
	}while(ch!=3);
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("Mahesh");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}