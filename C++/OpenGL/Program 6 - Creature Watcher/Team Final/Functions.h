#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>		// Glut (Free-Glut on Windows)

#include "Particle.h"

#define PI 3.1415926535f

#define ToRad(x) PI * x / 180.0f
#define ToDeg(x) 180.0f * x / PI

#define MAX_PARTICLES 11111
#define MAX_SNOWFLAKES 1111
#define MAX_WATERMOLECULES 1111

#define X_AXIS 0
#define	Y_AXIS 1 
#define	Z_AXIS 3

#define NEU 2
#define POS 1
#define NEG 0

void RenderScene();
void SetupRC();
void TimerFunc(int value);
void ChangeSize(int w, int h);
void CalculateEye();
void ChangeView(GLint button, GLint state, GLint x, GLint y);
void ChangeFunction(GLubyte key, GLint x, GLint y);
void SpecialKeys(int key, int x, int y);
void setupLists();
void setupMenu();
void calc();
void SelectFromMenu(int command);


