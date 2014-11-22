#include <windows.h>		// Must have for Windows platform builds
#include <gl/freeglut.h>

#define PI 3.1415926535f

#define ToRad(x) PI * x / 180.0f
#define ToDeg(x) 180.0f * x / PI

void RenderScene();
void SetupRC();
void TimerFunc(int value);
void ChangeSize(int w, int h);
void CalculateEye();
void ChangeView(GLint button, GLint state, GLint x, GLint y);
void ChangeFunction(GLubyte key, GLint x, GLint y);
void SpecialKeys(int key, int x, int y);
void setupMenu();
void SelectFromMenu(int command);


