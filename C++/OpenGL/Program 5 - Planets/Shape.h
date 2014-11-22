//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>

using namespace std;

#ifndef _SHAPE_H
#define _SHAPE_H

class Shape
{
protected:
	GLfloat r, g, b, xpos, ypos, zpos;
	
public:
	//Shape();
	//virtual void DrawMe();
};


#endif