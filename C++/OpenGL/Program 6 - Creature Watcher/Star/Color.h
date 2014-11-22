//Color.h
//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>

#ifndef _COLOR_H
#define _COLOR_H



class Color {
	GLfloat R;
	GLfloat G;
	GLfloat B;

public:
	Color();
	void setRed();
	void setOrange();
	void setYellow();
	void setGreen();
	void setBlue();
	void setPurple();
	GLfloat getR(){return R;}
	GLfloat getG(){return G;}
	GLfloat getB(){return B;}
};
#endif