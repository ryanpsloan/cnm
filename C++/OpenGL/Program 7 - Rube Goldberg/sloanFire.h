//Ryan Sloan
//Particle Definition for Particle Engine 
// - SloanP6 -
//OpenGL
//CIS 2270
//rsloan2@cnm.edu

#include <windows.h>		// Must have for Windows platform builds
#include <gl\freeglut.h>
#include "Functions.h"

#ifndef _FIRE_H
#define _FIRE_H
#define MAX_PARTICLES 5000

class Fire 
{
public:
	Particle Particles[MAX_PARTICLES];
	Fire();
	void Pos();
	
};

#endif