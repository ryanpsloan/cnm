//Bounce.cpp
//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
//this to avoid the black console window
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

#include <iostream>
#include <iomanip>
#include <sstream>
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>		// Glut (Free-Glut on Windows)
#include "Forest.h"
#include "Tetrahedron.h"
#include "Cube.h"

using namespace std;
//else
extern GLboolean planeOn;
extern GLboolean axesOn;
extern GLboolean lightsOn;
extern GLboolean drawMode;
extern GLboolean toggleView;
extern GLint drawCount;

extern Tetrahedron tetra[];
extern Cube cube[];

extern GLint width, height;//used to keep track of w and h globally
extern GLint timeT, timebase;
extern GLfloat eyex, eyey, eyez;
extern GLfloat pos[];
extern GLint azimuth, elevation, radius;
extern GLint listCount;
extern GLint frame;

///////////////////////////////////////////////////////////
// Called to draw scene
void RenderScene(void)
{
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	CalculateEye();	
	gluLookAt(eyex, eyey, eyez, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	setPerspective();
	
	//toggle plane
	if(planeOn) {
			//Draw blue plane on xz axis		
			glColor3f(0.00f, 0.00f, 1.00f);
			glBegin(GL_POLYGON);
				glVertex3f(-100.0, 0.0, -100.0);
				glVertex3f(100.0, 0.0, -100.0);
				glVertex3f(100.0, 0.0, 100.0);
				glVertex3f(-100.0, 0.0, 100.0);
			glEnd();
	}

	//toggle axes
	if(axesOn) {
		//draw axes
		glLineWidth(1.5); 
		glBegin(GL_LINES);
		//x y z axis
		//x white
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(100.0, 0.0, 0.0);
			glVertex3f(-100.0, 0.0, 0.0);
		//y	white
			glVertex3f(0.0, 100.0, 0.0);
			glVertex3f(0.0, -100.0, 0.0);
		//z white
			glVertex3f(0.0, 0.0, 100.0);
			glVertex3f(0.0, 0.0, -100.0);
		glEnd();
	}

	if(drawMode)
	{
		for(int i = 0; i < drawCount; ++i)
		{
			tetra[i].DrawMe();
			cube[i].DrawMe();
		}
	}
	else
	{
		if(drawCount == 10)
		{
			glCallList(listCount);
		}
		else if (drawCount == 35)
		{
			glCallList(listCount + 1);
		}
		else if (drawCount == 100)
		{
			glCallList(listCount + 2);
		}	
	}
	
	// Flush drawing commands and swap
    glutSwapBuffers();
	
	frame++;
	timeT = glutGet(GLUT_ELAPSED_TIME);
	
	if(timeT - timebase > 1000)
	{
		double t = frame * 1000.0 / (timeT - timebase);
		stringstream ss;
		ss << setprecision(2) << fixed << showpoint;
		ss << "Ryan Sloan - SloanP4 FPS:" << t;
		if(drawMode)
			ss << " DirectDraw ";
		else
			ss << " CallListDraw ";
		timebase = timeT;
		frame = 0;
		glutSetWindowTitle(ss.str().c_str());
	}
	
	
}

///////////////////////////////////////////////////////////
// Called by GLUT library when idle (window not being
// resized or moved)
void TimerFunction(int value)
{
	// Redraw the scene with new coordinates
    glutPostRedisplay();
    glutTimerFunc(1,TimerFunction, 1);
}


///////////////////////////////////////////////////////////
// Setup the rendering state
void SetupRC(void)
{
	// Set clear color 
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glShadeModel(GL_FLAT);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
}


///////////////////////////////////////////////////////////
// Called by GLUT library when the window has chanaged size
void ChangeSize(int w, int h)
{
	width = w;
	height = h;
    //GLfloat aspectRatio;

    // Prevent a divide by zero
    if(h == 0)
        h = 1;
		
    // Set Viewport to window dimensions
  	glViewport(0, 0, w, h);
}		

void ChangeFunction(GLubyte key, GLint x, GLint y)
{
	if(key == 'f'){
		radius -= 3;
		if (radius <= 0)
		{
			radius  = 0;
		}
	}
	if(key == 'b'){
		radius += 3;
		if (radius >= 900)
		{
			radius = 900;
		}
	}
}	

void CalculateEye()
{
	GLfloat e = elevation * PI / 180.0f;
	GLfloat a = azimuth * PI / 180.0f;
	eyex = radius * cos(e);
	eyey = radius * sin(e);
	eyez = eyex * sin(a);
	eyex = eyex * cos(a);
	
}

void SpecialKeys(int key, int x, int y)
{
	if(key == GLUT_KEY_UP){
		elevation += 3;
		if(elevation >= 89)
		{
			elevation = 89;
		}
		
	}
	if(key == GLUT_KEY_DOWN){
		elevation -= 3;
		if(elevation <= -89)
		{
			elevation = -89;
		}
	}
	if(key == GLUT_KEY_LEFT){
		azimuth += 3;
		if(azimuth >= 359) {
			azimuth = 359;
		}
	}
	if(key == GLUT_KEY_RIGHT){
		azimuth -= 3;
		if(azimuth <= 1){
			azimuth = 1;
		}
	}
}

void SetupMenus()
{
	GLint drawingSubMenu = glutCreateMenu(MenuHandler);
	glutAddMenuEntry("Toggle Draw Mode", TOGGLE_DRAWMODE);
	glutAddMenuEntry("Draw 10 Objects", TEN_OBJECTS);
	glutAddMenuEntry("Draw 35 Objects", THIRTYFIVE_OBJECTS);
	glutAddMenuEntry("Draw 100 Objects", HUNDRED_OBJECTS);
		
	GLint mainMenu = glutCreateMenu(MenuHandler);
	glutAddMenuEntry("Toggle Axes", TOGGLE_AXES);
	glutAddMenuEntry("Toggle Plane", TOGGLE_PLANE);
	glutAddMenuEntry("Toggle Lights", TOGGLE_LIGHTS);
	glutAddSubMenu("Drawing Options", drawingSubMenu);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	

}

void MenuHandler(int menuEntryValue)
{
	switch(menuEntryValue)
	{
	case 101:
		axesOn = !axesOn;
		break;
	case 102:
		planeOn = !planeOn;
		break;
	case 103:
		lightsOn = !lightsOn;
		if (lightsOn)
		{
			glEnable(GL_LIGHT0);
		}
		else
		{
			glDisable(GL_LIGHT0);
		}
		break;
	
	case 201:
		drawMode = !drawMode;
		break;
	
	case 202:
		drawCount = 10;
		break;
		
	case 203:
		drawCount = 35;
		break;
		
	case 204:
		drawCount = 100;
		break;
	}
}

void SetupDisplayLists()
{
	listCount = glGenLists(3);
	glNewList(listCount, GL_COMPILE);
		for (int i = 0; i < 10; ++i)
		{
			tetra[i].DrawMe();
			cube[i].DrawMe();
		}
	glEndList();
	glNewList(listCount + 1, GL_COMPILE);
		for (int i = 0; i < 35; ++i)
		{
			tetra[i].DrawMe();
			cube[i].DrawMe();
		}
	glEndList();
	glNewList(listCount + 2, GL_COMPILE);
		for (int i = 0; i < 100; ++i)
		{
			tetra[i].DrawMe();
			cube[i].DrawMe();
		}
	glEndList();

}

void ChangeView(GLint button, GLint state, GLint x, GLint y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		toggleView = !toggleView;
	}
}
void setPerspective()		
{
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		if (toggleView)
		{
			gluPerspective(90.0, 1.0, 10.0, 400.0); //only takes four arguments
		}
		else
		{
			glOrtho(-200.0, 200.0, -200.0, 200.0, -500.0, 500.0);
		}
		glMatrixMode(GL_MODELVIEW);
}		
			
		
	



