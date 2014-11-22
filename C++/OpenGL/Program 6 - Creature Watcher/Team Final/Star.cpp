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
#include "tAxis.h"
#include <math.h>
extern GLUquadricObj *O;
extern bool kdfire, kdfireball, kdaxes;
extern tAxis fireAxis;
extern GLfloat starX, starY, starZ;

Star::Star(){ 

	O = gluNewQuadric();
	
	X = Z = 0.0f;


	Yaw = 0.0f;
	size = 5.0f;
	
}

Star::~Star(){
	gluDeleteQuadric(O);
	
}

void Star::RenderStar(GLfloat Declination, GLfloat RightAscension, GLfloat DistanceAway){
	glDisable(GL_DEPTH_TEST);
		
		glPushMatrix();
			X = Declination;
			size = RightAscension;
			Z = DistanceAway;
			if(kdaxes){
				fireAxis.SetDistance(12.0);
				fireAxis.HideTicks();
				fireAxis.SetAxisColor(X_AXIS, 1.0f, 0.777f, 0.0f);
				fireAxis.SetAxisColor(Y_AXIS, 1.0f, 0.777f, 0.0f);
				fireAxis.SetAxisColor(Z_AXIS, 1.0f, 0.777f, 0.0f);
				fireAxis.Draw();
			}
			glTranslatef(Declination, RightAscension, DistanceAway);
			glRotatef(Yaw-90.0f, 0.0f, 1.0f, 0.0f);
			glColor3f(1.0, 0.777f, 0.0f);
			glutWireSphere(1.777, 5, 5);
			gluSphere(O, 1.777f, 444, 444); 
			particleEngine.Pos();
			particleEngine.Neu();
			
			if(kdfireball)
			{
				glRotatef(90.0f, 1.0f, 0.0f, 1.0f);
				fireBallEngine.RenderFire();
			}
		glPopMatrix();
	
	glEnable(GL_DEPTH_TEST);
	
}


void Star::RotateLocalY(GLfloat angle)
{
	Yaw += angle;

	if(Yaw > 360.0f)
		Yaw -= 360.0f;
	else if(Yaw < 0.0f)
		Yaw += 360.0f;
}

void Star::FowardMove(GLfloat unit)
{
	X += sin(ToRad(Yaw)) * unit;
	Z += cos(ToRad(Yaw)) * unit;
	if(X > 150 || X < -150){
		if (X > 0.0f)
			X = 150;
		else
			X = -150;
	}
	if(Z > 150 || Z < -150){
		if (Z > 0.0f)
			Z = 150;
		else
			Z = -150;
	}
}

void Star::GetMyPos(GLfloat &rX, GLfloat &rY, GLfloat &rZ)
{
	rX = X;
	rY = size;
	rZ = Z;
}

void Star::SetMyPos(GLfloat x, GLfloat z){
	X = x;
	Z = z;

}

