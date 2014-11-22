//Ryan Sloan
//SloanP5 - CIS2270
// Solar.cpp
// OpenGL SuperBible, Chapter 5
// Demonstrates OpenGL nested coordinate transformations
// and perspective
// Program by Richard S. Wright Jr.

#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>		// Glut (Free-Glut on Windows)
#include <gl/freeglut.h>
#include <math.h>
#include "Functions.h"
#include "Particle.h"
#include "ParticleEngine.h"
#include "Star.h"
#include "tAxis.h"
#include "Space.h"
#include "Snow.h"
#include "SnowFlake.h"


extern GLboolean lightsOn, flamesOn, fireOn, axesOn, rotationOn, spaceOn, sunOn;
extern GLfloat eyeX, eyeY, eyeZ;
extern GLint azimuth, elevation, radius;

extern GLuint txParticle;
extern GLuint txPlane;

extern Star starMaker;
extern GLfloat starX, starY, starZ;
extern GLUquadricObj *O;
extern Space layout;
extern Snow Snow;
extern GLfloat Rotation;
extern tAxis axis;
extern GLfloat Orbit;

// Lighting values
GLfloat  whiteLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat  sourceLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat	 lightPos[] = { starX, starY, starZ, 1.0f };
GLfloat  sunPos[] = {0.0f, 22.2f, -133.3f, 1.0};
GLfloat  diffuseMaterial[] = {0.5, 0.5, 0.5, 1.0};
GLfloat  specularMaterial[] = {1.0, 1.0, 1.0, 1.0};


// Called to draw scene
void RenderScene(void)
	{
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
	// Save the matrix state and do the rotations
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	CalculateEye();
	gluLookAt(eyeX, eyeY, eyeZ, 0,0,0, 0,1,0);
	Snow.LetItSnow();
	if(sunOn){
		glPushMatrix();
			glRotatef(Orbit, 0.0, 1.0, 0.0);
			glTranslatef(0.0f, 22.2f, -133.3f);
			glRotatef(Orbit, 0.0, 1.0, 0.0);
			glColor3f(1.0f, 1.0f, 1.0f);
			glutSolidSphere(2.222, 444, 444);
		glPopMatrix();
	}
	glPushMatrix();
	if(spaceOn){
		layout.DrawSpace();
	}
	if(axesOn) {
		axis.SetDistance(11.11f);
		axis.HideTicks();
		axis.SetAxisColor(XAXIS, 1.0f, 0.777f, 0.0f);
		axis.SetAxisColor(YAXIS, 1.0f, 0.777f, 0.0f);
		axis.SetAxisColor(ZAXIS, 1.0f, 0.777f, 0.0f);
		axis.Draw();
	}
	
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		layout.DrawSpace();
	glPopMatrix();	
	glPushMatrix();
	
		glRotatef(Rotation, 0.0f, 0.0f, 1.0f);
		glRotatef(Rotation, 1.0f, 0.0f, 0.0f);
		starMaker.CreateStar(starX, starY, starZ);	
		
	glPopMatrix();
	glPushMatrix();
		if(fireOn)
		{
			if(rotationOn) {
				glRotatef(Rotation, 0.0f, 0.0f, 1.0f);
			}
			starMaker.FireRender();
		}
	glPopMatrix();
	
	glutSwapBuffers();
}


// This function does any needed initialization on the rendering
// context. 
void SetupRC()
{
	glShadeModel(GL_SMOOTH);                    // Enables Smooth Shading
	glClearDepth(1.0f);                         // Depth Buffer Setup
		
	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	// Light values and coordinates
	glEnable(GL_DEPTH_TEST);	// Hidden surface removal
	glDepthFunc(GL_LEQUAL);	
	//glFrontFace(GL_CCW);		// counter clock-wise polygons face out
	//glEnable(GL_CULL_FACE);		// Do not calculate inside
	// Enable Material
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularMaterial);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 25.0);

	// Enable lighting
	glEnable(GL_LIGHTING);

	// Setup and enable light 0
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, sourceLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, sourceLight);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);
	
	glLightfv(GL_LIGHT1, GL_DIFFUSE, sourceLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, sourceLight);
	glLightfv(GL_LIGHT1, GL_POSITION, sunPos);
	glEnable(GL_LIGHT1);
	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	
	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	// Enable textures and bind our particle texture
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txParticle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // Linear Min Filter
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	// Enable blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_COLOR,GL_ONE);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);           
	glHint(GL_POINT_SMOOTH_HINT,GL_NICEST); 

	gluQuadricOrientation(O, GLU_INSIDE); 
	gluQuadricDrawStyle(O, GLU_LINE);      
	gluQuadricNormals(O, GLU_FLAT);
	gluQuadricTexture(O, GL_TRUE);

    }


void TimerFunc(int value)
{	
	Rotation += 2.0f;
	Orbit += 23.0f;
	if(Rotation >= 360.0f){
		Rotation = 0.0f;
	}
    glutPostRedisplay();
    glutTimerFunc(100, TimerFunc, 1);
}



void ChangeSize(int w, int h)
	{
	GLfloat fAspect;

	// Prevent a divide by zero
	if(h == 0)
		h = 1;

	// Set Viewport to window dimensions
    glViewport(0, 0, w, h);

	// Calculate aspect ratio of the window
	fAspect = (GLfloat)w/(GLfloat)h;

	// Set the perspective coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// field of view of 45 degrees, near and far planes 1.0 and 425
	gluPerspective(45.0f, fAspect, 1.0, 425.0);

	// Modelview matrix reset
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void CalculateEye()
{
	GLfloat e = elevation * PI / 180.0f;
	GLfloat a = azimuth * PI / 180.0f;
	eyeX = radius * cos(e);
	eyeY = radius * sin(e);
	eyeZ = eyeX * sin(a);
	eyeX = eyeX * cos(a);
	
}

void SpecialKeys(int key, int x, int y)
{
	if(key == GLUT_KEY_UP){
		elevation -= 3;
	}
	if(key == GLUT_KEY_DOWN){
		elevation += 3;
	}
	if(key == GLUT_KEY_RIGHT){
		azimuth += 3;
	}if(key == GLUT_KEY_LEFT){
		azimuth -= 3;
	}
	
}

void ChangeFunction(GLubyte key, GLint x, GLint y)
{
	if(key == 'f'){
		radius -= 3;
	}
	if(key == 'b'){
		radius += 3;
	}
	if(key == 'y'){
		fireOn = !fireOn;
	}
	if(key == 'j'){
		rotationOn = !rotationOn;
	}
	if(key == 'n'){
		flamesOn = !flamesOn;
	}
	if(key == 'b'){
		spaceOn = !spaceOn;
	}
	if(key == 'g'){
		axesOn = !axesOn;
	}
	if(key == 'h'){
		sunOn = !sunOn;
	}
}


