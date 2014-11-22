//Driver.cpp
// Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
//this to avoid the black console window
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>		// Glut (Free-Glut on Windows)
#include "Particle.h"
#include "Functions.h"
#include "ParticleEngine.h"
#include "Star.h"
#include "tAxis.h"
#include "Space.h"
#include "Snow.h"
#include "SnowFlake.h"
#include "AngelStar.h"
#include "AngelParticleEngine.h"
#include "Fire.h"
using namespace std;

GLfloat eyeX, eyeY, eyeZ;

GLint azimuth = 0, elevation = 45, radius = 200;
tAxis axis;
tAxis fireAxis;

GLuint txParticle;
GLuint txPlane;

GLUquadricObj *O;
AngelStar shinningStar;
Star starMaker;
Star fireBall;
Space layout;
GLfloat starX= 45.0f, starY = 10.0f, starZ= 0.0f; 

Snow snow;







///////////////////////////////////////////////////////////
// Main program entry point
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(700, 1100);
    glutCreateWindow("Ryan Sloan - SloanP6");
	glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
	glutTimerFunc(100, TimerFunc, 1);
	SetupRC();
	setupMenu();
	glutKeyboardFunc(ChangeFunction);
	glutSpecialFunc(SpecialKeys);
	glutMainLoop();
    
    return 0;
}