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

extern GLUquadricObj *O;
extern GLboolean flamesOn;


Star::Star(){ 

	O = gluNewQuadric();
	
}

Star::~Star(){
	gluDeleteQuadric(O);
	
}

void Star::CreateStar(GLfloat Declination, GLfloat RightAscension, GLfloat DistanceAway){
	glDisable(GL_DEPTH_TEST);
	
		glPushMatrix();
			glTranslatef(Declination, RightAscension, DistanceAway);
			glColor3f(1.0, 0.777f, 0.0f);
			glutWireSphere(1.777, 5, 5);
			gluSphere(O, 1.777f, 444, 444); 
			if(flamesOn){
				particleEngine.Pos();
				particleEngine.Neg();
				particleEngine.Neu();
			}
		glPopMatrix();
	
	glEnable(GL_DEPTH_TEST);
	
}

void Star::FireRender(){
	glPushMatrix();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		particleEngine.Pos(); 
	glPopMatrix();
}