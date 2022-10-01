
#include<iostream>
#include<process.h>
#include<conio.h>
using namespace std;
#include<glut.h>
void setpixel(GLint x,GLint y)
{
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
	glutPostRedisplay();
}

class line
{
	GLint x1,y1,x2,y2;
public:
	void linedda()
	{
		GLint dx,dy,n;
		GLfloat xinc,yinc,x,y;
		cout<<"\nEnter the starting vertex : ";
		cin>>x1>>y1;
		cout<<"\nEnter the ending vertex : ";
		cin>>x2>>y2;
		dx=x2-x1;
		dy=y2-y1;
		if(abs(dx)>=abs(dy))
			n=abs(dx);
		else
			n=abs(dy);
		xinc=float(dx)/n;
		yinc=float(dy)/n;
		x=x1;
		y=y1;
		setpixel(x1,y1);
		for(int k=0;k<n;k++)
		{
			x+=xinc;
			y+=yinc;
			x1=x+0.5;
			y1=y+0.5;
			setpixel(x1,y1);
		}
	}
	void bres()
	{
		GLint dx,dy,p,x,y,t,xend,yend,yinc=1,xinc=1,f;
		cout<<"\nEnter the starting vertex : ";
		cin>>x1>>y1;
		cout<<"\nEnter the ending vertex : ";
		cin>>x2>>y2;
		if(x1<x2)
		{
			x=x1;
			y=y1;
			xend=x2;
			yend=y2;
			dx=x2-x1;
			dy=y2-y1;
		}
		else
		{
			x=x2;
			y=y2;
			xend=x1;
			yend=y1;
			dx=x1-x2;
			dy=y1-y2;
		}
		/*if(abs(dx)>abs(dy))
		{
			t=y;
			y=x;
			x=t;
			t=dx;
			dx=dy;
			dy=t;
		}*/

		/*if(dy<0)
		{
			yinc=-1;
			dy=-dy;
		}*/

		if(abs(dx)>=abs(dy))
		{
			f=1;
		}
		else
		{
			f=0;
		}
		p=2*dy-dx;
		if(f==1)
		{
		while(x<=xend)
		{
			if(p<=0)
			{
				p+=2*dy;
				setpixel(x,y);
			}
			else
			{
				p+=(2*dy-2*dx);
				y+=yinc;
				setpixel(x,y);
			}
			x++;
		}
		}

		if(f==0)
		{
			while(y<=yend)
		{
			if(p<=0)
			{
				p+=2*dy;
				x+=xinc;
				setpixel(x,y);
			}
			else
			{
				p+=(2*dy-2*dx);
				//x+=xinc;
				setpixel(x,y);
			}
			y++;
		}
		}
		_getch();
	}
};
void init()
{
	glClearColor(1,1,1,0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-800,800,-800,800);
}

void choice()
{
	line l;
	int ch;
	GLint i;
	glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
	glPointSize(2+.0);
	glColor3f(0.0,0.0,0.0);
	for(i=-800;i<=800;i++)
	{
		setpixel(i,0);
		setpixel(0,i);
	}
	do
	{
		system("cls");
		cout<<"\n\t1)DDA";
		cout<<"\n\t2)Bresenhem's";
		cout<<"\n\t3)Exit";
		cout<<"\n\tEnter your choice :- ";
		cin>>ch;
		switch(ch)
		{
		case 1:glClear(GL_COLOR_BUFFER_BIT);
			glColor3f(0.0,0.0,0.0);
			for(i=-800;i<=800;i++)
			{
				setpixel(i,0);
				setpixel(0,i);
			}
			glColor3f(1.0,0.0,0.0);
			l.linedda();
			break;
		case 2:glClear(GL_COLOR_BUFFER_BIT);
			glColor3f(0.0,0.0,0.0);
			for(i=-800;i<=800;i++)
			{
				setpixel(i,0);
				setpixel(0,i);
			}
			glColor3f(1.0,0.0,0.0);
			l.bres();
			break;
		case 3:break;
		default:cout<<"Wtong choice entered!!!!!!";
		}
	}while(ch!=3);
	exit(0);
}
void main(int argc,char **argv)
{
	glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(500,200);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Line algorithms");
    init();
    glutDisplayFunc(choice);
    glutMainLoop();
}