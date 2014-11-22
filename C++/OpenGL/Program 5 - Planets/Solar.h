#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>		// Glut (Free-Glut on Windows)

#define PI 3.1415926535f
#define TOGGLE_LIGHTS 101
#define TOGGLE_OBJ_AXIS 102
#define TOGGLE_WORLD_AXIS 103
#define RESET_SCENE 104
#define CHANGE_SPEED 105

void RenderScene();
void SetupRC();
void TimerFunc(int value);
void ChangeSize(int w, int h);
void CalculateEye();
void SetupMenus();
void MenuHandler(int menuEntryValue);
void ChangeView(GLint button, GLint state, GLint x, GLint y);
void ChangeFunction(GLubyte key, GLint x, GLint y);
void SpecialKeys(int key, int x, int y);
void drawSun();
void drawEarth();
void drawMoon();
void drawCube();
void drawCubeNearMoon();
void drawCubeFarMoon();
void drawPlanet();


