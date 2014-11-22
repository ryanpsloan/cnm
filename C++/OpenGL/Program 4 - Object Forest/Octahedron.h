//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>
#include <random>
using namespace std;

#ifndef _OCTAHEDRON_H
#define _OCTAHEDRON_H

class Octahedron
{
private:
	GLfloat r, g, b, sizex, sizey, sizez, xpos, ypos, zpos;
	
public:
	Octahedron();
	void DrawMe();
};


#endif