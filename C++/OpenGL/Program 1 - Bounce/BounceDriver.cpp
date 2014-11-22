// BounceDriver.cpp
// Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
//this to avoid the black console window
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>		// Glut (Free-Glut on Windows)
#include "Bounce.h"

using namespace std;
// Initial square position and size
GLfloat x = 0.0f;
GLfloat y = 0.0f;
GLfloat rsize = 25;

// Step size in x and y directions
// (number of pixels to move each time)
GLfloat xstep = 2.0f;
GLfloat ystep = 2.0f;

// Keep track of windows changing width and height
GLfloat windowWidth;
GLfloat windowHeight;

GLfloat sizeOfTeapot = 30.0f;//used in renderscene
GLfloat speeds[3] = {0.0f, 1.0f, 2.0f};//used in ChangeColorOrSpeed
GLfloat colorsR[6] = {1.0f, 1.0f, 0.5f, 0.0f, 0.0f, 0.5f};
GLfloat colorsG[6] = {0.0f, 0.5f, 1.0f, 1.0f, 0.0f, 0.0f};
GLfloat colorsB[6] = {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.5f};
GLint clipping[3] = {50, 100, 200};
GLint indeXA = 4;//used for color arrays
GLint indeXB = 0;//used for speed array
GLint cycle = 1;//used in changeClipping
GLboolean On = false; //used in changeViewport
GLint width, height;//used to keep track of w and h globally

///////////////////////////////////////////////////////////
// Main program entry point
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500,500);
    glutCreateWindow("Ryan Sloan - SloanP1");
	glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
	glutTimerFunc(33, TimerFunction, 1);

	SetupRC();

	glutMainLoop();
        
    return 0;
}

