//Aaron Gresham
//Moses Baca
//TeapotMouse.cpp

#include "TeapotMouse.h"
#include <cmath>
#include <gl/glut.h>
using namespace std;

#define PI 3.14159265
#define ToRad(x) PI * x / 180.0f
#define ToDeg(x) 180.0f * x / PI

TeapotMouse::TeapotMouse()
{
	X = Z = 0.0f;


	Yaw = 0.0f;
	size = 5.0f;
}

TeapotMouse::TeapotMouse(GLfloat x, GLfloat z, GLfloat yaw)
{
	X = x;
	Z = z;

	Yaw = yaw;
	size = 5.0f;
}

void TeapotMouse::RotateLocalY(GLfloat angle)
{
	Yaw += angle;

	if(Yaw > 360.0f)
		Yaw -= 360.0f;
	else if(Yaw < 0.0f)
		Yaw += 360.0f;
}

void TeapotMouse::FowardMove(GLfloat unit)
{
	X += sin(ToRad(Yaw)) * unit;
	Z += cos(ToRad(Yaw)) * unit;
}

void TeapotMouse::Render()
{
	glPushMatrix();
	
	glTranslatef(X, size, Z);
	glRotatef(Yaw-90.0, 0.0, 1.0, 0.0);

	glColor3f(1.0, 0.0, 0.0);
	glutWireTeapot(5);

	glPopMatrix();
}

void TeapotMouse::GetMyPos(GLfloat &rX, GLfloat &rY, GLfloat &rZ)
{
	rX = X;
	rY = size;
	rZ = Z;
}

void TeapotMouse::SetMyPos(GLfloat x, GLfloat z){
	X = x;
	Z = z;

}