
#include <windows.h>		// Must have for Windows platform builds
#include <gl/freeglut.h>
#include "Component.h"
#include "sloanFire.h"

#ifndef FLAMETHROWER_H
#define FLAMETHROWER_H

class FlameThrower : public Component
{
public:
	GLint FTcount;
	GLboolean fireOn;
	Fire flames;
	FlameThrower();
	void Draw(); 
	void Update(); 
	void Setup();
	void Reset();

};

#endif