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
#include "Functions.h"
#include "WaterMolecule.h"

#ifndef _WATER_H
#define _WATER_H

class Water : public WaterMolecule
{
public:
	WaterMolecule FlowingWater[MAX_WATERMOLECULES];
	Water();
	void Melt();

};

#endif