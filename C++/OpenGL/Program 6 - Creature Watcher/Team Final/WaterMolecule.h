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


#ifndef _WATERMOLECULE_H
#define _WATERMOLECULE_H
class WaterMolecule
{
public:
GLfloat R, G, B, X, Y, Z;
WaterMolecule();
void InitWaterMolecule();
void Melt();
};
#endif