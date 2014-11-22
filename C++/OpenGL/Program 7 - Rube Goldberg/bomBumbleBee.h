//Bresdin O'Malley
//brezomalley@gmail.com
//bumblebee.h

#ifndef BUMBLEBEE_H
#define BUMBLEBEE_H

#include <windows.h>
#include <gl/freeglut.h>
#include <math.h>
#include <gl/glut.h>
#include <stdio.h>
#include "Component.h"

struct Tri
{
		GLfloat x, y, z;
};

class BumbleBee : public Component
{
private:
	GLfloat Yaw, X, Z;
	GLfloat fly; //amount wings will move
	GLboolean flyUp; //Will control whether wings are up or down
	GLuint index;	//
	GLUquadricObj *qobj;
	int previousTime;

	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;
	GLuint Texture;

public:
	BumbleBee();
	//------------- From Component
	void Draw();
	void Update();
	void Setup();
	void Reset();

	//----------------- Drawing the bee
	void BeeBody();
	void BeeHead();
	void Wing();
	void FullWing();
	void MoveWings();

	void ForwardMove(GLfloat unit);
	void Rotate(GLfloat angle);

	//------------------------- Bee body texture
	void SetTexture();
	GLuint loadBMP_custom(const char * imagepath);

};

#endif