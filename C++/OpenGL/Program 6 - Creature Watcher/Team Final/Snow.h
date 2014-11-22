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
#include "SnowFlake.h"

#ifndef _SNOW_H
#define _SNOW_H

class Snow : public SnowFlake
{
public:
	SnowFlake SnowFlakes[MAX_SNOWFLAKES];
	Snow();
	void LetItSnow();
};
#endif