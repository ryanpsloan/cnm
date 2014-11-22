//ColorChangeCode.cpp
//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>
#include "Color.h"
#include "ColorChangeCode.h"

ColorChangeCode::ColorChangeCode()
{
	colors = new Color[6];
	colors[0].setRed();
	colors[1].setOrange();
	colors[2].setYellow();
	colors[3].setGreen();
	colors[4].setBlue();
	colors[5].setPurple();
}


