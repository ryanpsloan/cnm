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
#include "Star.h"
#include "Space.h"
#include "SnowFlake.h"

SnowFlake::SnowFlake(){

	InitSnowFlake();
	
}

void SnowFlake::InitSnowFlake(){

	R = 1.0f;
	G = 1.0f;
	B = 1.0f;
	X = rand()%200 - 100.0f; 
	Y = 26.0;
	Z = rand()%200 - 100.0f; 
	
}

