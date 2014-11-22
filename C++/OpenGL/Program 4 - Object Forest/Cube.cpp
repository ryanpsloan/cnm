//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>
#include "Cube.h"

using namespace std;

Cube::Cube()
{
	r = (rand() % 100) / 100.0f;
	g = (rand() % 100) / 100.0f;
	b = (rand() % 100) / 100.0f;

	xpos = (float) (rand() % 201) - 100;
	ypos = (float) (rand() % 201) - 100;
	zpos = (float) (rand() % 201) - 100;
	
	size = (float) (rand() % 15) + 5;

	if(xpos + size/2 > 100){ 
		xpos = 98 - size/2;} 
	if(xpos - size/2 < - 100){ 
		xpos = -98 + size/2;}
	if(ypos + size/2 > 100) { 
		ypos = 98 - size/2;}
	if(ypos - size/2 < -100){ 
		ypos = -98 + size/2;}
	if(zpos + size/2 > 100) { 
		zpos = 98 - size/2;}
	if(zpos - size/2 < -100){ 
		zpos = -98 + size/2;}
}	

void Cube::DrawMe()
{
	glPushMatrix();
	glColor3f(r, g, b);
	glTranslatef(xpos, ypos, zpos);
	glutSolidCube(size);
	glPopMatrix();
}