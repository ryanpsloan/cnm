//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>
#include "Earth.h"

using namespace std;

Earth::Earth()
{
	r = 0.00f;
	g = 0.00f;
	b = 1.00f;

	earthRadius = 15.0f;
	earthSlices = 10.0f;
	earthStacks = 5.0f;
}
	
	

void Earth::DrawMe()
{
	glColor3f(r, g, b);
	glTranslatef(xpos, ypos, zpos);
	glutSolidSphere(earthRadius, earthSlices, earthStacks);
}