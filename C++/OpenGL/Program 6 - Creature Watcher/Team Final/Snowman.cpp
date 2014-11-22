//Kevin D'Ornellas	
//kdornellas@cnm.edu
//Program 5 Watcher

#include "Snowman.h"
#include <GL/freeglut.h>
#include <Windows.h>
#include <math.h>
#include "Functions.h"
extern bool kdlaser;
extern float laserd, headangle;
extern float starX, starY, starZ;


Snowman::Snowman()
{

}


void Snowman::DrawBody()
{
	glScalef(0.25,0.25,0.25);
	
	 //glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	 glColor3f(1.0f,1.0f,1.0f);
	 glPushMatrix();	 
	 glTranslatef(0.0f, 20.0f, 0.0f);
	 glutSolidSphere(20,12,12);//draw bottom
	 glPushMatrix();
	 glTranslatef(0.0f, 33.0f, 0.0f);
	 glutSolidSphere(15,12,12);//draw middle
	 glPushMatrix();
	 glRotatef(headangle+25, 0.5, 0.0, -0.5);
	 glTranslatef(0.0f, 23.0f, 0.0f);
	 glutSolidSphere(10,12,12);//draw head
	 
}

void Snowman::DrawFace()
{
	glPushMatrix();
	 glTranslatef(0.0f, 9.0f, 0.0f);
	 glColor3f(1.0f,0.0f,0.0f);
	 glRotatef(90.0,-3.0,0.0,0.0);
	 glutSolidCone(4.0,10.0,12,12);//draw hat
	 
	 glPopMatrix();//pop hat
	 glPushMatrix();//push mouth
	 glColor3f(0.0f,0.0f,0.0f);
	 glTranslatef(7.5f, 0.0f, 7.5f);	 
	 glRotatef(45.0,0.0,1.0,0.0);
	 glScalef(2.0,0.5,1.0);
	 glutSolidCylinder(2.0,0.1,12,12);
	 glPopMatrix();
	 glPushMatrix();//push right eye
	 glRotatef(-20.0,0.0,1.0,0.0);
	 //draw laser
	 


	 glTranslatef(6.5f, 6.0f, 6.5f);
	 glRotatef(45.0,0.0,1.0,0.0);
	 glScalef(1.0,0.3,1.0);
	 glutSolidCylinder(2.0,0.1,12,12);
	 glPopMatrix();
	 glPushMatrix();//push right eye center
	 glRotatef(-20.0,0.0,1.0,0.0);
	 glTranslatef(6.5f, 6.0f, 6.5f);
	 glRotatef(45.0,0.0,1.0,0.0);
	 glColor3f(1.0f,0.0f,0.0f);
	 glutSolidCylinder(.3,0.2,12,12);
		if(kdlaser)
		{
			glRotatef(20.0,0.0,1.0,0.0);
		glLineWidth(2.5);
		//newdistance = sqrt((82*82)+(laserd)*(laserd));
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0, 0, laserd*4);
		glEnd();
		}
	
	 glPopMatrix();
	 glPushMatrix();//push left eye
	 glColor3f(0.0f,0.0f,0.0f);
	 glRotatef(20.0,0.0,1.0,0.0);
	 glTranslatef(6.5f, 6.0f, 6.5f);
	 glRotatef(45.0,0.0,1.0,0.0);
	 glScalef(1.0,0.3,1.0);
	 glutSolidCylinder(2.0,0.1,12,12);
	 glPopMatrix();
	 glPushMatrix();//push left eye center
	 glColor3f(1.0f,0.0f,0.0f);
	 glRotatef(20.0,0.0,1.0,0.0);
	 glTranslatef(6.5f, 6.0f, 6.5f);
	 glRotatef(45.0,0.0,1.0,0.0);
	 glutSolidCylinder(0.3,0.2,12,12);

	 if(kdlaser)
		{
			glRotatef(-20.0,0.0,1.0,0.0);
		glLineWidth(2.5);
		//newdistance = sqrt((82*82)+((laserd)*(laserd)));
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0, 0, laserd*4);
		glEnd();
		}
	
	 glPopMatrix();
	 glPushMatrix();//push nose
	 glColor3f(1.0f,0.5f,0.0f);
	 glTranslatef(6.5f, 3.0f, 6.5f);
	 glRotatef(45.0,0.0,1.0,0.0);
	 glutSolidCone(1.5, 8.0, 12, 12);
	 glPopMatrix();
	 glPushMatrix();//push right eyebrow
	 glColor3f(0.0f,0.0f,0.0f);
	 glTranslatef(6.5f, 6.0f, 6.5f);
	 
	 glLineWidth((GLfloat)1.0);
	 glBegin(GL_LINES);
     glVertex3f(0.0,0.0,0.0);
     glVertex3f(-4.5,2.3,2.0);
	 glEnd();
	
	 glPopMatrix();
	 glPushMatrix();//push left eyebrow
	 glColor3f(0.0f,0.0f,0.0f);
	 glTranslatef(6.5f, 6.2f, 6.5f);
	 glRotatef(-12.0,0.0,1.0,0.0);
	 glLineWidth((GLfloat)1.0);
	 glBegin(GL_LINES);
     glVertex3f(0.0,0.0,0.0);
     glVertex3f(2.0,2.0,-4.0);
	 glEnd();	
	 glPopMatrix();//pop eyebrows
	 glPopMatrix();//pop head
}

void Snowman::DrawButtons()
{
	 glPushMatrix();//push top button
	 glColor3f(1.0f,0.0f,0.0f);
	 glTranslatef(7.6f, 11.0f, 7.6f);
	 glRotatef(45.0,0.0,1.0,0.0);
	 glRotatef(50.0,-1.0,0.0,-1.0);
	 glutSolidCylinder(1.5,0.1,12,12);
	 glPopMatrix();
	 glPushMatrix();//push middle button
	 glColor3f(1.0f,0.0f,0.0f);
	 glTranslatef(10.5f, 3.0f, 10.5f);
	 glRotatef(45.0,0.0,1.0,0.0);
	 glutSolidCylinder(1.5,0.1,12,12);
	 glPopMatrix();
	 glPushMatrix();//push bottom button
	 glColor3f(1.0f,0.0f,0.0f);
	 glTranslatef(9.9f, -6.0f, 9.9f);
	 glRotatef(45.0,0.0,1.0,0.0);
	 glRotatef(30.0,1.0,0.0,1.0);
	 glutSolidCylinder(1.5,0.1,12,12);
	 glPopMatrix();


}

void Snowman::DrawArms()
{
	 glPushMatrix();//push left arm
	 glColor3f(0.7f,0.3f,0.0f);
	 glTranslatef(14.5f, 12.0f, -14.5f);
	 glRotatef(30.0,0.0,-1.0,0.0);
	 glRotatef(65.0,1.0,0.0,-1.0);
	 glutSolidCylinder(1.0,12.0,12,12);
	 //draw forearm
	 glRotatef(-30.0,0.0,-1.0,0.0);
	 glRotatef(-65.0,1.0,0.0,-1.0);
	 glPushMatrix();
	 glTranslatef(5.7f, 5.9f, -4.7f);
	 glRotatef(180.0,-0.4,-0.4,1.0);
	 glutSolidCylinder(1.0,10.0,12,12);
	 
	 //draw middle finger
	 glPushMatrix();
	 glTranslatef(-1.3f, -1.3f, -5.1f);
	 glRotatef(180.0,0.9,1.0,-0.2);
	 glRotatef(180.0,0.0,1.0,0.0);
	 glutSolidCylinder(0.4,5.5,12,12);

	 //draw finger tip
	 glPushMatrix();
	 glRotatef(-180.0,0.9,1.0,-0.2);
	 glRotatef(-180.0,0.0,1.0,0.0);
	 glRotatef(180.0,1.0,0.1,0.1);
	 glutSolidCone(0.4,4.4,12,12);
	 glPopMatrix();
	 glPopMatrix();

	 //draw index finger
	 
	 glPushMatrix();
	 glTranslatef(-2.8f, -3.4f, -5.1f);
	 
	 glRotatef(180.0,0.7,0.8,-0.4);
	 glRotatef(180.0,0.0,1.0,0.0);
	 glutSolidCylinder(0.4,5.5,12,12);

	 //draw finger tip
	 glPushMatrix();
	 glRotatef(-180.0,0.9,1.0,-0.2);
	 glRotatef(-180.0,0.0,1.0,0.0);
	 glRotatef(180.0,1.0,0.1,0.1);
	 glutSolidCone(0.4,4.4,12,12);
	 glPopMatrix();
	 glPopMatrix();

	 //draw ring finger
	  glPushMatrix();
	 glTranslatef(-0.5f, 1.7f, -5.1f);
	 
	 glRotatef(180.0,0.8,1.0,0.4);
	 glRotatef(180.0,-0.1,-0.8,-0.2);
	 glutSolidCylinder(0.4,5.5,12,12);

	 //draw finger tip
	 glPushMatrix();
	 glRotatef(-180.0,0.8,1.0,-0.2);
	 glRotatef(-180.0,0.0,1.0,0.0);
	 glRotatef(180.0,1.0,0.1,0.1);
	 glutSolidCone(0.4,4.4,12,12);
	 glPopMatrix();
	 glPopMatrix();

	 glPopMatrix();
	 glPopMatrix();

	  glPushMatrix();//push right arm
	 glColor3f(0.7f,0.3f,0.0f);
	 glTranslatef(-14.5f, 12.0f, 14.5f);
	 glRotatef(30.0,-0.4,-1.0,-0.4);
	 glRotatef(65.0,1.0,0.0,-1.0);
	 glRotatef(180, 0.7, -0.6, .6);
	 glutSolidCylinder(1.0,12.0,12,12);
	 //draw forearm
	 glRotatef(-30.0,0.0,-1.0,0.0);
	 glRotatef(-65.0,1.0,0.0,-1.0);
	 glPushMatrix();
	 glTranslatef(5.7f, 5.9f, -4.7f);
	 glRotatef(180.0,-0.4,-0.4,1.0);
	 glutSolidCylinder(1.0,10.0,12,12);
	 
	 //draw middle finger
	 glPushMatrix();
	 glTranslatef(-1.3f, -1.3f, -5.1f);
	 glRotatef(180.0,0.9,1.0,-0.2);
	 glRotatef(180.0,0.0,1.0,0.0);
	 glutSolidCylinder(0.4,5.5,12,12);

	 //draw finger tip
	 glPushMatrix();
	 glRotatef(-180.0,0.9,1.0,-0.2);
	 glRotatef(-180.0,0.9,1.0,0.0);
	 glRotatef(180.0,0.2,0.1,0.1);
	 glutSolidCone(0.4,4.4,12,12);
	 glPopMatrix();
	 glPopMatrix();

	 //draw index finger
	 
	 glPushMatrix();
	 glTranslatef(-2.8f, -3.4f, -5.1f);
	 
	 glRotatef(180.0,0.7,0.8,-0.4);
	 glRotatef(180.0,0.0,1.0,0.0);
	 glutSolidCylinder(0.4,5.5,12,12);

	 //draw finger tip
	 glPushMatrix();
	 glRotatef(-180.0,0.9,1.0,-0.2);
	 glRotatef(-180.0,0.9,1.0,0.0);
	 glRotatef(180.0,0.2,0.1,0.1);
	 glutSolidCone(0.4,4.4,12,12);
	 glPopMatrix();
	 glPopMatrix();

	 //draw ring finger
	  glPushMatrix();
	 glTranslatef(-0.5f, 1.7f, -5.1f);
	 
	 glRotatef(180.0,0.8,1.0,0.4);
	 glRotatef(180.0,-0.1,-0.8,-0.2);
	 glutSolidCylinder(0.4,5.5,12,12);

	 //draw finger tip
	 glPushMatrix();
	 glRotatef(-180.0,0.8,1.0,-0.2);
	 glRotatef(-180.0,0.9,1.0,0.0);
	 glRotatef(180.0,0.2,0.1,0.1);
	 glutSolidCone(0.4,4.4,12,12);
	 glPopMatrix();
	 glPopMatrix();

	 glPopMatrix();
	 glPopMatrix();
	 glPopMatrix();
	 glPopMatrix();
	 glScalef(4.0,4.0,4.0);



}


void Snowman::DrawPuddle()
{
	
	glPushMatrix();
	glScalef(0.25,0.25,0.25);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glColor3f(0.0f,0.0f,1.0f);
	 glTranslatef(0.0f, 0.1f, 0.0f);
	 glutSolidCylinder(50.0,0.1,12,12);
	 glPopMatrix();
	 glPushMatrix();
	 glScalef(0.25,0.25,0.25);
	 glTranslatef(0.0f, 0.1f, 0.0f);
	 glColor3f(1.0f,0.0f,0.0f);
	 glRotatef(90.0,-3.0,0.0,0.0);
	 glutSolidCone(4.0,10.0,12,12);//draw hat
	 
	 glPopMatrix();

	 glPushMatrix();//push left arm
	 glRotatef(135.0,0.0,0.0,1.0);
	 glScalef(0.25,0.25,0.25);
	 glColor3f(0.7f,0.3f,0.0f);
	 glTranslatef(14.5f, 12.0f, -14.5f);
	 glRotatef(30.0,0.0,-1.0,0.0);
	 glRotatef(65.0,1.0,0.0,-1.0);
	 glutSolidCylinder(1.0,12.0,12,12);
	 //draw forearm
	 glRotatef(-30.0,0.0,-1.0,0.0);
	 glRotatef(-65.0,1.0,0.0,-1.0);
	 glPushMatrix();
	 glTranslatef(5.7f, 5.9f, -4.7f);
	 glRotatef(180.0,-0.4,-0.4,1.0);
	 glutSolidCylinder(1.0,10.0,12,12);
	 
	 //draw middle finger
	 glPushMatrix();
	 glTranslatef(-1.3f, -1.3f, -5.1f);
	 glRotatef(180.0,0.9,1.0,-0.2);
	 glRotatef(180.0,0.0,1.0,0.0);
	 glutSolidCylinder(0.4,5.5,12,12);

	 //draw finger tip
	 glPushMatrix();
	 glRotatef(-180.0,0.9,1.0,-0.2);
	 glRotatef(-180.0,0.0,1.0,0.0);
	 glRotatef(180.0,1.0,0.1,0.1);
	 glutSolidCone(0.4,4.4,12,12);
	 glPopMatrix();
	 glPopMatrix();

	 //draw index finger
	 
	 glPushMatrix();
	 glTranslatef(-2.8f, -3.4f, -5.1f);
	 
	 glRotatef(180.0,0.7,0.8,-0.4);
	 glRotatef(180.0,0.0,1.0,0.0);
	 glutSolidCylinder(0.4,5.5,12,12);

	 //draw finger tip
	 glPushMatrix();
	 glRotatef(-180.0,0.9,1.0,-0.2);
	 glRotatef(-180.0,0.0,1.0,0.0);
	 glRotatef(180.0,1.0,0.1,0.1);
	 glutSolidCone(0.4,4.4,12,12);
	 glPopMatrix();
	 glPopMatrix();

	 //draw ring finger
	  glPushMatrix();
	 glTranslatef(-0.5f, 1.7f, -5.1f);
	 
	 glRotatef(180.0,0.8,1.0,0.4);
	 glRotatef(180.0,-0.1,-0.8,-0.2);
	 glutSolidCylinder(0.4,5.5,12,12);

	 //draw finger tip
	 glPushMatrix();
	 glRotatef(-180.0,0.8,1.0,-0.2);
	 glRotatef(-180.0,0.0,1.0,0.0);
	 glRotatef(180.0,1.0,0.1,0.1);
	 glutSolidCone(0.4,4.4,12,12);
	 glPopMatrix();
	 glPopMatrix();
	 glPopMatrix();
	 glPopMatrix();
}



