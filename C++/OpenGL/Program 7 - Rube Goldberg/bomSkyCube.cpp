//Bresdin O'Malley 
//bomalley2@cnm.edu
//Cube.cpp
//Program 4 Teapot Forest, objects, glCallLists, Translation, scaling and lighting
//OpenGL


#include "bomSkyCube.h"

#define _CRT_SECURE_NO_WARNINGS

/*  Skybox Textures  */

SkyBox::SkyBox()
{
	for(int i = 0; i < 6; i++)
	{
		skybox[i] = 0;
	}
}
void SkyBox::DrawScene()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();
			glCallList(index);			//blue box
		glPopMatrix();

		glPushMatrix();
			glCallList(index + 1);		//island
		glPopMatrix();
	glPopAttrib();

}
void SkyBox::CallList()
{
	//call lists here
	index = glGenLists(2);

	glNewList(index, GL_COMPILE);
		DrawSkybox(600);
	glEndList();

	glNewList(index + 1, GL_COMPILE);
		glTranslatef(0.0f, 0.0f, 0.0f);
		DrawBeach();
	glEndList();

}

void SkyBox::DrawSkybox(double D)
{
	//D variable is the size of the panels 

	//This draws a blue square to simulate sky and ocean
	glPushAttrib(GL_ALL_ATTRIB_BITS);
			glColor3ub(0, 0, 255);

		glBegin(GL_QUADS);
			glTexCoord2f(0,0); glVertex3f(-D,-D,-D);
			glTexCoord2f(1,0); glVertex3f(+D,-D,-D);
			glTexCoord2f(1,1); glVertex3f(+D,+D,-D);
			glTexCoord2f(0,1); glVertex3f(-D,+D,-D);
		glEnd();

		glBegin(GL_QUADS);
			glTexCoord2f(0,0); glVertex3f(+D,-D,-D);
			glTexCoord2f(1,0); glVertex3f(+D,-D,+D);
			glTexCoord2f(1,1); glVertex3f(+D,+D,+D);
			glTexCoord2f(0,1); glVertex3f(+D,+D,-D);
		glEnd();
		glBegin(GL_QUADS);
			glTexCoord2f(0,0); glVertex3f(+D,-D,+D);
			glTexCoord2f(1,0); glVertex3f(-D,-D,+D);
			glTexCoord2f(1,1); glVertex3f(-D,+D,+D);
			glTexCoord2f(0,1); glVertex3f(+D,+D,+D);
		glEnd();

		glBegin(GL_QUADS);
			glTexCoord2f(0,0); glVertex3f(-D,-D,+D);
			glTexCoord2f(1,0); glVertex3f(-D,-D,-D);
			glTexCoord2f(1,1); glVertex3f(-D,+D,-D);
			glTexCoord2f(0,1); glVertex3f(-D,+D,+D);
		glEnd();

		glBegin(GL_QUADS);
			glTexCoord2f(0,0); glVertex3f(-D,+D,-D);
			glTexCoord2f(1,0); glVertex3f(+D,+D,-D);
			glTexCoord2f(1,1); glVertex3f(+D,+D,+D);
			glTexCoord2f(0,1); glVertex3f(-D,+D,+D);
		glEnd();
				
		glBegin(GL_QUADS);
			glTexCoord2f(1,1); glVertex3f(+D,-D,-D);
			glTexCoord2f(0,1); glVertex3f(-D,-D,-D);
			glTexCoord2f(0,0); glVertex3f(-D,-D,+D);
			glTexCoord2f(1,0); glVertex3f(+D,-D,+D);
		glEnd();

	glPopAttrib();
}

void SkyBox::DrawBeach()
{	
	glPushAttrib(GL_ALL_ATTRIB_BITS);
		glPushMatrix();
			glColor3ub(230, 172, 86);
			glScalef(10.0f, .50f, 10.0f);
			glutSolidSphere(20, 30, 30);
		glPopMatrix();
	glPopAttrib();
}
