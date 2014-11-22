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
void ChangeSize(int w, int h);
void ChangeFunction(GLubyte key, GLint x, GLint y);
void CalculateEye();
void SpecialKeys(int key, int x, int y);
void MenuHandler(int menuEntryValue);

#define PI 3.1415926535f

#define OBJECTS_MENU 100
#define TOGGLE_AXES 101
#define TOGGLE_PLANES 102
#define TOGGLE_TRIANGLES 103
#define SHOW_HIDE 104

#define POLYGON_MENU 200
#define TOGGLE_FRONT_FACE 201
#define TOGGLE_BACK_FACE 202
#define TOGGLE_FRONT_AND_BACK_FACE 203

#define TOGGLE_DEPTH_TESTING 301

#define TEAPOT_MENU 105
#define TOGGLE_WIRE 401
#define TOGGLE_TEAPOT 402

