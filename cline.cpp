#include<conio.h>
#include<iostream>
using namespace std;
#include<glut.h>

void init()
{
	glClearColor(0.3,0.3,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
}

void setp(int x,int y)
{
	glColor3f(0,1,0);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
}

class line
{
	int x1,y1,x2,y2;

public:
	void dda()
	{
		int i,dx,dy,steps;
		float x,y,xinc,yinc;
		cout<<"Enter the starting co-ordinates\n";
		cin>>x1>>y1;
		cout<<"\nEnter the ending co-ordinates\n";
		cin>>x2>>y2;
		dx=x2-x1;
		dy=y2-y1;
		if(abs(dx)>=abs(dy))
		{
			steps=abs(dx);
		}
		else
		{
			steps=abs(dy);
		}

		xinc=(float)dx/steps;
		yinc=(float)dy/steps;
		x=x1;
		y=y1;
		setp(x,y);

		for(i=1;i<steps;i++)
		{
			x=x+xinc;
			y=y+yinc;

			x1=x+0.5;
			y2=y+0.5;
			setp(x1,y2);
		}
	}

	int sign(float arg)
	{
		if(arg<0)
			return-1;
		else if(arg==0)
			return 0;
		else return 1;
	}

	void bres()
	{
		int i,dx,dy,steps;
		float x,y,xinc,yinc,g;
		cout<<"Enter the starting co-ordinates\n";
		cin>>x1>>y1;
		cout<<"\nEnter the ending co-ordinates\n";
		cin>>x2>>y2;
		dx=x2-x1;
		dy=y2-y1;
		x=x1;
		y=y1;
		g=2*dy-dx;
		setp(x1,y1);
		while(x<=x2)
		{
			if(g>=0)
			{
				x++;
				y++;
				g=g+2*dx;
			}

			if(g<0)
			{
				x++;
				g=g+2*(dy-dx);
			}
			setp(x1,y1);
		}
	}
	};

void display()
{
	line a;
	int ch,i;
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	do
	{
	cout<<"1. DDA\n2. Bresenhem\n3. Exit\n";
	cout<<"\nEnter your choice\t";
	cin>>ch;

	switch(ch)
	{
	case 1:glClear(GL_COLOR_BUFFER_BIT);
		for(i=-500;i<=500;i++)
		   {
			   setp(i,0);
			   setp(0,i);
		   }
		a.dda();
		break;
	case 2:glClear(GL_COLOR_BUFFER_BIT);
		for(i=-500;i<=500;i++)
		   {
			   setp(i,0);
			   setp(0,i);
		   }
		a.bres();
		break;
	case 3:exit(0);
		break;
	default:cout<<"\nEnter a valid choice\n";
	}
	}while(ch!=3);
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("Mahesh line");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
