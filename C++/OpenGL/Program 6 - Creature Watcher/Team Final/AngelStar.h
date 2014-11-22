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
#include "AngelParticleEngine.h"
#include "Fire.h"



#ifndef _ANGELSTAR_H
#define _ANGELSTAR_H

class AngelStar : public AngelParticleEngine
{
private: //33 Particle Engines
	AngelParticleEngine particleEngine;
	AngelParticleEngine particleEngine01;
	AngelParticleEngine particleEngine02;
	AngelParticleEngine particleEngine03;
	AngelParticleEngine particleEngine04;
	AngelParticleEngine particleEngine05;
	AngelParticleEngine particleEngine06;
	AngelParticleEngine particleEngine07;
	AngelParticleEngine particleEngine08;
	AngelParticleEngine particleEngine09;
	AngelParticleEngine particleEngine10;
	AngelParticleEngine particleEngine11;
	AngelParticleEngine particleEngine12;
	AngelParticleEngine particleEngine13;
	AngelParticleEngine particleEngine14;
	AngelParticleEngine particleEngine15;
	AngelParticleEngine particleEngine16;
	AngelParticleEngine particleEngine17;
	AngelParticleEngine particleEngine18;
	AngelParticleEngine particleEngine19;
	AngelParticleEngine particleEngine20;
	AngelParticleEngine particleEngine21;
	AngelParticleEngine particleEngine22;
	AngelParticleEngine particleEngine23;
	AngelParticleEngine particleEngine24;
	AngelParticleEngine particleEngine25;
	AngelParticleEngine particleEngine26;
	AngelParticleEngine particleEngine27;
	AngelParticleEngine particleEngine28;
	AngelParticleEngine particleEngine29;
	AngelParticleEngine particleEngine30;
	AngelParticleEngine particleEngine31;
	AngelParticleEngine particleEngine32;
	AngelParticleEngine particleEngine33;
	

	
public:	
	Fire fire;
	AngelStar();
	~AngelStar();
	void RenderStar(GLfloat D, GLfloat RA, GLfloat Distance);
	
	
};
#endif