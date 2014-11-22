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
#include "sloanParticle.h"
#include "Functions.h"

#ifndef _PARTICLE_ENGINE_H
#define _PARTICLE_ENGINE_H

class ParticleEngine : public Particle
{
public:
	Particle Particles;//[MAX_PARTICLES];
	ParticleEngine();
	void Pos();
	void Neg();
	void Neu();
	
};
#endif

