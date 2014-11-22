//Aaron Gresham
//Moses Baca
//TeapotMouse.h

#ifndef _TEAPOT_MOUSE_H_
#define _TEAPOT_MOUSE_H_

#include <gl/glut.h>

class TeapotMouse
{
protected:
	GLfloat X, Z, Yaw, size;

public:
	TeapotMouse();
	TeapotMouse(GLfloat x, GLfloat z, GLfloat yaw=0.0);
	void RotateLocalY(GLfloat angle);
	void FowardMove(GLfloat unit);
	void BackMove(GLfloat unit) {FowardMove(-unit);}
	void ObjectSize(GLfloat s){size = s;}
	void Render();
	void GetMyPos(GLfloat &rX, GLfloat &rY, GLfloat &rZ);
	void SetMyPos(GLfloat X, GLfloat z);
};

#endif
