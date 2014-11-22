//Bresdin O'Malley
//brezomalley@gmail.com
//Coconut.cpp

#include <windows.h>
#include <gl/freeglut.h>
#include <math.h>
#include "bomTree.h"
#include "Component.h"
#include "bomCoconut.h"

#define PI 3.14159265

Coconut::Coconut() : Component()
{
	drop = false;

	c = 0;

}

void Coconut::Draw()
{	
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();
	
		glTranslatef(XPos, YPos, ZPos);
		glScalef(ScaleX, ScaleY, ScaleZ);

		

		glCallList(index);	
		
		

		glPopMatrix();
	glPopAttrib();
	
}

void Coconut::Setup()
{
	//call lists here
	index = glGenLists(1);

		glNewList(index, GL_COMPILE);
			glColor3ub(74, 33, 6);
			glutSolidSphere(10, 15, 15);
		glEndList();

}

void Coconut::Update()
{
	if(bStartNext == true)
	{
		bStartNext = false;
	}

	if(bRunning)
	{
		c++;
		if(c = 500)
			drop = true;

		if(drop)
		{
			if(YPos >= 20.0)
			{
				//Move down the Y axis
				YPos -= 5.0;
			}
			else if(XPos <= 0.0)
			{
				//Move forward on the X axis
				glRotatef(360.0f, 1, 0, 0);
				XPos += 1.0;
				if(XPos >= 0.0)
				{
					bRunning = false;
					bStartNext = true;
				}
			}

			
		}
		else
		{
			//This must mimic tree
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

		
	}
}

void Coconut::Reset()
{

}