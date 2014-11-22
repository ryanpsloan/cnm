
//Ryan Sloan
//SloanP5 - CIS2270
// Solar.cpp
// OpenGL SuperBible, Chapter 5
// Demonstrates OpenGL nested coordinate transformations
// and perspective
// Program by Richard S. Wright Jr.

#include <windows.h>
#include <gl/freeglut.h>
#include <math.h>
#include "Solar.h"
#include "tAxis.h"

extern GLboolean objAxesOn;
extern GLboolean worldAxesOn;
extern GLboolean lightsOn;
extern GLfloat eyeX, eyeY, eyeZ;
extern GLint azimuth, elevation, radius;
extern GLint speed;
extern tAxis axis;
extern GLfloat angle;


// Lighting values
GLfloat  whiteLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat  sourceLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat	 lightPos[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat  diffuseMaterial[] = {0.5, 0.5, 0.5, 1.0};
GLfloat  specularMaterial[] = {1.0, 1.0, 1.0, 1.0};

// Called to draw scene
void RenderScene(void)
	{
	// Earth and Moon angle of revolution
	static float fMoonRot = 0.0f;
	static float fEarthRot = 0.0f;
	static float fCubeRot = 0.0f;
	static float fNearMoonRot = 0.0f;
	static float fFarMoonRot = 0.0f;
	static float fPlanetRot = 0.0f;

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Save the matrix state and do the rotations
	glMatrixMode(GL_MODELVIEW);
	

	// Set light position before viewing transformation
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	// Translate the whole scene out and into view	
	glTranslatef(0.0f, 0.0f, -300.0f);	
	
	glLoadIdentity();
	CalculateEye();
	gluLookAt(eyeX, eyeY, eyeZ, 0, 0, 0, 0, 1, 0);
	glDisable(GL_LIGHTING);
	
	//Draw Axes	
	if(worldAxesOn){
		axis.SetDistance(100.0);
		axis.HideTicks();
		axis.SetAxisColor(XAXIS, 1.0f, 0.0f, 0.0f);
		axis.SetAxisColor(YAXIS, 0.0f, 1.0f, 0.0f);
		axis.SetAxisColor(ZAXIS, 0.0f, 0.0f, 1.0f);
		axis.Draw();
	}
	// Set material color, Yellow
	// Draw the Sun
	drawSun();
	
	// Move the light after we draw the sun!
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
	glEnable(GL_LIGHTING);

	glPushMatrix();//0
	// Rotate coordinate system
		glPushMatrix();//1
			glRotatef(fEarthRot, 0.0f, 1.0f, 0.0f); //rotating from origin coordinates
			glTranslatef(50.0f, 0.0f, 0.0f); // move to earth coordinates
			glRotatef(fEarthRot, 0.0f, 1.0f, 0.0);
	// Draw the Earth
			drawEarth();
			fEarthRot += angle;
			if(fEarthRot > 360.0f)
				fEarthRot = 0.0f;
	// Rotate from Earth based coordinates and draw Moon
			glRotatef(fMoonRot,0.0f, 1.0f, 0.0f); // rotate
			glTranslatef(30.0f, 0.0f, 0.0f); //translate from earth coordinates
			drawMoon();
			fMoonRot+= angle;
			if(fMoonRot > 360.0f)
			fMoonRot = 0.0f;
		glPopMatrix();//1 // back to origin coordinates

		glPushMatrix();//2
			glRotatef(fCubeRot, 0.0f, 1.0f, 0.0f);
			glTranslatef(0.0f, 0.0f, 85.0f); //move to cube coordinates
			drawCube();
			fCubeRot += angle;
			if(fCubeRot > 360.0f)
				fCubeRot = 0.0f;
	
			glPushMatrix(); //3
				glRotatef(fNearMoonRot, 0.0f, 1.0f, 0.0f);
				glTranslatef(0.0f, 0.0f, 25.0f); // move from cube coordinates to near moon coordinates
				glRotatef(fNearMoonRot, 0.0, 1.0, 0.0);
				drawCubeNearMoon();
				fNearMoonRot+= angle;//cylinder
				if(fNearMoonRot > 360.0f)
					fNearMoonRot = 0.0f;
			glPopMatrix(); //3 //back to cube coordinates
	
			glPushMatrix();//4 
				glRotatef(fFarMoonRot, 1.0f, 0.0f, 0.0f);
				glTranslatef(0.0f, 0.0f, 35.0f); // move to far moon coordinates
				glRotatef(fFarMoonRot, 0.0f, 1.0f, 0.0f);
				drawCubeFarMoon();
				fFarMoonRot += angle; //cone
				if(fFarMoonRot > 360.0f)
					fFarMoonRot = 0.0f;
			glPopMatrix();//4
		glPopMatrix();//2 back to origin coordinates
	
		glPushMatrix();//5
			glRotatef(fPlanetRot, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 95.0f, 0.0f); // move to third planet coordinates
			glRotatef(fPlanetRot, 1.0f, 0.0f, 0.0f);
			drawPlanet();
			fPlanetRot += angle;
			if(fPlanetRot > 360.0f)
				fPlanetRot = 0.0f;
		glPopMatrix(); //5	// Modelview matrix 
	glPopMatrix(); //0 // restore to origin coordinates

	
	glMatrixMode(GL_PROJECTION);
	// Show the image
	glutSwapBuffers();
	}


// This function does any needed initialization on the rendering
// context. 
void SetupRC()
{	
	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
	glShadeModel(GL_SMOOTH);
	// Light values and coordinates
	glEnable(GL_DEPTH_TEST);	// Hidden surface removal
	glFrontFace(GL_CCW);		// Counter clock-wise polygons face out
	glEnable(GL_CULL_FACE);		// Do not calculate inside
	// Enable Material
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR,specularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, 25.0);

	// Enable lighting
	glEnable(GL_LIGHTING);

	// Setup and enable light 0
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, sourceLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, sourceLight);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);
	
	
	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	
	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
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
	gluPerspective(45.0f, fAspect, 1.0, 600.0);

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
		elevation += 3;
		if(elevation >= 89)
		{
			elevation = 89;
		}
		
	}
	if(key == GLUT_KEY_DOWN){
		elevation -= 3;
		if(elevation <= -89)
		{
			elevation = -89;
		}
	}
	if(key == GLUT_KEY_LEFT){
		azimuth += 3;
		if(azimuth >= 359) {
			azimuth = 359;
		}
	}
	if(key == GLUT_KEY_RIGHT){
		azimuth -= 3;
		if(azimuth <= 1){
			azimuth = 1;
		}
	}
}

void SetupMenus()
{
	GLint mainMenu = glutCreateMenu(MenuHandler);
	glutAddMenuEntry("Toggle Lights", TOGGLE_LIGHTS);
	glutAddMenuEntry("Toggle Object Axis", TOGGLE_OBJ_AXIS);
	glutAddMenuEntry("Toggle World Axis", TOGGLE_WORLD_AXIS);
	glutAddMenuEntry("Scene Reset", RESET_SCENE);
	glutAddMenuEntry("Change Speed", CHANGE_SPEED);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void MenuHandler(int menuEntryValue)
{
	switch(menuEntryValue)
	{
	case 101:
		lightsOn = !lightsOn;
		if(lightsOn)
		{
			glEnable(GL_LIGHT0);
		}
		else
		{
			glDisable(GL_LIGHT0);
		}
		break;
	case 102:
		objAxesOn = !objAxesOn;
		break;
	case 103:
		worldAxesOn = !worldAxesOn;
		break;
	case 104:
		azimuth = 90.0f;
		elevation = 0.0f;
		radius = 400.0f;
		break;
	case 105:	
		speed += 1;
		if(speed > 2)
			speed = 0;
		if(speed == 0)
		{
			angle = 5.0f;
		}
		else if(speed == 1)
		{
			angle = 2.0f;
		}
		else if(speed == 2)
		{
			angle = 0.0f;
		}
		break;
	}
}

void ChangeFunction(GLubyte key, GLint x, GLint y)
{
	if(key == 'f'){
		radius -= 3;
		if (radius <= 0)
		{
			radius  = 0;
		}
	}
	if(key == 'b'){
		radius += 3;
		if (radius >= 900)
		{
			radius = 900;
		}
	}
	if(key == 'r'){
		azimuth = 90.0f;
		elevation = 0.0f;
		radius = 400.0f;
	}
}

void drawSun(){
	glColor3ub(255, 255, 0);
	glutSolidSphere(20.0f, 20, 20);
}

void drawEarth(){
	if(objAxesOn)
	{
		axis.SetDistance(25.0);
		axis.HideTicks();
		axis.Draw();
	}
	glColor3ub(0, 0, 255);
	glPushMatrix();
		glScalef(10.0f, 10.0f, 10.0f);
		glRotatef(23.5, 1.0, 0.0, 0.0);
		glutSolidIcosahedron();
	glPopMatrix();
}

void drawMoon(){
	if(objAxesOn)
	{
		axis.SetDistance(15.0);
		axis.HideTicks();
		axis.Draw();
	}
	glColor3ub(200,200,200);
	glutSolidTorus(3.0f, 2.0f, 10, 10);
}

void drawCube(){
	if(objAxesOn)
	{
		axis.SetDistance(25.0);
		axis.HideTicks();
		axis.Draw();
	}
	glBegin(GL_QUADS); //F1 - CCW
		glColor3ub(255,255,255); //white
		glVertex3f(5.0, 5.0, 5.0);   //Front Top Right Corner //V1
		glColor3ub(0,255,0);//green
		glVertex3f(-5.0, 5.0, 5.0);  //Front Top Left Corner //V4
		glColor3ub(255,0,0);//red
		glVertex3f(-5.0,-5.0, 5.0); //Front Bottom Left Corner  //V3
		glColor3ub(255,255,0);//yellow
		glVertex3f(5.0, -5.0, 5.0);  //Front Bottom Right Corner //V2
	glEnd();

	glBegin(GL_QUADS); //F2 - CCW
		glColor3ub(255,255,255);
		glVertex3f(5.0, 5.0, 5.0); //Front Top Right Corner //V1
		glColor3ub(0,0,255);//blue
		glVertex3f(5.0, 5.0, -5.0); // Back Top Right Corner //V5
		glColor3ub(255,0,255);//magenta
		glVertex3f(-5.0, 5.0, -5.0); // Back Top Left Corner //V6
		glColor3ub(0,255,0);
		glVertex3f(-5.0, 5.0, 5.0); // Front Top Left Corner //V4
	glEnd();

	glBegin(GL_QUADS); //A3 - CCW
		glColor3ub(0,0,0);//black
		glVertex3f(-5.0, -5.0, -5.0); //Back Bottom Left Corner //V7
		glColor3ub(255,0,255);
		glVertex3f(-5.0, 5.0, -5.0); //Back Top Left Corner //V6
		glColor3ub(0,0,255);
		glVertex3f(5.0, 5.0, -5.0); //Back Top Right Corner //V5
		glColor3ub(0,255,255);
		glVertex3f(5.0, -5.0, -5.0); //Back Bottom Right Corner //V8
	glEnd();	
		
	
	glBegin(GL_QUADS);//A4 - CCW
		glColor3ub(0,0,0);
		glVertex3f(-5.0, -5.0, -5.0); //Back Bottom Left Corner //V7
		glColor3ub(255,0,0);
		glVertex3f(-5.0, -5.0, 5.0); //Front Bottom Left Corner //V3
		glColor3ub(255,255,0);
		glVertex3f(5.0, -5.0, 5.0); //Front Bottom Right Corner //V2
		glColor3ub(0,255,255);
		glVertex3f(5.0, -5.0, -5.0); //Back Bottom Right Corner//V8
	glEnd();

	glBegin(GL_QUADS); //A5 - CCW
		glColor3ub(0,255,255);
		glVertex3f(5.0, -5.0, -5.0); //Back Bottom Right Corner //V8
		glColor3ub(0,0,255);
		glVertex3f(5.0, 5.0, -5.0); //Back Top Right Corner //V5
		glColor3ub(255,255,255);
		glVertex3f(5.0, 5.0, 5.0); //Front Top Right Corner //V1
		glColor3ub(255,255,0);
		glVertex3f(5.0, -5.0, 5.0); //Front Bottom Right Corner //V2
		
		
	glEnd();

	glBegin(GL_QUADS); //A6 - CCW
		glColor3ub(255,0,255);
		glVertex3f(-5.0, 5.0, -5.0); //Back Top Left Corner //V6
		glColor3ub(0,0,0);
		glVertex3f(-5.0, -5.0, -5.0); //Back Bottom Left Corner //V7
		glColor3ub(255,0,0);
		glVertex3f(-5.0, -5.0, 5.0); //Front Bottom Left Corner //V3
		glColor3ub(0,255,0);
		glVertex3f(-5.0, 5.0, 5.0); //Front Top Left Corner //V4
	glEnd();
}

void drawCubeNearMoon(){
	if(objAxesOn)
	{
		axis.SetDistance(15.0);
		axis.HideTicks();
		axis.Draw();
	}
	glColor3ub(118, 114, 225);
	glutSolidCylinder(6.0f, 9.0f, 9, 9);
}

void drawCubeFarMoon(){
	if(objAxesOn)
	{
		axis.SetDistance(15.0f);
		axis.HideTicks();
		axis.Draw();
	}
	glColor3ub(25, 156, 200);
	glutSolidCone(7.0f, 7.0f, 7, 7);
}	

void drawPlanet(){
	if(objAxesOn)
	{
		axis.SetDistance(25.0);
		axis.HideTicks();
		axis.Draw();
	}
	glPushMatrix();
		glScalef(12.0f, 18.0f, 12.0f);
		
		glPushMatrix();
			glColor3ub(255,0,0);
			glutSolidOctahedron();
		glPopMatrix();
	
		glPushMatrix();
			glColor3ub(0,255,0);
			glRotatef(45.0,1.0,0.0,0.0);
			glutSolidOctahedron();
		glPopMatrix();

		glPushMatrix();
			glColor3ub(0,0,255);
			glRotatef(45.0,0.0,1.0,0.0);
			glutSolidOctahedron();
		glPopMatrix();

		glPushMatrix();
			glColor3ub(255,255,0);
			glRotatef(45.0,0.0,0.0,1.0);
			glutSolidOctahedron();
		glPopMatrix();

		glPushMatrix();
			glColor3ub(75,147,255);
			glRotatef(45.0,0.0,0.0,1.0);
			glutSolidTetrahedron();
		glPopMatrix();

		glPushMatrix();
			glColor3ub(147,255,75);
			glRotatef(45.0,1.0,0.0,0.0);
			glutSolidTetrahedron();
		glPopMatrix();

		glPushMatrix();
			glColor3ub(255,75,147);
			glRotatef(45.0,0.0,1.0,0.0);
			glutSolidTetrahedron();
		glPopMatrix();

		glPushMatrix();
			glColor3ub(75,147,255);
			glRotatef(45.0,0.0,0.0,1.0);
			glutSolidTetrahedron();
		glPopMatrix();

	glPopMatrix();
}