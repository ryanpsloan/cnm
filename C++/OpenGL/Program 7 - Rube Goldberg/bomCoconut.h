
#ifndef COCONUT_H
#define COCONUT_H

#include <windows.h>
#include <gl/freeglut.h>
#include <math.h>
#include <gl/glut.h>
#include "Component.h"


class Coconut : public Component
{
private:
	GLuint index, c;
	GLboolean drop, swingForward; // This will drop the coconut
	GLfloat swing;

public:
	Coconut();

	void Draw();
	void Update();
	void Setup();
	void Reset();

};

#endif