//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>

using namespace std;

#ifndef _CUBE_H
#define _CUBE_H

class Cube
{
private:
	GLfloat r, g, b, size, xpos, ypos, zpos;
	
public:
	Cube();
	void DrawMe();
};


#endif