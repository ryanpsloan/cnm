//Bresdin O'Malley
//brezomalley@gmail.com
//Tree.cpp

#include <windows.h>
#include <gl/freeglut.h>
#include <math.h>
#include "bomTree.h"
#include "Component.h"

#define PI 3.14159265
#define NUM_POINTS 20

Tree::Tree() : Component()
{
	swing = 0;

	moveTree = false;
	treeCount = 0;
}

void Tree::Draw()
{

	glPushAttrib(GL_ALL_ATTRIB_BITS);
	qobj = gluNewQuadric();	

	glPushMatrix();
		glTranslatef(XPos, YPos, ZPos);
		glScalef(ScaleX, ScaleY, ScaleZ);

	glPushMatrix();		
		Trunk();	
			glRotatef(90.0, 1.0, 0.0, 0.0);
		glPushMatrix();
				glPushMatrix();
					glRotatef(30, 0, 0, 1);
					glCallList(index);			//Leaf bunch
				glPopMatrix();

				glPushMatrix();
					glRotatef(-60, 0, 0, 1);
					glCallList(index);			//Leaf bunch	
				glPopMatrix();

				glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glPushMatrix();
						glRotatef(30, 0, 0, 1);
						glCallList(index);		//Leaf Bunch	
					glPopMatrix();

					glPushMatrix();
						glRotatef(-60, 0, 0, 1);
						glCallList(index);		//Leaf Bunch
					/*glPushMatrix();
						glTranslatef(20, 20, 0);
						Hive();
					glPopMatrix();*/
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopAttrib();
	
}

void Tree::Setup()
{
	//call lists here
	index = glGenLists(1);

	glNewList(index, GL_COMPILE);
		LeafBunch();
	glEndList();

	/*glNewList(index, GL_COMPILE);
		Hive();
	glEndList();*/

}

void Tree::Update()
{
	if(bStartNext == true)
	{
		bStartNext = false;
	}

	if(bRunning)
	{
		moveTree = true;
		treeCount++;
		//----------------- start the coconuct before stoping
		if(treeCount == 20)			
			bStartNext = true;
		else if(treeCount == 150)	//Stop tree
			bRunning = false;
	}

}

void Tree::Reset()
{
	moveTree = false;
	treeCount = 0;
}

void Tree::Trunk()
{
	double a = 15; //To create smaller cylinders
		
		if(moveTree)
			LeafMovement();

		glRotatef(90.0, -1.0, 0.0, 0.0);
		for(int i = 0; i < 15; i++)
		{			
			glRotatef(swing, 0, 1, 0);
			if(i % 2 == 0)
			{
				glColor3ub(83, 105, 23); //color dark green
			}
			else
			{
				glColor3ub(96, 130, 3); //color light green			
			}

			glutSolidCylinder(a, 10, 20, 20);
			glTranslatef(0.0f, 0.0f, 10.0f);
			a--;
			
		}
}

void Tree::Leaves()
{
	glPushMatrix();
		//create 3 arrays

		Tri3D A[NUM_POINTS];
		Tri3D B[NUM_POINTS];
		Tri3D C[NUM_POINTS];


		for(int i = 0; i <NUM_POINTS; i++)
		{
			//Middle
			B[i].x = i*1.5+(1.0f/(float)(i+1))-3;
			B[i].y = 0;
			B[i].z = 0;
		}

		for(int i = 0; i < NUM_POINTS; i++)
		{
			//- Side B
			A[i].x = i*1.8;
			A[i].y = 0;
			A[i].z = 8 - (i * i)/50.0;//(i * 5/16.0);
		}

		for(int i = 0; i < NUM_POINTS; i++)
		{
			//Side A
			C[i].x = i*1.9;
			C[i].y = 0;
			C[i].z = -(8 - (i * i)/50.0);
		}

		
		srand(8675307);
		glColor3ub(155, 196, 40);
		for(int i = 0; i < NUM_POINTS-1; i++)
		{
			glBegin(GL_TRIANGLES);
				//-------------- Side A
				glNormal3f(0, 1, 0);
					glColor3ub(155, 196, 40);
				glVertex3f(B[i].x, B[i].y, B[i].z);
				glVertex3f(B[i + 1].x, B[i + 1].y, B[i + 1].z);
					glColor3ub(96, 130, 3);
				glVertex3f(A[i + 1].x, A[i + 1].y, A[i + 1].z);

				//-------------- Side B
				glNormal3f(0, 1, 0);
					glColor3ub(155, 196, 40);
				glVertex3f(B[i + 1].x, B[i + 1].y, B[i + 1].z);
				glVertex3f(B[i].x, B[i].y, B[i].z);
					glColor3ub(200, 130, 3);
				glVertex3f(C[i + 1].x, C[i + 1].y, C[i + 1].z);
				
			glEnd();
		}

		glColor3ub(96, 130, 3);
		for(int i =0; i <NUM_POINTS-1; i++)
		{
			glBegin(GL_TRIANGLES);
				//---------- Side A
			if (rand()%5 != 0) {
				glNormal3f(0, 1, 0);
				glVertex3f(B[i].x, B[i].y, B[i].z);
				glVertex3f(A[i + 1].x, A[i + 1].y, A[i + 1].z);
				glVertex3f(A[i].x, A[i].y, A[i].z);
			}
				//---------- Side B
			if (rand()%7 != 0) {
				glNormal3f(0, 1, 0);
				glVertex3f(B[i].x, B[i].y, B[i].z);
				glVertex3f(C[i + 1].x, C[i + 1].y, C[i + 1].z);
				glVertex3f(C[i].x, C[i].y, C[i].z);
			}
			glEnd();
		}

		for(int i = 0; i <NUM_POINTS; i++)
		{
			//Middle
			B[i].x = -(i+(1.0f/(float)(i+1)))+3;
			B[i].y = 0;
			B[i].z = 0;
		}

		for(int i = 0; i < NUM_POINTS; i++)
		{
			//- Side B
			A[i].x = -i;
			A[i].y = 0;
			A[i].z = 8 - (i * i)/50.0;//(i * 5/16.0);
		}

		for(int i = 0; i < NUM_POINTS; i++)
		{
			//Side A
			C[i].x = -i;
			C[i].y = 0;
			C[i].z = -(8 - (i * i)/50.0);
		}

		glColor3ub(155, 196, 40);
		for(int i = 0; i < NUM_POINTS-1; i++)
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
		
		glColor3ub(96, 130, 3);
		for(int i =0; i <NUM_POINTS-1; i++)
		{
			glBegin(GL_TRIANGLES);
				//---------- Side A
			if (rand()%18 != 0) {
				glNormal3f(0, 1, 0);

				glVertex3f(B[i].x, B[i].y, B[i].z);
				glVertex3f(A[i + 1].x, A[i + 1].y, A[i + 1].z);
				glVertex3f(A[i].x, A[i].y, A[i].z);
			}
				//---------- Side B
			if (rand()%6 != 0) {
				glNormal3f(0, 1, 0);
				glVertex3f(B[i].x, B[i].y, B[i].z);
				glVertex3f(C[i + 1].x, C[i + 1].y, C[i + 1].z);
				glVertex3f(C[i].x, C[i].y, C[i].z);
			}
			glEnd();
		}
	//cube for refrence
	//glPushMatrix();
	//	gluQuadricDrawStyle(qobj, GLU_FILL); /* flat shaded */
	//	gluQuadricNormals(qobj, GLU_FLAT);
	//	glColor3ub(96, 130, 3);
	//	gluCylinder(qobj, 1, .05, 30, 10, 10);

	//glPopMatrix();
	glPopMatrix();

}

void Tree::LeafBunch()
{
	GLfloat roLeaves[3] = {70, 100, 130};

	for(int i = 0; i < 3; i++)
	{
		glPushMatrix();	
			glScalef(2, 2, 2);
			glRotatef(roLeaves[i]/5, 1, 0, 0);
			glRotatef(roLeaves[i], 0, 0, 1);
			glRotatef(roLeaves[i]/10, 0, 1, 0);
			glTranslatef(15.0, 0, 0);
			Leaves();
			glRotatef(90, 1, 0, 0);
			Leaves();
		glPopMatrix();
	}
}

void Tree::LeafMovement()
{
	double unit = (1);

	if (swing < -unit)
		swingForward = true;
	else if (swing > unit)
		swingForward = false;

	if (swingForward)
		swing += .03;
	else
		swing -= .03;
}

void Tree::Hive()
{
	double a = 8; //To create smaller torus

	glRotatef(70.0f, 0, 1, 0);

		for(int i = 0; i < 5; i++)
		{
			if(i % 2 == 0)
			{
				glColor3ub(255, 215, 55); //bright yellow
			}
			else
			{
				glColor3ub(232, 206, 96); //dark yellow
			}
			glutSolidTorus(a, 5, 16, 16);
			glTranslatef(0.0f, 0.0f, 4.0f);
			a--;
		}
}

