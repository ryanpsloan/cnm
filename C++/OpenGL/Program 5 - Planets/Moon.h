//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>
#include "Shape.h"

using namespace std;

#ifndef _MOON_H
#define _MOON_H

class Moon : protected Shape
{
private:
	GLfloat size;
	
public:
	Moon();
	void DrawMe();
};


#endif