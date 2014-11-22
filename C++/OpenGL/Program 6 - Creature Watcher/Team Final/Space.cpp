//Ryan Sloan
//Star Class 
// - SloanP6 -
//OpenGL
//CIS 2270
//rsloan2@cnm.edu

#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>
#include "Particle.h"
#include "Functions.h"
#include "ParticleEngine.h"
#include "Star.h"
#include "Space.h"
extern bool kdfloor;


Space::Space(){}
void Space::DrawSpace(){
	glDisable(GL_DEPTH_TEST);
	if(kdfloor)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.5f, 0.5f, 0.5f);		//White Plane
		glVertex3f(150.0f, 0.0f, 150.0f);
		glVertex3f(150.0f, 0.0f, -150.0f);
		glVertex3f(-150.0f, 0.0f, -150.0f);
		glVertex3f(-150.0f, 0.0f, 150.0f);
		glEnd();
	}
		
	glEnable(GL_DEPTH_TEST);
}

