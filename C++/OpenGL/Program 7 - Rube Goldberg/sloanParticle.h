//Ryan Sloan
//Particle Definition for Particle Engine 
// - SloanP6 -
//OpenGL
//CIS 2270
//rsloan2@cnm.edu

#include <windows.h>		// Must have for Windows platform builds
#include <gl/freeglut.h>

#ifndef _PARTICLE_H
#define _PARTICLE_H

class Particle
{

public:
	
	GLfloat X,Y,Z;		// Current position
	GLfloat R,B,G;		// Particle Colour
	
	Particle();
	void InitParticle();
	
};	
	



















#endif