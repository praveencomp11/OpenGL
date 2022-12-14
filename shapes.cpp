#include "glut.h"

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);	// Set display window colour to white

	glMatrixMode(GL_PROJECTION);		// Set projection parameters
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	// Clear display window
	
	//Set colour to black
	glColor3f(1.0, 0.0, 1.0);
	//Adjust the point size
	glPointSize(10.0);

	// Draw a couple of points
	glBegin(GL_POINTS);
		glVertex2i(60, 360);
		glVertex2i(140, 360);
	glEnd();

	//Set colour to green
	glColor3f(0.0, 1.0, 0.0);

	// Draw a filled triangle
	glBegin(GL_TRIANGLES);
		glVertex2i(20, 250);
		glVertex2i(100, 380);
		glVertex2i(180, 250);
	glEnd();

	//Set colour to red
	glColor3f(1.0, 0.0, 0.0);

	// Draw a filled quadrilateral
	glBegin(GL_QUADS);
		glVertex2i(200, 250);
		glVertex2i(200, 380);
		glVertex2i(380, 380);
		glVertex2i(380, 250);
	glEnd();
	
	//Set colour to blue
	glColor3f(0.0, 0.0, 1.0);

	// Draw a filled octagon
	glBegin(GL_POLYGON);
		glVertex2i(90, 30);
		glVertex2i(30, 90);
		glVertex2i(30, 174);
		glVertex2i(90, 234);
		glVertex2i(174, 234);
		glVertex2i(234, 174);
		glVertex2i(234, 90);
		glVertex2i(174, 30);
	glEnd();

	//Set colour to black
	glColor3f(0.0, 0.0, 0.0);

	// Draw an outlined triangle
	glBegin(GL_LINE_LOOP);
		glVertex2i(260, 30);
		glVertex2i(320, 230);
		glVertex2i(380, 30);
	glEnd();

	glFlush();	// Process all OpenGL routines
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);						// Initalise GLUT
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	// Set display mode
	
	glutInitWindowPosition(200, 200);				// Set window position
	glutInitWindowSize(400, 400);					// Set window size
	glutCreateWindow("OpenGL Objects");	// Create display window

	init();							// Execute initialisation procedure
	glutDisplayFunc(drawShapes);		// Send graphics to display window
	glutMainLoop();					// Display everything and wait
	
	return 0;
}
