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

#ifndef _IMA_STAR_H
#define _IMA_STAR_H

class Star : public ParticleEngine
{
private:
	ParticleEngine particleEngine;
	
public:		
	Star();
	~Star();
	void CreateStar(GLfloat D, GLfloat RA, GLfloat Distance);
	void FireRender();
	
};
#endif

