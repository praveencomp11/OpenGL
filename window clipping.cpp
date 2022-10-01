#include<iostream>
#include<glut.h>

using namespace std;
#define width  640
#define height 480

#define MAX 50

bool mousedown=false;
bool windowdrawn=false;
bool inputwindow=false;
bool inputlines=false;

int total_lines=0;
int xStart,yStart,xEnd,yEnd,n=0;
int flag1=0,flag2=0,point_no=0,click1=0,click2=0;

typedef class lines
{
	public:
			int     x,y;
			int     outcode[4];
}L;
L line[MAX];
typedef class window
{
	public:
			int xc,yc;
}W;
W win[4];
class line_clipping:public lines,public window
{
	private:
			int edge_count;
			L edpt[MAX],edpt1[MAX];
	public:
			void input_lines();
			void draw_clipping_window();
			void cohen_suth(L ed1,L ed2);
			int  region_test(L ed,L ed1);
			L    outcode(L ed1);
}LC;
void line_clipping::input_lines()
{
		glBegin(GL_LINES);
		glVertex3f(xStart,yStart,0);
		glVertex3f(xEnd,yEnd,0);
		glEnd();
}
void line_clipping::draw_clipping_window()
{
		glBegin(GL_LINES);
		glVertex3f(xStart,yStart,0);
		glVertex3f(xStart,yEnd,0);
		
		glVertex3f(xStart,yEnd,0);
		glVertex3f(xEnd,yEnd,0);
		
		glVertex3f(xEnd,yEnd,0);
		glVertex3f(xEnd,yStart,0);

		glVertex3f(xEnd,yStart,0);
		glVertex3f(xStart,yStart,0);
	    glEnd();
		
		
		win[0].xc=xEnd;	        win[0].yc=yStart;				//clipping windows coordinates saved in win object
		win[1].xc=win[2].xc;	win[1].yc=win[0].yc;
		win[2].xc=xStart;	    win[2].yc=yEnd;
		win[3].xc=win[0].xc;    win[3].yc=win[2].yc;

		//cout<<win[0].xc<<","<<win[0].yc<<endl;				//clipping windows coordinates saved in win object
		//cout<<win[2].xc<<","<<win[2].yc<<endl;
}
void line_clipping::cohen_suth(L ed1,L ed2)
{
		L edon,edtw;
		int region,flag,interx,intery,i;
		edon=outcode(ed1);
		edtw=outcode(ed2);

		region=region_test(edon,edtw);
		glColor3f(1,0,0);
		glLineWidth(2);
		switch(region)
		{
		case 0:				
			   //totally inside
			   glBegin(GL_LINES);
			   glVertex3f(edon.x,edon.y,0);
			   glVertex3f(edtw.x,edtw.y,0);
			   glEnd();
			   break;
		case 1:return;											//totally outside
		case 2:next_inter:
				for(i=3;i>=0;i--)
				{
					if(edon.outcode[i]==0&&edtw.outcode[i]==0)
						continue;
					if(edtw.outcode[i]==1)
						goto new_code1;
					else
						goto new_code2;
				}
				goto drawline;
				new_code1:
							switch(i)
							{
							case 2: interx=win[0].xc;
								intery=(((win[0].xc-edon.x)*(edon.y-edtw.y))/(edon.x-edtw.x))+edon.y;
								break;
							case 3: interx=win[1].xc;
								intery=(((win[1].xc-edon.x)*(edon.y-edtw.y))/(edon.x-edtw.x))+edon.y;
								break;
							case 0: intery=win[1].yc;
								interx=(((win[1].yc-edon.y)*(edon.x-edtw.x))/(edon.y-edtw.y))+edon.x;
								break;
							case 1: intery=win[3].yc;
								interx=(((win[3].yc-edon.y)*(edon.x-edtw.x))/(edon.y-edtw.y))+edon.x;
								break;
							}
							edtw.x=interx;
							edtw.y=intery;
							edtw=outcode(edtw);
							goto next_inter;
				new_code2:switch(i)
							{
							case 2: interx=win[0].xc;
								intery=(((win[0].xc-edtw.x)*(edtw.y-edon.y))/(edtw.x-edon.x))+edtw.y;
								break;
							case 3: interx=win[1].xc;
								intery=(((win[1].xc-edtw.x)*(edtw.y-edon.y))/(edtw.x-edon.x))+edtw.y;
								break;
							case 0: intery=win[1].yc;
								interx=(((win[1].yc-edtw.y)*(edtw.x-edon.x))/(edtw.y-edon.y))+edtw.x;
								break;
							case 1: intery=win[3].yc;
								interx=(((win[3].yc-edtw.y)*(edtw.x-edon.x))/(edtw.y-edon.y))+edtw.x;
								break;
							}
						    edon.x=interx;
							edon.y=intery;
							edon=outcode(edon);
							goto next_inter;
		}
drawline:
		glColor3f(1,0,0);
		glBegin(GL_LINES);
		glVertex3f(edon.x,edon.y,0);
	    glVertex3f(edtw.x,edtw.y,0);
		glEnd();
//glutPostRedisplay();
}
L line_clipping::outcode(L edc)
{
	if(edc.x<win[1].xc)				//left
		edc.outcode[3]=1;    
	else
		edc.outcode[3]=0;

	if(edc.x>win[0].xc)             //right
		edc.outcode[2]=1;
	else
		edc.outcode[2]=0;

	if(edc.y>win[2].yc)            //below
		edc.outcode[1]=1;
	else
		edc.outcode[1]=0;

	if(edc.y<win[0].yc)			   //top
		edc.outcode[0]=1;
	else
		edc.outcode[0]=0;

return edc;
}
int line_clipping::region_test(L ed,L ed1)
{
	int j;
	int temp=0;
	L Etemp;
	for(j=0;j<4;j++)
	{
		if(ed.outcode[j]==ed1.outcode[j])
			if(ed.outcode[j]==0)
				temp++;
	}
	if(temp==4)
		return 0;
	else
	{
		for(j=0;j<4;j++)
		{
			if(ed.outcode[j]==ed1.outcode[j]&&ed.outcode[j]==1&&ed1.outcode[j]==1)
				Etemp.outcode[j]=1;
			else
				Etemp.outcode[j]=0;
		}
		temp=0;
		for(j=0;j<4;j++)
		{
			if(Etemp.outcode[j]==0)
				temp++;
		}
	}
	if(temp<4)
			return 1;
	else
			return 2;
}
//========================================================================================================
void UpdateWindow()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glutPostRedisplay();
}
void InitGlut(int w,int h)
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0,w,h,0,-1,1);

}
void renderscene()
{
	if(!windowdrawn&&xEnd!=0)
	{
		LC.draw_clipping_window();
		if(flag1&&!mousedown)
		{
		windowdrawn=true;
		inputlines=true;
		cout<<"\nClipping Window Drawn....";
		cout<<"\nNow Draw Lines..";
		cout<<"\nPress at any point of time 'c' to clipp the lines";
		}
	}
glFlush();
}
void handlemouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:if(state==GLUT_DOWN)
							  {
								  if(!windowdrawn)
									{
										//y=height-y;
										mousedown=true;
										xStart=x;
										yStart=y;

										flag1=true;									//flag1 is set after first click this means that user is actually entering window
									}
								}
						  else
							  mousedown=false;
						  break;
	case GLUT_RIGHT_BUTTON:if(state==GLUT_DOWN&&inputlines)
								{

									line[point_no].x=x;
									line[point_no].y=y;
									/*glPointSize(4);
									glBegin(GL_POINTS);
									glVertex3f(line[point_no].x,line[point_no].y,0);
									glEnd();*/
									if(point_no%2!=0)
									{
										glColor3f(0.5,0.5,0.5);
										glBegin(GL_LINES);
										glVertex3f(line[point_no-1].x,line[point_no-1].y,0);
										glVertex3f(line[point_no].x,line[point_no].y,0);
										glEnd();
										total_lines++;
									}
									point_no++;
								}
	}
	glutPostRedisplay();
}
void mousemove(int x,int y)
{
	//y=height-y;
	if(mousedown)
	{
		xEnd=x;
		yEnd=y;
		UpdateWindow();
	}
}
void handlekeyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
	case 'c':
	case 'C':for(int i=0;i<2*total_lines;i+=2)
				 LC.cohen_suth(line[i],line[i+1]);
		break;
	}
	glutPostRedisplay();
}
void main(int argc,char **argv)
{
	cout<<"\n\n\n\t\t\tLINE CLIPPING";
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(width,height);
	glutCreateWindow("LINE CLIPPING-COHEN SUTHERLAND ALGORITHM");
	InitGlut(width,height);
	glutDisplayFunc(renderscene);
	glutMouseFunc(handlemouse);
	glutKeyboardFunc(handlekeyboard);
	glutMotionFunc(mousemove);
	glutMainLoop();
}