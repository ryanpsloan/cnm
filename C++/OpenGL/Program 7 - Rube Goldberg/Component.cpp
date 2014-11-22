 //Component.cpp
#include <GL/freeglut.h>
#include "Component.h"

Component::Component()
{
	ColorR = ColorG = ColorB = 128; //gray
	bRunning = false;
	bStartNext = false;
	RotAngle = 0.0;
	XPos = YPos = ZPos = 0.0;
	DegreeStart = AngleXStart = AngleYStart = AngleZStart = 0;
	
	ScaleX = 1.0;
	ScaleY = 1.0;
	ScaleZ = 1.0;
}

void Component::SetStartPos(float XStart, float YStart, float ZStart)
{
	XPos = XStart;
	YPos = YStart;
	ZPos = ZStart;
}

void Component::SetColor(float R, float G, float B)
{
	ColorR = R;
	ColorG = G;
	ColorB = B;
}

void Component::SetRotation(GLfloat degrees, GLfloat x, GLfloat y, GLfloat z)
{
	DegreeStart = degrees;
	AngleXStart = x;
	AngleYStart = y;
	AngleZStart = z;
}

void Component::SetScale(GLfloat x, GLfloat y, GLfloat z)
{
	ScaleX = x;
	ScaleY = y;
	ScaleZ = z;
}

