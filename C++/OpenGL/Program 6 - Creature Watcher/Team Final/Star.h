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

#ifndef _IMA_STAR_H
#define _IMA_STAR_H

class Star : public ParticleEngine
{
private:
	ParticleEngine particleEngine;
	ParticleEngine fireBallEngine;
	GLfloat X, Z, Yaw, size;
	
public:		
	Star();
	~Star();
	void RenderStar(GLfloat D, GLfloat RA, GLfloat Distance);
	void RotateLocalY(GLfloat angle);
	void FowardMove(GLfloat unit);
	void BackMove(GLfloat unit) {FowardMove(-unit);}
	void ObjectSize(GLfloat s){size = s;}
	void GetMyPos(GLfloat &rX, GLfloat &rY, GLfloat &rZ);
	void SetMyPos(GLfloat X, GLfloat z);

	
};
#endif

