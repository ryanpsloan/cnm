// BounceDriver.cpp
// Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
//this to avoid the black console window
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>		// Glut (Free-Glut on Windows)
#include "Functions.h"

using namespace std;

GLboolean planesOn = true;
GLboolean axesOn = true;
GLboolean triangleFanOn = true;
GLboolean allItemsOn = true;
GLboolean depthTestingOn = true;
GLboolean teapotOn = true;
GLboolean toggleFrontFace = true;
GLboolean toggleBackFace = true;
GLint toggleTeapot = 0;
GLfloat r = 0.15f, g = 0.15f, b = 0.15f;
GLint changeColor = 1;
GLfloat sizeOfTeapot = 30.0f;//used in renderscene
GLint width, height;//used to keep track of w and h globally

GLfloat eyex, eyey, eyez;
GLint azimuth = 45, elevation = 20, radius = 300;
GLint iPivot = 1;

///////////////////////////////////////////////////////////
// Main program entry point
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500,500);
    glutCreateWindow("Ryan Sloan - SloanP1");
	glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
	glutTimerFunc(33, TimerFunction, 1);
	SetupMenus();
	SetupRC();

	glutMainLoop();
        
    return 0;
}

