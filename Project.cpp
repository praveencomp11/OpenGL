#include<windows.h>
#include<iostream>
using namespace std;
#include<glut.h>

int a=0,b=6,c=6,d=6,e=6,f=6,g=6;
void init()
{
	glClearColor(0.0,0.3,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0,-2.0,2.0,-2.0,2.0);
	glPointSize(1.0);
	glLineWidth(9.0);
	glColor3f(0.0,1.0,0.0);
}

void cube3D()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	glutWireCube(2);
	glFlush();
}

void cubetop()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0,0.0,0.0,0.0,-5.0, 0.0, 5.0, 0.0);
	glutWireCube(2);
	glFlush();
}

void cubefront()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0,0.0, 0.0,-5.0, 0.0,0.0, 0.0, 5.0);
	glutWireCube(2);
	glFlush();
}

void cubeside()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0, 0.0, -5.0, 0.0, 0.0, 0.0,5.0, 0.0);
	glutWireCube(2);
	glFlush();
}

void cone3D()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	cout<<"\nEnter the no. of slices\t\t";
	cin>>b;
	cout<<"\nEnter the no. of stacks\t\t";
	cin>>c;
	glutWireCone(1,1.7,b,c);
	glFlush();
}

void conetop()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0,0.0, 0.0,-5.0, 0.0,0.0, 0.0, 5.0);
	glutWireCone(1,1.7,b,c);	
	glFlush();
}

void conefront()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//init();
	gluLookAt (0.0, 0.0,0.0, 0.0,0.0,-5.0, 0.0, 5.0, 0.0);
	glutWireCone(1,1.7,b,c);	
	glFlush();
}

void coneside()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0, 0.0, -5.0, 0.0, 0.0, 0.0,5.0, 0.0);
	glutWireCone(1,1.7,b,c);	
	glFlush();
}

void sphere3D()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	cout<<"\nEnter the no. of slices\t\t";
	cin>>d;
	cout<<"\nEnter the no. of stacks\t\t";
	cin>>e;
	glutWireSphere(2,d,e);
	glFlush();
}

void spheretop()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0,0.0, 0.0,-5.0, 0.0,0.0, 0.0, -5.0);
	glutWireSphere(2,d,e);
	glFlush();
}

void spherefront()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0,0.0, 0.0,0.0,-5.0, 0.0, 5.0, 0.0);
	glutWireSphere(2,d,e);
	glFlush();
}

void sphereside()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0, 0.0, -5.0, 0.0, 0.0, 0.0,5.0, 0.0);
	glutWireSphere(2,d,e);
	glFlush();
}

void torus3D()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	cout<<"\nEnter the no. of slices\t\t";
	cin>>f;
	cout<<"\nEnter the no. of stacks\t\t";
	cin>>g;
	glutWireTorus(0.7,1.3,f,g);
	glFlush();
}

void torustop()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0,0.0, 0.0,-5.0,0.0,0.0, 0.0, -5.0);
	glutWireTorus(0.7,1.3,f,g);
	glFlush();
}

void torusfront()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0,0.0, 0.0,0.0,-5.0, 0.0, 5.0, 0.0);
	glutWireTorus(0.7,1.3,f,g);
	glFlush();
}

void torusside()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0,0.0, -5.0,0.0, 0.0,0.0, 5.0, 0.0);
	glutWireTorus(0.7,1.3,f,g);
	glFlush();
}

void octa3D()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	glutWireOctahedron ();
	glFlush();
}

void octatop()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0,0.0, 0.0,-5.0,0.0, 0.0, 0.0, -5.0);
	glutWireOctahedron ();
	glFlush();
}

void octafront()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0,0.0, 0.0,0.0, -5.0,0.0, 5.0, 0.0);
	glutWireOctahedron ();
	glFlush();
}

void octaside()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0, 0.0, -5.0, 0.0, 0.0, 0.0,5.0, 0.0);
	glutWireOctahedron ();
	glFlush();
}

void Dodeca3D()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	glutWireDodecahedron();
	glFlush();
}

void Dodecatop()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0,0.0, 0.0,-5.0,0.0, 0.0, 0.0, -5.0);
	glutWireDodecahedron();
	glFlush();
}

void Dodecafront()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0,0.0, 0.0,0.0,-5.0, 0.0, 5.0, 0.0);
	glutWireDodecahedron();
	glFlush();
}

void Dodecaside()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0, 0.0, -5.0, 0.0, 0.0, 0.0,5.0, 0.0);
	glutWireDodecahedron();
	glFlush();
}

void Icosa3D()
{	
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	glutWireIcosahedron ();
	glFlush();
}

void Icosatop()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0,0.0, 0.0,-5.0, 0.0,0.0, 0.0, -5.0);
	glutWireIcosahedron ();
	glFlush();
}

void Icosafront()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0,0.0, 0.0,0.0,-5.0, 0.0, 5.0, 0.0);
	glutWireIcosahedron ();
	glFlush();
}

void Icosaside()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0, 0.0, -5.0, 0.0, 0.0, 0.0,5.0, 0.0);
	glutWireIcosahedron ();
	glFlush();
}

void teapot3D()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	glutWireTeapot (1.1);
	glFlush();
}

void teapottop()
{	
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0,0.0, 0.0,-5.0, 0.0,0.0, 0.0, -5.0);
	glutWireTeapot (1.1);
	glFlush();
}

void teapotfront()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0,0.0, 0.0,0.0,-5.0, 0.0, 5.0, 0.0);
	glutWireTeapot (1.1);
	glFlush();
}

void teapotside()
{
	glClear(GL_COLOR_BUFFER_BIT);
	init();
	gluLookAt (0.0, 0.0, 0.0, -5.0, 0.0, 0.0, 0.0,5.0, 0.0);
	glutWireTeapot (1.1);
	glFlush();
}

void processcube(int option)
{
	a=option;
	switch(option)
	{
	case 0:cube3D();
		break;
	case 1:cubetop();
		break;
	case 2:cubefront();
		break;
	case 3:cubeside();
		break;
	
	}
}

void processcone(int option)
{
	a=option;
	switch(option)
	{
	case 4:cone3D();
		break;
	case 5:conetop();
			break;
	case 6:conefront();
			break;
	case 7:coneside();
		break;
	}
}

void processsphere(int option)
{
	a=option;
	switch(option)
	{
	case 8:sphere3D();
		break;
	case 9:spheretop();
		break;
	case 10:spherefront();
		break;
	case 11:sphereside();
		break;
	}
}

void processtorus(int option)
{
	a=option;
	switch(option)
	{
	case 12:torus3D();
		break;
	case 13:torustop();
		break;
	case 14:torusfront();
		break;
	case 15:torusside();
		break;
	}
}

void processoctahedron(int option)
{
	a=option;
	switch(option)
	{
	case 16:octa3D();
		break;
	case 17:octatop();
		break;
	case 18:octafront();
		break;
	case 19:octaside();
		break;
	}
}

void processdodecahedron(int option)
{
	a=option;
	switch(option)
	{
	case 20:Dodeca3D();
		break;
	case 21:Dodecatop();
		break;
	case 22:Dodecafront();
		break;
	case 23:Dodecaside();
		break;
	}
}

void processicosahedron(int option)
{
	a=option;
	switch(option)
	{
	case 24:Icosa3D();
		break;
	case 25:Icosatop();
		break;
	case 26:Icosafront();
		break;
	case 27:Icosaside();
		break;
	}
}

void processteapot(int option)
{
	a=option;
	switch(option)
	{
	case 28:teapot3D();
		break;
	case 39:teapottop();
		break;
	case 30:teapotfront();
		break;
	case 31:teapotside();
		break;
	}
}

void processfig(int option)
{
	exit(0);
}

void MainMenu()
{
	int menu,menu1,menu2,menu3,menu4,menu5,menu6,menu7,menu8;
	menu=glutCreateMenu(processfig);
	menu1=glutCreateMenu(processcube);
	menu2=glutCreateMenu(processcone);
	menu3=glutCreateMenu(processsphere);
	menu4=glutCreateMenu(processtorus);
	menu5=glutCreateMenu(processoctahedron);
	menu6=glutCreateMenu(processdodecahedron);
	menu7=glutCreateMenu(processicosahedron);
	menu8=glutCreateMenu(processteapot);
	
	glutSetMenu(menu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddSubMenu("Cube",menu1);
	glutAddSubMenu("Cone",menu2);
	glutAddSubMenu("Sphere",menu3);
	glutAddSubMenu("Trous",menu4);
	glutAddSubMenu("Octahedron",menu5);
	glutAddSubMenu("Dodecahedron",menu6);
	glutAddSubMenu("Icosahedron",menu7);
	glutAddSubMenu("Teapot",menu8);
	glutAddMenuEntry("Exit",0);
	glutSetMenu(menu1);
	glutAddMenuEntry("3D Figure",0);
	glutAddMenuEntry("Top view",1);
	glutAddMenuEntry("Front view",2);
	glutAddMenuEntry("Side view",3);
	
	glutSetMenu(menu2);
	glutAddMenuEntry("3D Figure",4);
	glutAddMenuEntry("Top view",5);
	glutAddMenuEntry("Front view",6);
	glutAddMenuEntry("Side view",7);

	glutSetMenu(menu3);
	glutAddMenuEntry("3D Figure",8);
	glutAddMenuEntry("Top view",9);
	glutAddMenuEntry("Front view",10);
	glutAddMenuEntry("Side view",11);

	glutSetMenu(menu4);
	glutAddMenuEntry("3D Figure",12);
	glutAddMenuEntry("Top view",13);
	glutAddMenuEntry("Front view",14);
	glutAddMenuEntry("Side view",15);

	glutSetMenu(menu5);
	glutAddMenuEntry("3D Figure",16);
	glutAddMenuEntry("Top view",17);
	glutAddMenuEntry("Front view",18);
	glutAddMenuEntry("Side view",19);
	
	glutSetMenu(menu6);
	glutAddMenuEntry("3D Figure",20);
	glutAddMenuEntry("Top view",21);
	glutAddMenuEntry("Front view",22);
	glutAddMenuEntry("Side view",23);
	
	glutSetMenu(menu7);
	glutAddMenuEntry("3D Figure",24);
	glutAddMenuEntry("Top view",25);
	glutAddMenuEntry("Front view",26);
	glutAddMenuEntry("Side view",27);
	
	glutSetMenu(menu8);
	glutAddMenuEntry("3D Figure",28);
	glutAddMenuEntry("Top view",39);
	glutAddMenuEntry("Front view",30);
	glutAddMenuEntry("Side view",31);	
}

void text()
{
	glColor3f(1.0, 1.0, 1.0); 
	glRasterPos3f(-0.5, 0, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'D');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'O');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'B');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'J');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'C');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'T');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'S');	
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	text();
	MainMenu();
	glFlush();
}



void motion(int x, int y)
{
	x=x-500;
	y=500-y;
	glClear(GL_COLOR_BUFFER_BIT);
	switch(a)
	{
	case 0:
			glutWireCube(2);
			glRotatef(1,y,x,0);
			break;
	case 4:
			glutWireCone(1,2,b,c);		
			glRotatef(1,x, y, 0);
			break;
	case 8:
			glutWireSphere(2,d,e);					
			glRotatef(1,x, y, 0);
			break;
	case 12:
			glutWireTorus(0.7,1.3,f,g);
			glRotatef(1,x, y, 0);
			break;
	case 16:
			glutWireOctahedron ();
			glRotatef(1,x, y, 0);
			break;
	case 20:
			glutWireDodecahedron ();
			glRotatef(1,x, y, 0);
			break;
	case 24:
			glutWireIcosahedron ();
			glRotatef(1,x, y, 0);
			break;
	case 28:
			glutSolidTeapot (1.1);
			glRotatef(1,x, y, 0);
			break;
	}
	glFlush();
}

void resize(int w, int h)
{
	init();
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glutPostRedisplay();
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
	glutReshapeFunc (resize);
	glutMotionFunc(motion);
	glutMainLoop();
}