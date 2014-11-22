//Driver.cpp
// Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
//this to avoid the black console window
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>		// Glut (Free-Glut on Windows)

#include "tAxis.h"
#include "Solar.h"

using namespace std;

GLboolean objAxesOn = true;
GLboolean worldAxesOn = true;
GLboolean lightsOn = true;

GLfloat eyeX, eyeY, eyeZ;
GLint azimuth = 45, elevation = 20, radius = 300;
GLint speed = 0;
tAxis axis;
GLfloat angle = 5.0;

///////////////////////////////////////////////////////////
// Main program entry point
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(750, 750);
    glutCreateWindow("Ryan Sloan - SloanP5");
	glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
	glutTimerFunc(1, TimerFunc, 1);
	SetupMenus();
	SetupRC();
	glutKeyboardFunc(ChangeFunction);
	glutSpecialFunc(SpecialKeys);
	glutMainLoop();
    
    return 0;
}

