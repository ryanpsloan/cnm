
#include <windows.h>		// Must have for Windows platform builds
#include <gl/freeglut.h>
#include "Component.h"
//#include "Ice.h"

#ifndef ICECUBE_H
#define ICECUBE_H

class IceCube : public Component
{
public:
	GLint ICcount;
	GLfloat cSize, pSize, cubeScale, puddleScale;
	IceCube(); 
	void Draw(); 
	void Update(); 
	void Setup();
	void Reset();
	
};

#endif