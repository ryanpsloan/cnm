//ColorChangeCode.h
//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h> 
#include "Color.h"

using namespace std;
#ifndef _COLORCHANGECODE_H
#define _COLORCHANGECODE_H

class ColorChangeCode : public Color {
	
public:
	Color* colors;
	ColorChangeCode();
	~ColorChangeCode(){delete[] colors;}
};	




#endif