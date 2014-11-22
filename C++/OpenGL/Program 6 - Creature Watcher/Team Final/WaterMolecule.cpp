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
#include "WaterMolecule.h"

using namespace std;


WaterMolecule::WaterMolecule(){
	InitWaterMolecule();
}

void WaterMolecule::InitWaterMolecule(){
	R = 0.0f;
	G = 0.0f;
	B = 0.0f;
	X = 0.0f;
	Y = 5.0f;
	Z = 0.0f;

}
