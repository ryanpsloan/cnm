//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>
#include "Octahedron.h"

using namespace std;

Octahedron::Octahedron()
{
	r = (rand() % 100) / 100.0f;
	g = (rand() % 100) / 100.0f;
	b = (rand() % 100) / 100.0f;

	xpos = (float) (rand() % 201) - 100;
	ypos = (float) (rand() % 201) - 100;
	zpos = (float) (rand() % 201) - 100;

	sizex = (float) (rand() % 150) - 75;
	sizey = (float) (rand() % 150) - 75;
	sizez = (float) (rand() % 150) - 75;
}

void Octahedron::DrawMe()
{
	glPushMatrix();
	glColor3f(r, g, b);
	glTranslatef(xpos, ypos, zpos);
	glScalef(sizex, sizey, sizez);
	glutSolidOctahedron();
	glPopMatrix();
}