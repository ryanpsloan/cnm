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
#include "Particle.h"
#include "Functions.h"
#include "ParticleEngine.h"

#ifndef _SPACE_H
#define _SPACE_H

class Space 
{
public:
	
	Space();
	void DrawSpace();
	
};
#endif