#include<glut.h>//Include the GLUT functions

void init()
{
    glClearColor(0,0,0,0);//Define our background color
    gluOrtho2D(-5,5,-5,5);//(NEW)  Define our viewing area
}
/*void display()
{
    glClear(GL_COLOR_BUFFER_BIT);//Clear the screen

    glColor3f(1,0,0);//Change the object color to red

    glBegin(GL_TRIANGLES);//Start drawing a triangle
    glVertex2f(3,-4);//draw our first coordinate
    glVertex2f(3.5,-3);//Our second coordinate
    glVertex2f(4,-4);//Our last coordinate
    glEnd();//Stop drawing triangles


    glColor3f(0,1,0);//Change the object colors to green

    glBegin(GL_QUADS);//Start drawing quads
    glVertex2f(-4,-4);//first coordinate
    glVertex2f(-4,-2);//second coordinate

    glColor3f(0,0,1);//Change the color to blue halfway through to create a neat color effect

    glVertex2f(-2,-2);//third coordinate (now blue)
    glVertex2f(-2,-4);//last coordinate
    glEnd();//Stop drawing quads

    glColor3f(1,0,0);//Change color to red
    glBegin(GL_POLYGON);//Start drawing a polygon
    glVertex2f(-2,2);//first vertex
    glColor3f(0,1,0);//Change color to green
    glVertex2f(-1,3);//second vertex
    glColor3f(0,0,1);//Change color to blue
    glVertex2f(0,2);//third vertex
    glColor3f(1,0,1);//Change color to purple
    glVertex2f(-0.5,0);//fourth vertex
    glColor3f(1,1,0);//Change color to yellow
    glVertex2f(-1.5,0);//last vertex
    glEnd();//Stop drawing our polygon

	//void glutWireCube ( 2 );
    glFlush();//Draw everything to the screen
   // glutPostRedisplay();//Start drawing again
}*/
void main(int argc, char ** argv)
{
    glutInit(&argc, argv);//Initialize GLUT
    glutInitWindowSize(800,600);//define the window size
    glutInitWindowPosition(10,50);//Position the window
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);//Define the drawing mode
    glutCreateWindow("Polygons");//Create our window
    init();//initialize our variables
    //glutDisplayFunc(display);//tell Glut what our display function is
    glutMainLoop();//Keep the program running
}

