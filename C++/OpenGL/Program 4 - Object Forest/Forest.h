//Bounce.h
//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>

void RenderScene(void);
void TimerFunction(int value);
void SetupRC(void);
void SetupMenus();
void SetupDisplayLists();
void ChangeSize(int w, int h);
void ChangeView(GLint button, GLint state, GLint x, GLint y);
void ChangeFunction(GLubyte key, GLint x, GLint y);
void CalculateEye();
void SpecialKeys(int key, int x, int y);
void MenuHandler(int menuEntryValue);
void setPerspective();


#define PI 3.1415926535f

#define TOGGLE_AXES 101
#define TOGGLE_PLANE 102

#define TOGGLE_LIGHTS 103

#define TOGGLE_DRAWMODE 201
#define TEN_OBJECTS 202
#define THIRTYFIVE_OBJECTS 203
#define HUNDRED_OBJECTS 204


//#ifdef _IN_DRIVER_
//#else
//#endif
