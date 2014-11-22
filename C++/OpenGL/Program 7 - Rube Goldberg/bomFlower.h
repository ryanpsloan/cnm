//Bresdin O'Malley
//brezomalley@gmail.com
//flower.h

#ifndef FLOWER_H
#define FLOWER_H

#include <windows.h>
#include <gl/freeglut.h>
#include <math.h>
#include <gl/glut.h>
#include "Component.h"

struct Triangles
{
	//This struct allows an array to define 
	//points of triangles for the leaves
	GLfloat x, y, z;
};

class Flower : public Component
{
private:
	GLfloat x, z, y, Yaw, size, X, Z, sphereSize;
	int count, count2;
	float leafC1;
	static GLubyte petals[20][3];
	GLuint index;
	GLUquadricObj *qobj;
	GLboolean doneDrawing; // To start next machine
	bool up;

	GLfloat angle;
	int spheres; 
	GLfloat dist;

public:
	Flower();
	Flower(GLfloat x, GLfloat z, GLfloat yaw=0.0);

	void Draw(); 
	void Setup();
	void Update();
	void Reset();
	
	void StemBase();
	void FlowerLeaves();
	void FlowerPetals();
	void Middle(GLfloat sphereSize);
};

#endif