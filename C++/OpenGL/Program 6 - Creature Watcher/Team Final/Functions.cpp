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
#include "Snowman.h"
#include "AngelStar.h"
#include "AngelParticleEngine.h"
#include "Fire.h"


extern GLfloat eyeX, eyeY, eyeZ;
extern GLint azimuth, elevation, radius;

extern GLuint txParticle;
extern GLuint txPlane;

extern AngelStar shinningStar;
extern Star starMaker;
extern Star fireBall;
extern GLfloat starX, starY, starZ;
extern GLUquadricObj *O;
extern Space layout;
extern Snow snow;

extern tAxis axis;
extern tAxis fireAxis;

float distance, laserd, headangle, bodyangle;

Snowman snowman;
//menu vars
GLuint index;
bool kdstar = false;
bool kdlaser = false;
bool kdlights = true;
bool kdfloor = false;
bool kdaxes = false;
bool kdfire = false;
bool kdfireball = false;
bool kdsnow = false;
bool kdangel = true;
enum{
	mlaseron,
	mlaseroff,
	mlightson, 
	mlightsoff, 
	mflooron, 
	mflooroff, 
	maxeson, 
	maxesoff, 
	mfireon, 
	mfireoff, 
	mfirebon, 
	mfireboff, 
	msnowon,
	msnowoff
};



// Lighting values
GLfloat  whiteLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat  sourceLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat	 lightPos[] = { starX, starY, starZ, 1.0f };
GLfloat  sunPos[] =  {0.0f, 22.2f, -33.3f, 1.0};
GLfloat  sunPos2[] = {0.0f, 22.2f, 33.3f, 1.0};
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

	glPushMatrix();
	if(kdfloor){
		layout.DrawSpace();
	}
	if(kdaxes) {
		axis.SetDistance(11.11f);
		axis.HideTicks();
		axis.SetAxisColor(X_AXIS, 1.0f, 0.777f, 0.0f);
		axis.SetAxisColor(Y_AXIS, 1.0f, 0.777f, 0.0f);
		axis.SetAxisColor(Z_AXIS, 1.0f, 0.777f, 0.0f);
		axis.Draw();
	}
	if(kdstar){			
		starMaker.GetMyPos(starX, starY, starZ);
		starMaker.RenderStar(starX, starY, starZ);
		
		calc();
	}
	if(kdangel){
		shinningStar.RenderStar(0.0f, 35.0f, 0.0f);
	}
	glPopMatrix();
	glPushMatrix();
	if(kdfireball && distance<20)
		snowman.DrawPuddle();
	else {
		if(bodyangle>0)
		{
			glRotatef(bodyangle-45, 0.0, 1.0, 0.0);
		}
		else
		{
			glRotatef((bodyangle-180)-45, 0.0, 1.0, 0.0);
		}
		if(starX < 0.0f)
		{
			glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
		}
		snowman.DrawBody();
		snowman.DrawFace();
		//glCallList(index);
		//glCallList(index+1);
		glCallList(index+2);
		glCallList(index+3);
		glPopMatrix();
	}	
	
	if(kdsnow){
		snow.LetItSnow();
	}
	
	glutSwapBuffers();
}



// This function does any needed initialization on the rendering
// context. 
void SetupRC()
{
	
	starMaker.SetMyPos(starX,starZ);
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
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, 25.0);

	// Enable lighting
	glEnable(GL_LIGHTING);

	// Setup and enable light 0
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, sourceLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, sourceLight);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);
	
	glLightfv(GL_LIGHT1, GL_DIFFUSE, sourceLight);
	glLightfv(GL_LIGHT1, GL_POSITION, sunPos);
	glEnable(GL_LIGHT1);
	
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, sourceLight);
	glLightfv(GL_LIGHT2, GL_POSITION, sunPos2); 
	glEnable(GL_LIGHT2);
	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	
	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// Enable textures and bind our particle texture
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txParticle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // Linear Min Filter
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	// Enable blending
	//glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_COLOR,GL_ONE);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);           
	glHint(GL_POINT_SMOOTH_HINT,GL_NICEST); 

	gluQuadricOrientation(O, GLU_INSIDE); 
	gluQuadricDrawStyle(O, GLU_LINE);      
	gluQuadricNormals(O, GLU_FLAT);
	gluQuadricTexture(O, GL_TRUE);

	setupLists();
    }


void TimerFunc(int value)
{	
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
	
	if(key == 'a')      //rotate left
	{
		starMaker.RotateLocalY(4.0);
		
	}
	if(key == 's') //back up teapot
	{
		starMaker.BackMove(2.0);
		
	}
	if(key == 'd') //rotate right
	{
		starMaker.RotateLocalY(-4.0);
		
	}
	if(key == 'w') //move forward
	{
		starMaker.FowardMove(2.0);
		
	}

}

void setupMenu()
{
	GLint laserSubMenu = glutCreateMenu(SelectFromMenu);
	glutAddMenuEntry ("on", mlaseron);
	glutAddMenuEntry ("off", mlaseroff);
	GLint lightsSubMenu = glutCreateMenu(SelectFromMenu);
	glutAddMenuEntry ("on", mlightson);
	glutAddMenuEntry ("off", mlightsoff);		
	GLint floorSubMenu = glutCreateMenu(SelectFromMenu);
	glutAddMenuEntry ("on", mflooron);
	glutAddMenuEntry ("off", mflooroff);
	GLint axesSubMenu = glutCreateMenu(SelectFromMenu);
	glutAddMenuEntry ("on", maxeson);
	glutAddMenuEntry ("off", maxesoff);	
	GLint fireSubMenu = glutCreateMenu(SelectFromMenu);
	glutAddMenuEntry ("on", mfireon);
	glutAddMenuEntry ("off", mfireoff);	
	GLint firebSubMenu = glutCreateMenu(SelectFromMenu);
	glutAddMenuEntry ("on", mfirebon);
	glutAddMenuEntry ("off", mfireboff);
	GLint snowSubMenu = glutCreateMenu(SelectFromMenu);
	glutAddMenuEntry ("on", msnowon);
	glutAddMenuEntry ("off", msnowoff);
	
	GLint objectSubMenu = glutCreateMenu(SelectFromMenu);
	glutAddSubMenu("Laser Eyes", laserSubMenu);
	glutAddSubMenu("Lights", lightsSubMenu);
	glutAddSubMenu("Floor", floorSubMenu);
	glutAddSubMenu("Axes", axesSubMenu); 
	glutAddSubMenu("Fire", fireSubMenu); 
	glutAddSubMenu("Fire Ball", firebSubMenu);
	glutAddSubMenu("Snow", snowSubMenu);
  
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  
}

 void SelectFromMenu(int idCommand)
 {
	  switch (idCommand)
    {
	  case mlaseron:
			kdlaser = true;
			break;
	  case mlaseroff:
			kdlaser = false;
			break;
	  case mlightson:
		  glEnable(GL_LIGHTING);
		  break;
	  case mlightsoff:
		  glDisable(GL_LIGHTING);
		  break;
	  case mflooron:
		  kdfloor = true;
		  break;
	  case mflooroff:
		  kdfloor = false;
		  break;
	  case maxeson:
		  kdaxes = true;
		  break;
	  case maxesoff:
		  kdaxes = false;
		  break;
	  case mfireon:
		  kdfire = true;
		  break;
	  case mfireoff:
		  kdfire = false;
		  break;
	  case mfirebon:
		  kdfireball = true;
		  break;
	  case mfireboff:
		  kdfireball = false;
		  break;
	  case msnowon:
		  kdsnow = true;
		  break;
	  case msnowoff:
		  kdsnow = false;
		  break;
	  
	}


 }

 void setupLists()
 {

	 index = glGenLists(4);//create 2 display lists
	 glNewList(index, GL_COMPILE);
	 snowman.DrawBody();
	 glEndList();

	  glNewList(index+1, GL_COMPILE);
	 snowman.DrawFace();	
	 glEndList();

	  glNewList(index+2, GL_COMPILE);
	 snowman.DrawButtons();
	 glEndList();

	 glNewList(index+3, GL_COMPILE);
	 snowman.DrawArms();
	  glEndList();

 }

 void calc()
{
	distance = sqrt(pow(starX, 2) + pow(starZ, 2));
	laserd = sqrt(pow(distance, 2) + pow(starY, 2));
	headangle = ((PI/2) - (atan (distance/starY))) *180/PI;
	bodyangle = ((atan(starX/starZ)) *180/PI);
	
}


