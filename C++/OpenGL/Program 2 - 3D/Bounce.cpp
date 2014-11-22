//Bounce.cpp
//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
//this to avoid the black console window
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

#include <iostream>
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>		// Glut (Free-Glut on Windows)

#include "Bounce.h"         

using namespace std;
// Initial square position and size
extern GLfloat x;
extern GLfloat y;
extern GLfloat rsize;

// Step size in x and y directions
// (number of pixels to move each time)
extern GLfloat xstep;
extern GLfloat ystep;

// Keep track of windows changing width and height
extern GLfloat windowWidth;
extern GLfloat windowHeight;

extern GLfloat sizeOfTeapot;//used in renderscene
extern GLint cycle;//used in changeClipping
extern GLboolean On; //used in changeViewport
extern GLint width, height;//used to keep track of w and h globally

extern GLfloat colorsR[];
extern GLfloat colorsG[];
extern GLfloat colorsB[];
extern GLfloat speeds[] ;//used in ChangeColorOrSpeed

extern GLint indeXA;//used for color array
extern GLint indeXB;//used for speed array


extern GLfloat eyex, eyey, eyez;
extern GLint azimuth, elevation, radius;

extern GLboolean enableDT;
extern GLboolean changeTeapot;
///////////////////////////////////////////////////////////
// Called to draw scene
void RenderScene(void)
{
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	CalculateEye();
	gluLookAt(eyex, eyey, eyez, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//Draw Grey rectangle at +/-200
	glColor3f(0.50, 0.50, 0.50);
	glRectf(-200.0, 200.0, 200.0, -200.0);
	//Draw white rectangle at +/-100
   	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(-100.0, 100.0, 100.0, -100.0);
	//Set drawing color
	//	       R      G     B
	glColor3f(1.0f, 0.5f, 0.0f);
	//draws a orange teapot
	if(changeTeapot)
	{
		glutWireTeapot(sizeOfTeapot);
		
	}
	else
	{
		glutSolidTeapot(sizeOfTeapot);
	}
    //set drawing color to black
	glColor3f(0.0f, 0.0f, 0.0f);
	//draw axis and tickmarks
	glLineWidth(1.5); 
	
	glBegin(GL_LINES);
	//x and y axis
	
		glVertex3f(0.0, 200.0, 0.0);
		glVertex3f(0.0, -200.0, 0.0);
		glVertex3f(200.0, 0.0, 0.0);
		glVertex3f(-200.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 200.0);
		glVertex3f(0.0, 0.0, -200.0);
	
	//tick marks
		glLineWidth(1.0);
		GLfloat xpos = 25.0f;
		//+x
		for(int i = 0; i < 7; ++i)
		{
			glVertex2f(xpos, 3.0);
			glVertex2f(xpos,-3.0);
			xpos += 25.0;
		}
		//-x
		xpos = -25.0;
		for (int i = 0; i < 7; ++i)
		{
			glVertex2f(xpos,  3.0);
			glVertex2f(xpos, -3.0);
			xpos += -25.0;
		}
				
		//+y
		GLfloat ypos = 25.0f;
		for(int i = 0; i < 7; ++i)
		{
			glVertex2f( 3.0, ypos);
			glVertex2f(-3.0, ypos);
			ypos += 25.0;
		}
				
		//-y
		ypos = -25.0;
		for(int i = 0; i < 7; ++i)
		{
			glVertex2f( 3.0, ypos);
			glVertex2f(-3.0, ypos);
			ypos += -25.0;
		}
		
		//+z
		GLfloat zpos = 25.0;
		for(int i = 0; i < 7; ++i)
		{
			glVertex3f(0.0, 3.0, zpos);
			glVertex3f(0.0, -3.0, zpos);
			zpos += 25.0;
		}

		//-z

		zpos = -25.0;
		for(int i = 0; i < 7; ++i)
		{
			glVertex3f(0.0, 3.0, zpos);
			glVertex3f(0.0, -3.0, zpos);
			zpos += -25.0;
		}


	glEnd();
	
	
	// Set current drawing color to blue
	//		   R	 G	   B
		glColor3f(colorsR[indeXA],colorsG[indeXA],colorsB[indeXA]);

		// Draw a filled rectangle with current color
		glRectf(x, y, x + rsize, y - rsize);
	
	// Flush drawing commands and swap
    glutSwapBuffers();//AAA
}

///////////////////////////////////////////////////////////
// Called by GLUT library when idle (window not being
// resized or moved)
void TimerFunction(int value)
{
	
	//GLfloat windowWidth = 100, windowHeight = 100;
    // Reverse direction when you reach left or right edge
    if(x > windowWidth-rsize || x < -windowWidth)
        xstep = -xstep;

    // Reverse direction when you reach top or bottom edge
    if(y > windowHeight || y < -windowHeight + rsize)
        ystep = -ystep;

	// Actually move the square
    x += xstep;
    y += ystep;

    // Check bounds. This is in case the window is made
    // smaller while the rectangle is bouncing and the 
	// rectangle suddenly finds itself outside the new
    // clipping volume
    if(x > (windowWidth-rsize + xstep))
        x = windowWidth-rsize-1;
	else if(x < -(windowWidth + xstep))
		x = -windowWidth -1;

    if(y > (windowHeight + ystep))
        y = windowHeight-1; 
	else if(y < -(windowHeight - rsize + ystep))
		y = -windowHeight + rsize - 1;
		
	glutMouseFunc(ChangeColorOrSpeed);
	glutKeyboardFunc(ChangeFunction);
	glutSpecialFunc(SpecialKeys);
     // Redraw the scene with new coordinates
    glutPostRedisplay();
    glutTimerFunc(33,TimerFunction, 1);
}


///////////////////////////////////////////////////////////
// Setup the rendering state
void SetupRC(void)
{
    // Set clear color 
    glClearColor(0.48f, 0.24f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}


///////////////////////////////////////////////////////////
// Called by GLUT library when the window has chanaged size
void ChangeSize(int w, int h)
{
	width = w;
	height = h;
    //GLfloat aspectRatio;

    // Prevent a divide by zero
    if(h == 0)
        h = 1;
		
    // Set Viewport to window dimensions
    if(On)
	{
		glViewport(w/4, h/4, w/2, h/2);
		
	}
	else
	{
		glViewport(0, 0, w, h);
		
	}
    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

   	windowWidth = 100;
	windowHeight = 100;
	
	gluPerspective(90.0, 1.0, 1.0, 400.0);//only takes four arguments


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void ChangeColorOrSpeed(GLint button, GLint state, GLint x, GLint y)
{
	
	//indeXA and B are globals
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ){
		++indeXA;
		if (indeXA == 6){
			indeXA = 0;
		}
		
	}
	else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN ){
		
		if(xstep > 0){

			xstep = speeds[indeXB];
		}
		else if (xstep <= 0){
			
			xstep = -speeds[indeXB];
		}
		if (ystep > 0){
			
			ystep = speeds[indeXB];
		}
		else if (ystep <= 0){
			
			ystep = -speeds[indeXB];
		}
		
		indeXB++;
		if(indeXB == 3){
			indeXB = 0;
		}	
	}
}

void ChangeFunction(GLubyte key, GLint x, GLint y)
{
	if(key == 'v'){
		On =!On;
		if(On)	{
			glViewport(width/4, height/4, width/2, height/2);
		}
		else {
			glViewport(0, 0, width, height);
		}
	}
	if(key == 'd'){
		enableDT = !enableDT;
		if(enableDT){
			glEnable(GL_DEPTH_TEST);
		}
		else {
			glDisable(GL_DEPTH_TEST);
		}
	}

	if(key == 'w'){
		changeTeapot = !changeTeapot;
	}
	if(key == 'f'){
		radius -= 3;
		if (radius <= 0)
		{
			radius  = 0;
		}
	}
	if(key == 'b'){
		radius += 3;
		if (radius >= 400)
		{
			radius = 400;
		}
	}
	if(key == ']')
	{
		sizeOfTeapot++;
		if(sizeOfTeapot >= 100){
			sizeOfTeapot = 100;
		}
	}
	if(key == '['){
		sizeOfTeapot--;
		if(sizeOfTeapot <= 1){
			sizeOfTeapot = 1;
		}
	}

}	

void CalculateEye()
{
	GLfloat e = elevation * PI / 180.0;
	GLfloat a = azimuth * PI / 180.0;
	eyex = radius * cos(e);
	eyey = radius * sin(e);
	eyez = eyex * sin(a);
	eyex = eyex * cos(a);
	
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



