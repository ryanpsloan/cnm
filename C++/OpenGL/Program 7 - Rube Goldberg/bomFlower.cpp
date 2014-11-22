//Bresdin O'Malley
//brezomalley@gmail.com
//flower.cpp

#include <windows.h>
#include <gl/freeglut.h>
#include <math.h>
#include "bomFlower.h"
#define PI 3.14159265
#define LEAF_POINTS 20     //Point arrays to draw leaves



////////////////////////// This will changethe color of the flower petals
////changing the color

GLubyte Flower::petals[20][3]= 
	{
	{139, 0, 139},   //Maroon
	{139, 0, 139},
	{139, 0, 139},
	{139, 0, 139},
	{139, 71, 137},
	{139, 71, 137},
	{139, 71, 137},
	{139, 71, 137},
	{205,105,201},
	{205,105,201},
	{205,105,201},
	{205,105,201},
	{218,112,214},
	{218,112,214},
	{219,112,219},
	{219,112,219},
	{238,122,233},
	{238,122,233},
	{238,122,233},
	{255,131,250},
	};

Flower::Flower() : Component()
{
	XPos = ZPos = 0.0f;

	Yaw = 0.0f;
	ScaleX = ScaleY = ScaleZ = 3.0f;

	count = count2 = -50;
	leafC1 = 0.0f;

	doneDrawing = true;
	up = false;

	dist = 4;
}

void Flower::Draw()
{	
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glTranslatef(XPos, YPos, ZPos);
	glScalef(ScaleX, ScaleY, ScaleZ);
	glRotatef(DegreeStart, AngleXStart, AngleYStart, AngleZStart);

	if(count == 0)
	{
		//----------------------- Draw the flower petals
		glPushMatrix();
			glTranslatef(0, 50, 0);
			glColor3ub(139, 0, 139);
			Middle(5);
			glRotatef(45.0f, 1, 0, 0);
			
			if(up)
			{
					for (GLfloat angle = 0; angle < 360; angle += 20)
					{
						glPushMatrix();
						glRotatef(angle, 0, 1, 0);
						glPushMatrix();
						for (int spheres = 0; spheres < 20; spheres++)
						{
							glTranslatef(1.5f, 0, 0);
							glRotatef(dist*dist, 0, 1, 0);
							glColor3ubv(petals[spheres]);
							Middle(1+(spheres/5.0f));							
						}

					glPopMatrix();
					glPopMatrix();

						if(angle >= 340)
						{
							bStartNext = true;
						}
					
					}

				glPopMatrix();
			}
	}

//--------------------------------- Draw the base
	
	glPushMatrix();
		glColor3ub(139, 0, 139);
		glTranslatef(0, count+50, 0);
		Middle(3);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, count, 0);
		glCallList(index);	
	glPopMatrix();

	if(up)
	{
		if(leafC1 <= .80f)
		{
			leafC1 = leafC1 + .01f;
		}
	}

	glPushMatrix();
		glTranslatef(0.0f, count+20.0f, 0.0f);
	//--------------------------- Draw first leaf
	glPushMatrix();
		//glScalef(.80f, .80f, .80f);
		glScalef(leafC1, leafC1, leafC1);
		glTranslatef(15.0f, 0.0f, 0.0f);
		glRotatef(45.0f, 0, 0, 1);
		glCallList(index + 1);
	glPushMatrix();
		glRotatef(90.0f, 1, 0, 0);
		glCallList(index + 1);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, count+30.0f, 0.0f);
	glPushMatrix();
	//--------------------------- Draw second leaf
		//glScalef(.80f, .80f, .80f);
		glScalef(leafC1, leafC1, leafC1);
		glTranslatef(-18.5f, 0.0f, 0.0f);
		glRotatef(-210.0f, 0, 0, 1);
		glCallList(index + 1);
	glPushMatrix();
		glRotatef(90.0f, 1, 0, 0);
		glCallList(index + 1);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopAttrib();
}

void Flower::Setup()
{
	//Sets up call lists!
	qobj = gluNewQuadric();
	index = glGenLists(2);

	glNewList(index, GL_COMPILE);
		StemBase();
	glEndList();

	glNewList(index + 1, GL_COMPILE);
		FlowerLeaves();
	glEndList();

}

void Flower::Update()
{
	if(bStartNext == true)
	{
		bStartNext = false;
	}

	if(bRunning == true)
	{
		//start drawing and moving compnent
		up = true;
		
		if(count != 0)
		{
			count++;
		}
		if (dist > 0 && count == 0) dist -= 0.05f;	
	}
}

void Flower::Reset()
{
	XPos = ZPos = 0.0f;

	Yaw = 0.0f;
	ScaleX, ScaleY, ScaleZ = 3.0f;

	count = -50;
	leafC1 = 0.0f;
}

void Flower::StemBase()
{

	glRotatef(90.0, -1.0, 0.0, 0.0);
	glColor3ub(96, 130, 3);
	glutSolidCylinder(2, 50, 20, 20);
	
}

void Flower::FlowerLeaves()
{
	glPushMatrix();
		//create 3 arrays

		Triangles A[LEAF_POINTS];
		Triangles B[LEAF_POINTS];
		Triangles C[LEAF_POINTS];


		for(int i = 0; i <LEAF_POINTS; i++)
		{
			//Middle
			B[i].x = i*2.0f+(1.0f/(float)(i+1))-3;
			B[i].y = 0;
			B[i].z = 0;
		}

		for(int i = 0; i < LEAF_POINTS; i++)
		{
			//- Side B
			A[i].x = i*1.8;
			A[i].y = 0;
			A[i].z = 8 - (i * i)/50.0;//(i * 5/16.0);
		}

		for(int i = 0; i < LEAF_POINTS; i++)
		{
			//Side A
			C[i].x = i*1.9;
			C[i].y = 0;
			C[i].z = -(8 - (i * i)/50.0);
		}

		
		for(int i = 0; i < LEAF_POINTS-1; i++)
		{
			glBegin(GL_TRIANGLES);
				//-------------- Side A
				glColor3ub(155, 196, 40);
				glVertex3f(B[i].x, B[i].y, B[i].z);
				glVertex3f(B[i + 1].x, B[i + 1].y, B[i + 1].z);
				glVertex3f(A[i + 1].x, A[i + 1].y, A[i + 1].z);

				//-------------- Side B
				glNormal3f(0, 1, 0);
				glVertex3f(B[i + 1].x, B[i + 1].y, B[i + 1].z);
				glVertex3f(B[i].x, B[i].y, B[i].z);
				glVertex3f(C[i + 1].x, C[i + 1].y, C[i + 1].z);
				
			glEnd();
		}

		glColor3ub(163, 210, 52);
		for(int i =0; i <LEAF_POINTS-1; i++)
		{
			glBegin(GL_TRIANGLES);
				//---------- Side A
				glNormal3f(0, 1, 0);
				glVertex3f(B[i].x, B[i].y, B[i].z);
				glVertex3f(A[i + 1].x, A[i + 1].y, A[i + 1].z);
				glVertex3f(A[i].x, A[i].y, A[i].z);
			
				//---------- Side B	
				glNormal3f(0, 1, 0);
				glVertex3f(B[i].x, B[i].y, B[i].z);
				glVertex3f(C[i + 1].x, C[i + 1].y, C[i + 1].z);
				glVertex3f(C[i].x, C[i].y, C[i].z);
			
			glEnd();
		}


		//---------------------------------- Back end of leaf
		for(int i = 0; i <LEAF_POINTS; i++)
		{
			//Middle
			B[i].x = -(i+(1.0f/(float)(i+1)))+1;
			B[i].y = 0;
			B[i].z = 0;
		}

		for(int i = 0; i < LEAF_POINTS; i++)
		{
			//- Side B
			A[i].x = -i;
			A[i].y = 0;
			A[i].z = 8 - (i * i)/50.0;//(i * 5/16.0);
		}

		for(int i = 0; i < LEAF_POINTS; i++)
		{
			//Side A
			C[i].x = -i;
			C[i].y = 0;
			C[i].z = -(8 - (i * i)/50.0);
		}

		glColor3ub(155, 196, 40);
		for(int i = 0; i < LEAF_POINTS-1; i++)
		{
			glBegin(GL_TRIANGLES);
				//-------------- Side A
				glNormal3f(0, 1, 0);
				glVertex3f(B[i].x, B[i].y, B[i].z);
				glVertex3f(B[i + 1].x, B[i + 1].y, B[i + 1].z);
				glVertex3f(A[i + 1].x, A[i + 1].y, A[i + 1].z);

				//-------------- Side B
				glNormal3f(0, 1, 0);
				glVertex3f(B[i].x, B[i].y, B[i].z);
				glVertex3f(C[i + 1].x, C[i + 1].y, C[i + 1].z);
				glVertex3f(B[i + 1].x, B[i + 1].y, B[i + 1].z);
			glEnd();
		}
		
		glColor3ub(163, 210, 52);
		//glColor3ub(96, 130, 3);
		for(int i =0; i <LEAF_POINTS-1; i++)
		{
			glBegin(GL_TRIANGLES);
				//---------- Side A
				glNormal3f(0, 1, 0);
				glVertex3f(B[i].x, B[i].y, B[i].z);
				glVertex3f(A[i + 1].x, A[i + 1].y, A[i + 1].z);
				glVertex3f(A[i].x, A[i].y, A[i].z);
				//---------- Side B
				glNormal3f(0, 1, 0);
				glVertex3f(B[i].x, B[i].y, B[i].z);
				glVertex3f(C[i + 1].x, C[i + 1].y, C[i + 1].z);
				glVertex3f(C[i].x, C[i].y, C[i].z);
			glEnd();		
		}
	glPopMatrix();
}

void Flower::Middle(GLfloat sphereSize)
{
	glutSolidSphere(sphereSize, 20, 20);
}



