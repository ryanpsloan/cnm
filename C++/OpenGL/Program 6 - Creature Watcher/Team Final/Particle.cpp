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
#include <ctime>

#include "Particle.h"
#include "Functions.h"


using namespace std;


Particle::Particle(){

InitParticle();

}

void Particle::InitParticle()
{
	R = 1.0f;
	G = 1.0f;
	B = 1.0f;
	X = 0.0f; 
	Y = 0.0f;
	Z = 0.0f; 
}


