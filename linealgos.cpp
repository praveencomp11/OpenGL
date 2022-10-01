#include<iostream>
#include <glut.h>
#include <math.h>
using namespace std;
#define W 500
#define H 500

void initialize()
{
	glClearColor( 1.0, 1.0, 1.0, 0.0);//sets background color 
	glMatrixMode(GL_MODELVIEW);//viewing angle
	glLoadIdentity();//to load identity matrix
	gluOrtho2D(-W, W,-H,H);//camera properties
}

void setPixel(GLint,GLint);

class line
{	public:
	int x0,x1,y0,y1;


void LineWithbres()
{	cout<<"Enter the startring coordinates:";
	cin>>x0>>y0;
	cout<<"Enter the ending coordinates:";
	cin>>x1>>y1;
	GLint dx,dy,steps,i=0,x,y,g;
	if(x0>x1&&y0>y1)
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
if(x0>x1&&y0<y1)
{

	if(dx>=dy)
	{	g=2*dy-dx;
		steps=dx;
		while(i<=steps)
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
		steps=dy;
	while(i<=steps)
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

else if(x0<x1&&y0>y1)
{
	if(dx>=dy)
	{	g=dx-2*dy;
		steps=dx;
		while(i<=steps)
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
		steps=dy;
	while(i<=steps)
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
{if(dx>=dy)
	{	g=2*dy-dx;
		steps=dx;
		while(i<=steps)
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
		steps=dy;
	while(i<=steps)
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
{cout<<"Enter the startring coordinates:";
	cin>>x0>>y0;
	cout<<"Enter the ending coordinates:";
	cin>>x1>>y1;
    GLint dy = y1 - y0;
    GLint dx = x1 - x0;
    GLint steps,i;
    GLfloat xinc,yinc,x=x0,y=y0;
    if( abs(dx) >= abs(dy)){
        steps=abs(dx);
    }else{
          steps=abs(dy);
    }
    xinc=(float) dx/ (float) steps;
    yinc=(float) dy/ (float) steps;
    setPixel(x,y);
    for(i=0;i<steps;i++){
         x+=xinc;
         y+=yinc;
         setPixel(x,y);
    }
    
}


};
void setPixel(GLint x, GLint y)
{	
	glColor3f(0, 0, 1);//color of what we draw
	glBegin(GL_POINTS);//inbuilt functions
	glVertex2f(x,y);//to pass coordinates
	glEnd();
	glFlush();
}

    


void choice()
{
	line l;
	int ch,ch1=1,i;
	 glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
	glColor3f(1.0,0.0,0.0);
	glPointSize(2.0);
	for(i=-500;i<500;i++)
	{
		setPixel(i,0);
		setPixel(0,i);
	}
	while(1)
	{	if(ch1!=1)
		exit(0);
		cout<<"****Line Generation****\n1.Bresenhem's\n2.DDA\n3.Exit";
		cin>>ch;
		switch(ch)
		{
		case 1:
		glClear(GL_COLOR_BUFFER_BIT);
			for(i=-500;i<500;i++)
	{
		setPixel(i,0);
		setPixel(0,i);
	}
			l.LineWithbres();
		break;
		case 2:
			glClear(GL_COLOR_BUFFER_BIT);
			for(i=-500;i<500;i++)
	{
		setPixel(i,0);
		setPixel(0,i);
	}
			l.DDA();
		break;
		case 3:
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
	glutInitWindowPosition(500,300);
	glutInitWindowSize(W,H);
	glutCreateWindow("OpenGL line generation");
	initialize();
	glutDisplayFunc(choice);
	glutMainLoop();
	return(0);
}
