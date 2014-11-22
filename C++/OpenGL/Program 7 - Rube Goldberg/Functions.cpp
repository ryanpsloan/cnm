//Ryan Sloan
//SloanP7 - CIS2270


#include <windows.h>		// Must have for Windows platform builds
#include <gl/freeglut.h>
#include <math.h>
#include "Functions.h"
#include "tAxis.h"
#include "Component.h"

//-------------------------- Ryan Sloans Classes
	//-- derived from flamethrower
#include "sloanFire.h"
	//-- Draw Flamethrower
#include "sloanFlameThrower.h"
	//-- Draw Ice Cube
#include "sloanIceCube.h"
	//-- Create the particles
#include "sloanParticle.h"
	//-- put particles together and create form
#include "sloanParticleEngine.h"

//-------------------------- Bresdin O'Malley's Classes
	//-- draw bumblebee (uses texture mapping)
#include "bomBumbleBee.h"
	//-- Draw coconut
#include "bomCoconut.h"
	//-- Draw flower
#include "bomFlower.h"
	//-- Draw Tree
#include "bomTree.h"
	//-- Draw Landscape and sky
#include "bomSkyCube.h"

using namespace std;

extern GLfloat eyeX, eyeY, eyeZ;
extern GLint azimuth, elevation, radius;

// -- Ryans Objects
extern FlameThrower fire;
extern IceCube ice;

// -- Bresdins Objs
extern BumbleBee bee;
extern Coconut coco;
extern Flower flow;
extern Tree palmtree;
extern SkyBox sandybeach;

extern Component * puzzle[8];
extern tAxis axis;
extern GLboolean startMachine, reset;
extern GLboolean planeOn, axesOn;

enum{ START, RESET, PLANE, AXES, LIGHTS_ON, LIGHTS_OFF};

//Lighting values
GLfloat  whiteLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat  sourceLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat	 lightPos[] = { 0.0f, 50.0f, 0.0f, 1.0f};
GLfloat  sunPos[] =  {0.0f, 50.0f, -33.3f, 1.0};
GLfloat  sunPos2[] = {0.0f, 50.2f, 33.3f, 1.0};
GLfloat  diffuseMaterial[] = {0.5, 0.5, 0.5, 1.0};
GLfloat  specularMaterial[] = {1.0, 1.0, 1.0, 1.0};

#define MAX_COMPONENTS 2


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
	if(axesOn){

		//This will draw the axis if menu option axes is on
		axis.SetDistance(60.0f);
		axis.ShowLabel();
		axis.SetAxisColor(1.0f, 1.0f, 1.0f);
		axis.Draw();
	}
	if(planeOn){

		//This will draw the landscape if menu plane option is on
		sandybeach.DrawScene();

	}
	
	if(startMachine){
		startMachine = false;
		for( int h = 0; h < MAX_COMPONENTS; ++h){
			puzzle[h]->SetRunning(true); //FT gets set to runnin //IC gets set to running
		}									// in order for it to work both have to be 
	}									//running at the same time
	

	for (int j = 0; j < MAX_COMPONENTS; ++j){
		
		if(puzzle[j]->isTimeToStartNext()) //checks bStartMext
			if(j + 1 < MAX_COMPONENTS) {
				puzzle[j + 1]->SetRunning(true); //if true sets next component to running
			}
	}

	for (int k = 0; k < MAX_COMPONENTS; ++k){
		puzzle[k]->Draw();
	}	
	
	if(reset)
	{
		for(int l = 0; l < 2; ++l){
			puzzle[l]->Reset();
		}
	}

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
	
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, sourceLight);
	glLightfv(GL_LIGHT2, GL_SPECULAR, sourceLight);
	glLightfv(GL_LIGHT2, GL_POSITION, sunPos2); 
	glEnable(GL_LIGHT2);
	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	
	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	
	// -------------------------- ORDER 
		//1 - tree
		//2 - coconut
		//3 - Fire
		//4 - ice cube
		//5 - flower
		//6 - bee
		//7 - tom hanks
		//8 - lantern
	// ---------------------------

	puzzle[0] = &palmtree;
	puzzle[0]->Setup();
	puzzle[0]->SetStartPos(-100, 9, -40);

	puzzle[1] = &coco;
	puzzle[1]->Setup();
	puzzle[1]->SetStartPos(-100, 100, -20);

	puzzle[2] = &fire;
	puzzle[2]->Setup();
	puzzle[2]->SetStartPos(-80, 9, 40);

	puzzle[3] = &ice;
	puzzle[3]->Setup();
	puzzle[3]->SetStartPos(-60, 9, 60);

	puzzle[4] = &flow;
	puzzle[4]->Setup();
	puzzle[4]->SetStartPos(-60, 9, 100);

	puzzle[5] = &bee;
	puzzle[5]->Setup();
	puzzle[5]->SetStartPos(0, 100, 0);
	

	//-- Tom hanks and lantern last
}	
	
void TimerFunc(int value)
{	
	for(int m = 0; m < MAX_COMPONENTS; m++){
		if(puzzle[m]->isRunning()){
			puzzle[m]->Update();
		}
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
	if(key == 'r'){
		startMachine = true;
		
	}
}

void setupMenu()
{

	GLint subMenu = glutCreateMenu(SelectFromMenu);
	glutAddMenuEntry ("START", START);
	glutAddMenuEntry ("RESET", RESET);
		
	GLint objectSubMenu = glutCreateMenu(SelectFromMenu);
	glutAddMenuEntry ("PLANE", PLANE);
	glutAddMenuEntry ("AXES", AXES);
	
	GLint lightsSubMenu = glutCreateMenu(SelectFromMenu);
	glutAddMenuEntry("ON", LIGHTS_ON);
	glutAddMenuEntry("OFF", LIGHTS_OFF);

	GLint mainMenu = glutCreateMenu(SelectFromMenu);
	glutAddSubMenu("SUBMENU", subMenu);
	glutAddSubMenu("OBJECTS", objectSubMenu);
	glutAddSubMenu("LIGHTS", lightsSubMenu);
  
	glutAttachMenu(GLUT_RIGHT_BUTTON);
  
}

 void SelectFromMenu(int idCommand)
 {
	switch (idCommand)
	{
	case 1: //Start
		startMachine = true;
		break;
	case 2: //Reset
		reset = !reset;
		break;
	case 3: //Plane
		planeOn = !planeOn;
		break;
	case 4: //Axes
		axesOn = !axesOn;
		break;
	case 5: //Lights off
		glDisable(GL_LIGHTING);
		break;
	case 6: //Lights on 	
		glEnable(GL_LIGHTING);
		break;
	}


 }






