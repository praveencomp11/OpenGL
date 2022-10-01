#include<glut.h>
#include<stdio.h>
#include<iostream>


/*************************modifications********************************
member function:ddacircle(quite easy one.....rcostheta one)
				bresenham.
completed
***********************************************************************/
#define ESC 27
void main(int argc,char **argv);
void keyboard(unsigned char key,int x,int y);

using namespace std;
GLint xCenter,yCenter,raduis;
int kill;
class circle
{
private:
		GLint x,y;
public:
		circle()
		{
			x = 0;
			y = 0;
		}
		circle(GLint xc,GLint yc)
		{
			x=xc;
			y=yc;
		}

	void setCoordinates(GLint xCoordinateValue, GLint yCoordinateValue)
	{
		x = xCoordinateValue;
		y = yCoordinateValue;
	}
	GLint getx () const
	{
		return x;
	}
	GLint gety () const
	{
		return y;
	}
	void incrementx ()
	{
		x++;
	}
	void decrementy ()
	{
		y--;
	}

	friend void circlePlotPoints(GLint, GLint, circle); 
	//line drawing functions
	static void drawMyCircle1();
	static void drawMyCircle2();
	static void drawMyCircle3();

	static void circleMidPoint(GLint,GLint,GLint);
	static void circleDDA(GLint,GLint,GLint);
	static void circleBresenham(GLint,GLint,GLint);


}c;

void setPixel(GLint xCoordinate, GLint yCoordinate)
{
	glBegin(GL_POINTS);
	glVertex2i(xCoordinate, yCoordinate);
	glEnd();
	glFlush(); 
}
void circle::circleBresenham(GLint xc, GLint yc, GLint raduis)
{
	circle circlePoint;
	//initialize value for midpoint parameter
	GLint p = 3-(2*raduis);
	//set coordinates for top point of circle
	circlePoint.setCoordinates(0,raduis);
	//function prototype
	//plot the initial point in each quadrant
	circlePlotPoints(xc, yc, circlePoint);
	//calculate the next point and plot in each octant
	while(circlePoint.getx() < circlePoint.gety())
	{
		if(p<0)
			p += 4 * circlePoint.getx() + 6;
		else
		{
			p += 4* (circlePoint.getx () - circlePoint.gety ()) + 10;
			circlePoint.decrementy ();
		}
		circlePoint.incrementx();
		circlePlotPoints(xc, yc, circlePoint);
	}
}

void circle::circleMidPoint(GLint xc, GLint yc, GLint raduis)
{
	circle circlePoint;
	//initialize value for midpoint parameter
	GLint p = 1-raduis;
	//set coordinates for top point of circle
	circlePoint.setCoordinates(0,raduis);
	//function prototype
	//plot the initial point in each quadrant
	circlePlotPoints(xc, yc, circlePoint);
	//calculate the next point and plot in each octant
	while(circlePoint.getx() < circlePoint.gety())
	{
		circlePoint.incrementx();
		if(p<0)
			p += 2 * circlePoint.getx() + 1;
		else
		{
			circlePoint.decrementy ();
			p += 2 * (circlePoint.getx () - circlePoint.gety ()) + 1;
		}
		circlePlotPoints(xc, yc, circlePoint);
	}
}
void circle::circleDDA(GLint xc,GLint yc,GLint raduis)
{
	circle circPoint;
	circPoint.setCoordinates(raduis,0);

	GLfloat theta=0;
	for(;theta<=360.0;theta+=0.01)
	{
		circPoint.setCoordinates(raduis*cos(theta),raduis*sin(theta));
		setPixel(xc+circPoint.getx(),yc+circPoint.gety());
	}
}
void circlePlotPoints(GLint xc, GLint yc, circle circPoint)
{
	setPixel(xCenter,yCenter);
	setPixel(xc + circPoint.getx () , yc + circPoint.gety ());
	setPixel(xc - circPoint.getx () , yc + circPoint.gety ());
	setPixel(xc + circPoint.getx () , yc - circPoint.gety ());
	setPixel(xc - circPoint.getx () , yc - circPoint.gety ());
	setPixel(xc + circPoint.gety () , yc + circPoint.getx ());
	setPixel(xc - circPoint.gety () , yc + circPoint.getx ());
	setPixel(xc + circPoint.gety () , yc - circPoint.getx ());
	setPixel(xc - circPoint.gety () , yc - circPoint.getx ());
}
//Initialize OpenGL
void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0); //set display-window color to black
	glMatrixMode(GL_PROJECTION); //set projection parameters
	gluOrtho2D(0.0,500.0,0.0,500.0);
}
void circle::drawMyCircle1()
{
	glClear(GL_COLOR_BUFFER_BIT); //clear display-window
	glColor3f(1.0,0.5,0.0); //set pixel color to red
	glPointSize(1.0);
	circleMidPoint(xCenter, yCenter, raduis);
}

void circle::drawMyCircle2()
{
	glClear(GL_COLOR_BUFFER_BIT); //clear display-window
	glColor3f(1.0,0.5,0.0); //set pixel color to red
	glPointSize(1.0);
	circleDDA(xCenter, yCenter, raduis);
}
void circle::drawMyCircle3()
{
	glClear(GL_COLOR_BUFFER_BIT); //clear display-window
	glColor3f(1.0,0.5,0.0); //set pixel color to red
	glPointSize(1.0);
	circleBresenham(xCenter, yCenter, raduis);
}
void menu()
{
	int ans=1;
	cout<<"\n\t\t\t\tCIRCLES\n\n";

	cout<<"\nEnter the center of circle:";
	cin>>xCenter>>yCenter;
	cout<<"\nEnter the raduis of circle:";
	cin>>raduis;

	cout<<"\n1.MID-POINT CIRCLE";
	cout<<"\n2.DDA CIRCLE";
	cout<<"\n3.BRESENHAM CIRCLE";
	cout<<"\n4.EXIT";
	cout<<"\nALGORITHM TO FOLLOW:";
	cin>>ans;
	//glutCreateWindow("Circle Algorithm");
switch(ans)
{
case 1:	kill=glutCreateWindow("Circle Mid Point Algorithm");

		init(); //execute initialization procedure of OpenGL

		glutDisplayFunc(&circle::drawMyCircle1); //send graphics to display win
		break;
case 2:
		kill=glutCreateWindow("DDA Circle Algorithm");

		init(); //execute initialization procedure of OpenGL

		glutDisplayFunc(&circle::drawMyCircle2); //send graphics to display window
		break;
case 3:
		kill=glutCreateWindow("Bresenham Circle Algorithm");

		init(); //execute initialization procedure of OpenGL

		glutDisplayFunc(&circle::drawMyCircle3); //send graphics to display window
		break;
case 4:break;
default:
		break;
}
glutKeyboardFunc(keyboard);
glutMainLoop();
}
	
void keyboard(unsigned char key,int x,int y)
{
	glutDestroyWindow(kill);
		menu();
		if(key==ESC)
			exit(0);
}
void main(int argc, char**argv)
{
glutInit(&argc, argv); //initialize GLUT
glutInitWindowPosition(10,10); //set top-left display-window position
glutInitWindowSize(500,500); //set display-window width and height to 500
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set display mode
//glutCreateWindow("CREATE WINDOW");
menu();
glutKeyboardFunc(keyboard);
//glutMainLoop();
//Now display the window with a title
}
