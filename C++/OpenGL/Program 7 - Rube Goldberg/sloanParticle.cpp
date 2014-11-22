//Ryan Sloan
//Particle Definition for Particle Engine 
// - SloanP6 -
//OpenGL
//CIS 2270
//rsloan2@cnm.edu

#include <windows.h>		// Must have for Windows platform builds
#include <gl/freeglut.h>

#include "Particle.h"
#include "Functions.h"


using namespace std;


Particle::Particle(){

InitParticle();

}

void Particle::InitParticle()
{
	R = 1.0f;
	G = 0.3f;
	B = 0.0f;
	X = 0.0f; 
	Y = 2.0f;
	Z = 0.0f; 
}


