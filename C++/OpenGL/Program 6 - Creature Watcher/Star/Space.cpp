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

Space::Space(){}
void Space::DrawSpace(){
	glDisable(GL_DEPTH_TEST);
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 1.0f);		
		glVertex3f(100.0f, 0.0f, 50.0f);
		glVertex3f(100.0f, 0.0f, -50.0f);
		glVertex3f(-100.0f, 0.0f, -50.0f);
		glVertex3f(-100.0f, 0.0f, 50.0f);
	glEnd();
		glPushMatrix();
			glTranslatef(0.0f, 0.0f, -100.0);
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			glColor3f(1.0f, 0.777f, 0.0f);
		glBegin(GL_POLYGON);
			glVertex3f(100.0f, 0.0f, 50.0f);
			glVertex3f(100.0f, 0.0f, -50.0f);
			glVertex3f(-100.0f, 0.0f, -50.0f);
			glVertex3f(-100.0f, 0.0f, 50.0f);
		glEnd();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-100.0f, 0.0f, 0.0);
			glRotatef(90.0f, 0.0f, 0.0f, 1.0f);			
		glBegin(GL_POLYGON);
			glVertex3f(100.0f, 0.0f, 50.0f);
			glVertex3f(100.0f, 0.0f, -50.0f);
			glVertex3f(-100.0f, 0.0f, -50.0f);
			glVertex3f(-100.0f, 0.0f, 50.0f);
		glEnd();
	
	glEnable(GL_DEPTH_TEST);
}

