//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>
#include "Tetrahedron.h"

using namespace std;

Tetrahedron::Tetrahedron()
{
	r = (rand() % 100) / 100.0f;
	g = (rand() % 100) / 100.0f;
	b = (rand() % 100) / 100.0f;

	xpos = (float) (rand() % 201) - 100;
	ypos = (float) (rand() % 201) - 100;
	zpos = (float) (rand() % 201) - 100;

	sizex = (float) (rand() % 15) + 5;
	sizey = (float) (rand() % 15) + 5;
	sizez = (float) (rand() % 15) + 5;

	if(xpos + sizex > 100){ 
		xpos = 98 - sizex;} 
	if(xpos - sizex < -100){ 
		xpos = -98 + sizex;}
	if(ypos + sizey > 100) { 
		ypos = 98 - sizey;}
	if(ypos - sizey < -100){ 
		ypos = -98 + sizey;}
	if(zpos + sizez > 100) { 
		zpos = 98 - sizez;}
	if(zpos - sizez < -100){ 
		zpos = -98 + sizez;}
}

void Tetrahedron::DrawMe()
{
	glPushMatrix();
	glColor3f(r, g, b);
	glTranslatef(xpos, ypos, zpos);
	glScalef(sizex, sizey, sizez);
	glutSolidTetrahedron();
	glPopMatrix();
}