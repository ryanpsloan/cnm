//Bounce.h
//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>

#define PI 3.1415926535

void RenderScene(void);
void TimerFunction(int value);
void SetupRC(void);
void ChangeSize(int w, int h);
void ChangeColorOrSpeed(GLint button, GLint state, GLint x, GLint y);
void ChangeFunction(GLubyte key, GLint x, GLint y);
void CalculateEye();
void SpecialKeys(int key, int x, int y);
