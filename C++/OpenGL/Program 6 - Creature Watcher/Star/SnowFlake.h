//Ryan Sloan
//Star Class 
// - SloanP6 -
//OpenGL
//CIS 2270
//rsloan2@cnm.edu

#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>
#include "Functions.h"


#ifndef _SNOWFLAKE_H
#define _SNOWFLAKE_H

class SnowFlake 
{
public:
	GLfloat X, Y, Z, R, G, B;
	SnowFlake();
	void InitSnowFlake();
	void LetItSnow();
};
#endif