#include<windows.h>
#include<iostream>
using namespace std;
#include<glut.h>

int a=0;
void init()
{
	glClearColor(0.3,0.3,0.0,0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(-2.0, 2.0,-2.0,2.0,-2.0,2.0);
	glPointSize(100.0);
	glLineWidth(90.0);
	glColor3f(0.0,1.0,0.0);
}

void processoption(int option)
{
	a=option;
	glClear(GL_COLOR_BUFFER_BIT);
	switch(option)
	{
	case 1:
		init();
		glutWireCube(2);
		break;
	case 2:
		glutWireSphere(2,4,10);
		break;
	case 3:
		glutWireCone(1,2,3,4);	
		break;
	case 4:
		glutWireTorus(0.7,1.3,8,8);
		break;
	case 5:
		glutWireOctahedron ();
		break;
	case 6:
		glutWireDodecahedron();
		break;
	case 7:
		glutWireIcosahedron ();
		break;
	case 8:
		glutWireTeapot (1.1);
		break;
	case 9:exit(0);
	}
	glFlush();
}

void MainMenu()
{
	int menu,menu1,menu2,menu3,menu4;
	menu=glutCreateMenu(processoption);
	glutSetMenu(menu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddMenuEntry("Cube",1);
	glutAddMenuEntry("Sphere",2);
	glutAddMenuEntry("Cone",3);
	glutAddMenuEntry("Torus",4);
	glutAddMenuEntry("Octahedron",5);
	glutAddMenuEntry("Dodecahedron",6);
	glutAddMenuEntry("Icosahedron",7);
	glutAddMenuEntry("Teapot",8);
	glutAddMenuEntry("Exit",9);
}

void display()
{
	MainMenu();
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}


void motion(int x, int y)
{
	x=x-500;
	y=500-y;
	glClear(GL_COLOR_BUFFER_BIT);
	switch(a)
	{
	case 1:
			glutWireCube(2);
			glRotatef(1,x, y, y);
			break;
	case 2:
			glutWireSphere(2,400,10);
			glRotatef(1,x, y, 0);
			break;
	case 3:
			glutWireCone(1,2,5,4);						
			glRotatef(1,x, y, 0);
			break;
	case 4:
			glutWireTorus(0.7,1.3,8,8);
			glRotatef(1,x, y, 0);
			break;
	case 5:
			glutWireOctahedron ();
			glRotatef(1,x, y, 0);
			break;
	case 6:
			glutWireDodecahedron ();
			glRotatef(1,x, y, 0);
			break;
	case 7:
			glutWireIcosahedron ();
			glRotatef(1,x, y, 0);
			break;
	case 8:
			glutWireTeapot (1.1);
			glRotatef(1,x, y, 0);
			break;
	}
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(65,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("Project");
	init();
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);	
	glutDisplayFunc(display);
	glutMotionFunc(motion);
	glutMainLoop();
}