//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>
#include "Shape.h"

using namespace std;

#ifndef _EARTH_H
#define _EARTH_H

class Earth : protected Shape
{
private:
	GLfloat earthRadius, earthSlices, earthStacks;
	
public:
	Earth();
	void DrawMe();
};


#endif