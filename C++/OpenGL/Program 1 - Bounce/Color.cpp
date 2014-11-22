//Color.cpp
//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>	
#include "Color.h"

	
	Color::Color(){

	}
	void Color::setRed(){
		
		R = 1.0f;
		G = 0.0f;
		B = 0.0f;
		
	}
	void Color::setOrange(){
		
		R = 1.0f;
		G = 0.5f;
		B = 0.0f;

		
	}
	void Color::setYellow(){
		
		R = 0.5f;
		G = 1.0f;
		B = 0.0f;
		
	}
	void Color::setGreen(){
		
		R = 0.0f;
		G = 1.0f;
		B = 0.0f;
	
	}
	void Color::setBlue(){
		
		R = 0.0f;
		G = 0.0f;
		B = 1.0f;
	
	}
	void Color::setPurple(){
		
		R = 0.5f;
		G = 0.0f;
		B = 0.5f;
		
	}
	