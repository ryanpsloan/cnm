//Driver.cpp
// Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
//this to avoid the black console window
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>		// Glut (Free-Glut on Windows)

//#define _IN_DRIVER_
#include "Forest.h"
#include "Tetrahedron.h"
#include "Cube.h"

using namespace std;

//indriver
GLboolean planeOn = true;														
GLboolean axesOn = true;
GLboolean lightsOn = true;
GLboolean drawMode = true;
GLboolean toggleView = true;

Tetrahedron tetra[100];
Cube cube[100];

GLfloat eyex, eyey, eyez;
GLint timeT = 0, timebase = 0;
GLfloat pos[] = {100.0f, 100.0f, 100.0f, 0.0f};
GLint azimuth = 45, elevation = 20, radius = 300;
GLint drawCount = 100;
GLint listCount = 0;
GLint frame = 0;
GLint width, height;//used to keep track of w and h globally

///////////////////////////////////////////////////////////
// Main program entry point
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
    glutCreateWindow("Ryan Sloan - SloanP4");
	glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
	glutTimerFunc(1, TimerFunction, 1);
	SetupDisplayLists();
	SetupMenus();
	SetupRC();
	glutMouseFunc(ChangeView);
	glutKeyboardFunc(ChangeFunction);
	glutSpecialFunc(SpecialKeys);
	glutMainLoop();
    
    return 0;
}

