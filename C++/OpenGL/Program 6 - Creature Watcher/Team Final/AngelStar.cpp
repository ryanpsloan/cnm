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
#include "tAxis.h"
#include "AngelStar.h"
#include "AngelParticleEngine.h"

extern GLUquadricObj *O;
extern tAxis fireAxis;
extern bool kdaxes, kdfire;
GLfloat Rotation = 10.0f;


AngelStar::AngelStar(){ 

	O = gluNewQuadric();
	
}

AngelStar::~AngelStar(){
	gluDeleteQuadric(O);
	
}

void AngelStar::RenderStar(GLfloat Declination, GLfloat RightAscension, GLfloat DistanceAway){
	glDisable(GL_DEPTH_TEST);
		
	glPushMatrix();
	glTranslatef(Declination, RightAscension, DistanceAway);
		if(kdaxes){
			fireAxis.SetDistance(12.0);
			fireAxis.HideTicks();
			fireAxis.SetAxisColor(X_AXIS, 1.0f, 0.777f, 0.0f);
			fireAxis.SetAxisColor(Y_AXIS, 1.0f, 0.777f, 0.0f);
			fireAxis.SetAxisColor(Z_AXIS, 1.0f, 0.777f, 0.0f);
			fireAxis.Draw();
		}
		
		glColor3f(1.0, 0.777, 0.0f);
		gluSphere(O, 0.555f, 555, 555);
		if(kdfire){
		fire.Pos();
		fire.Neg();
		fire.Neu();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		fire.Pos();
		fire.Neg();
		fire.Neu();
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		fire.Pos();
		fire.Neg();
		fire.Neu();
		
		
			particleEngine.SunFire();//0
			glRotatef(Rotation, 0.0f, 0.0f, 1.0f);
			particleEngine01.SunFire();//1
			glRotatef(-Rotation, 0.0f, 1.0f, 0.0f);
			particleEngine02.SunFire();//2
			glRotatef(Rotation, 1.0f, 0.0f, 0.0f);
			particleEngine03.SunFire();//3
			glRotatef(-Rotation, 0.0f, 1.0f, 0.0f);
			particleEngine04.SunFire();//4
			glRotatef(Rotation, 0.0f, 0.0f, 1.0f);
			particleEngine05.SunFire();//5
			glRotatef(-Rotation, 0.0f, 1.0f, 0.0f);
			particleEngine06.SunFire();//6
			glRotatef(Rotation, 1.0f, 0.0f, 0.0f);
			particleEngine07.SunFire();//7
			glRotatef(-Rotation, 0.0f, 1.0f, 0.0f);
			particleEngine08.SunFire();//8
			glRotatef(Rotation, 0.0f, 0.0f, 1.0f);
			particleEngine09.SunFire();//9
			glRotatef(-Rotation, 0.0f, 1.0f, 0.0f);
			particleEngine10.SunFire();//10
			glRotatef(Rotation, 1.0f, 0.0f, 0.0f);
			particleEngine11.SunFire();//11
			glRotatef(-Rotation, 0.0f, 1.0f, 0.0f);
			particleEngine12.SunFire();//12
			glRotatef(Rotation, 0.0f, 0.0f, 1.0f);
			particleEngine13.SunFire();//13
			glRotatef(-Rotation, 0.0f, 1.0f, 0.0f);
			particleEngine14.SunFire();//14
			glRotatef(Rotation, 1.0f, 0.0f, 0.0f);
			particleEngine15.SunFire();//15
			glRotatef(-Rotation, 0.0f, 1.0f, 0.0f);
			particleEngine16.SunFire();//16
			glRotatef(Rotation, 0.0f, 0.0f, 1.0f);
			particleEngine17.SunFire();//17
			glRotatef(-Rotation, 0.0f, 1.0f, 0.0f);
			particleEngine18.SunFire();//18
			glRotatef(Rotation, 1.0f, 0.0f, 0.0f);
			particleEngine19.SunFire();//19
			glRotatef(-Rotation, 0.0f, 1.0f, 0.0f);
			particleEngine20.SunFire();//20
			glRotatef(Rotation, 0.0f, 0.0f, 1.0f);
			particleEngine21.SunFire();//21
			glRotatef(-Rotation, 0.0f, 1.0f, 0.0f);
			particleEngine22.SunFire();//22
			glRotatef(Rotation, 1.0f, 0.0f, 0.0f);
			particleEngine23.SunFire();//23
			glRotatef(-Rotation, 0.0f, 1.0f, 0.0f);
			particleEngine24.SunFire();//24
			glRotatef(Rotation, 0.0f, 0.0f, 1.0f);
			particleEngine25.SunFire();//25
			glRotatef(-Rotation, 0.0f, 1.0f, 0.0f);
			particleEngine26.SunFire();//26
			glRotatef(Rotation, 1.0f, 0.0f, 0.0f);
			particleEngine27.SunFire();//27
			glRotatef(-Rotation, 0.0f, 1.0f, 0.0f);
			particleEngine28.SunFire();//28
			glRotatef(Rotation, 0.0f, 0.0f, 1.0f);
			particleEngine29.SunFire();//29
			glRotatef(-Rotation, 0.0f, 1.0f, 0.0f);
			particleEngine30.SunFire();//30
			glRotatef(Rotation, 1.0f, 0.0f, 0.0f);
			particleEngine31.SunFire();//31
			glRotatef(-Rotation, 0.0f, 1.0f, 0.0f);
			particleEngine32.SunFire();//32
			glRotatef(Rotation, 0.0f, 0.0f, 1.0f);
			particleEngine33.SunFire();//33
			
	}
	glPopMatrix();
	
	glEnable(GL_DEPTH_TEST);
	
}

