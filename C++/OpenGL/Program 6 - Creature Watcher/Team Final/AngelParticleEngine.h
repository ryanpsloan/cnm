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
#include "Particle.h"
#include "Functions.h"

#ifndef _ANGEL_PARTICLE_ENGINE_H
#define _ANGEL_PARTICLE_ENGINE_H



class AngelParticleEngine : public Particle
{
public:
	Particle Particles[MAX_PARTICLES];
	Particle MirrorParticles[MAX_PARTICLES];
	//A
	Particle ParticlesA[MAX_PARTICLES];
	Particle MirrorParticlesA[MAX_PARTICLES];
	//B
	Particle ParticlesB[MAX_PARTICLES];
	Particle MirrorParticlesB[MAX_PARTICLES];
	//C
	Particle ParticlesC[MAX_PARTICLES];
	Particle MirrorParticlesC[MAX_PARTICLES];
	
	AngelParticleEngine();
	void SunFire();
	
};
#endif

