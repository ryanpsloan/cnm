//Ryan Sloan
//Particle Definition for Particle Engine 
// - SloanP6 -
//OpenGL
//CIS 2270
//rsloan2@cnm.edu

#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>
#include "ParticleEngine.h"
#include "Functions.h"

#ifndef _FIRE_H
#define _FIRE_H
class Fire : public ParticleEngine
{
public:
	Particle Particles[MAX_PARTICLES];
	ParticleEngine pEngine;
	Fire();
	void Pos();
	void Neg();
	void Neu();
	
};

#endif