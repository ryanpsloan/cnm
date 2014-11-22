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


#ifndef _PARTICLE_H
#define _PARTICLE_H

class Particle
{

public:
	
	GLfloat X,Y,Z;		// Current position
	GLfloat R,B,G;		// Particle Colour
	
	Particle();
	void InitParticle();
	void InitSnowFlake();
};	
	



















#endif