

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <glut.h> 
#include <windows.h>
#include <math.h>
//#include <Gl.h>
//#include <Glu.h>


int SCREEN_HEIGHT = 480;
// Keep track of times clicked, on 3 clicks draw.
int NUMPOINTS = 0;

class Point 
{
public:
	float x, y, z;
	void setxy(float x2, float y2) { x = x2; y = y2; }
	void operator=(const Point &rPoint) 
	{
		x = rPoint.x;
		y = rPoint.y;
		z = rPoint.z;
	}
};

Point abc[20];

void myInit() 
{
	glClearColor(0.0,0.0,1.0,0.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(4.0);
    gluOrtho2D(0.0,640.0,0.0,480.0);

}

void drawDot(int x, int y) 
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
    glEnd();
    glFlush();
}

void drawLine(Point p1, Point p2) 
{
	glBegin(GL_LINES);
	glVertex3f(p1.x, p1.y, p1.z);
	glVertex3f(p2.x, p2.y, p2.z);
    glEnd();
    glFlush();
}

Point drawBezier(Point A, Point B, Point C, Point D, double t) 
{
	Point P;
    P.x = pow((1 - t), 3) * A.x + 3 * t * pow((1 -t), 2) * B.x + 3 * (1-t) * pow(t, 2)* C.x + pow (t, 3)* D.x;
    P.y = pow((1 - t), 3) * A.y + 3 * t * pow((1 -t), 2) * B.y + 3 * (1-t) * pow(t, 2)* C.y + pow (t, 3)* D.y;
    P.z = pow((1 - t), 3) * A.z + 3 * t * pow((1 -t), 2) * B.z + 3 * (1-t) * pow(t, 2)* C.z + pow (t, 3)* D.z;
	return P;
}
Point binomial(int n,double t);

void key(unsigned char key,int x,int y)
{
	if(key=='c')
	{
		NUMPOINTS=0;
		glClear(GL_COLOR_BUFFER_BIT);
		glutPostRedisplay();
	}
	else if(key==13)
	{
		Point POld=abc[0];
		int i=NUMPOINTS;
		while(--i)
		{
			glColor3f(1.0,1.0,1.0);
			drawLine(abc[i-1], abc[i]);
		}
		for(double t = 0.0;t <= 1.0; t += 0.1) 
		{
			Point p=binomial(NUMPOINTS-1,t);
			drawLine(POld, p);
			Sleep(200);
			POld = p;
		}
		glColor3f(1.0,0.0,0.0);
		NUMPOINTS = 0;
	}
}

int fact(int n)
{
	int i,s=1;
	if(n>1)
		s=n*fact(n-1);
	else
		return 1;
	return s;
}
int mul(int n,int j)
{
	int s=1,i=0;
	while(i<j)
	{
		s=s*n;
		n--;
		i++;
	}
	return s;
}

Point binomial(int n,double t)
{
	int j=0,k=NUMPOINTS;
	float i;
	Point p;
	p.x=p.y=p.z=0;
		while(j<=k)
		{
			i=mul(k-1,j)/fact(j);
			p.x=p.x+(i*abc[j].x*pow((1-t),n)*pow(t,j));
			p.y=p.y+(i*abc[j].y*pow((1-t),n)*pow(t,j));
			p.z=p.z+(i*abc[j].z*pow((1-t),n)*pow(t,j));
			j++;
			n--;
		}
		return p;
}

void myMouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{      
		abc[NUMPOINTS].setxy((float)x,(float)(SCREEN_HEIGHT - y));
		NUMPOINTS++;
		drawDot(x, SCREEN_HEIGHT - y);	
	}
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

int main(int argc, char *argv[]) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Bezier Curve");
	glutMouseFunc(myMouse);
	//glutDisplayFunc(myDisplay);
	glutKeyboardFunc(key);
	myInit();
	glutMainLoop();
	return 0;
}