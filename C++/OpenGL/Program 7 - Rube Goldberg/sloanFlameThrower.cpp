#include <windows.h>		// Must have for Windows platform builds
#include <gl/freeglut.h>
//#include <iostream>
#include "sloanFlameThrower.h"
using namespace std;

FlameThrower::FlameThrower(){
	fireOn = false;
	FTcount = 0;
	XPos = -10.0f; 
	YPos = 0.0f; 
	ZPos = 50.0f;
	bRunning = false;
	FTcount = 0;
}

void FlameThrower::Draw(){
		//pushMatrix 1 is in setup
	glPushAttrib(GL_ALL_ATTRIB_BITS);

		glScalef(0.65f, 0.65f, 0.65f);
		glCallList(index);
		if(fireOn){
			glPushMatrix();//5
				glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
				glScalef(2.0f, 2.0f, 5.5f);
				flames.Pos();
			glPopMatrix();//5
			FTcount++;
		}
		glPopMatrix(); //1 pushMatrix is in Setup;

	glPopAttrib();
}


void FlameThrower::Update(){
	if(bRunning){
		fireOn = true;
		//cout << "FTcount:" << FTcount << " ";
		FTcount++;
		if(FTcount > 444){
			bRunning = false;
			fireOn = false;
			bStartNext = true;
		}
	}
}
 

void FlameThrower::Setup(){
	index = glGenLists(1);
	glNewList(index, GL_COMPILE);

		glTranslatef(XPos, YPos, ZPos);
		glScalef(ScaleX, ScaleY, ScaleZ);
		glRotatef(DegreeStart, AngleXStart, AngleYStart, AngleZStart);

		glPushMatrix();//1
		glTranslatef(XPos, YPos, ZPos);
		glScalef(2.0f, 2.0f, 2.0f);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		glTranslatef(0.0f, 0.0f, 5.0f); //x0 y0 z5
		glColor3f(1.0f, 1.0f, 0.0f); //yellow
		glutSolidSphere(5.0f, 20, 20); //bottom of tank1 //x0 y0 z0
		glutSolidCylinder(5.0f, 15.0f, 20, 20); // body of tank1 //x0 y0 z0
		glTranslatef(0.0f, 0.0f, 15.0f); //to top end of tank1 //x0 y0 z15
		glutSolidSphere(5.0f, 20, 20); //top end of tank1
		glTranslatef(10.0f, 0.0f, -15.0); // across to tank2 //x10 y0 z0
		glutSolidSphere(5.0f, 20, 20); // bottom end tank2
		glutSolidCylinder(5.0f, 15.0f, 20 ,20); // body of tank2
		glTranslatef(0.0f, 0.0f, 15.0f); // to top end tank2 //x10 y0 z15
		glutSolidSphere(5.0f, 20, 20); // top end tank2
		glTranslatef(0.0f, 0.0f, 4.0f);//x10 y0 z19
		glColor3f(0.5f, 0.5f, 0.5f); //gray
		glutSolidCylinder(2.0f, 5.0f, 20, 20); // fuel line tank2
		glTranslatef(0.0f, 0.0f, 5.0f); // x10 y0 x24
		glutSolidSphere(2.0f, 20, 20); // fuel line tank2
		glTranslatef(-10.0f, 0.0f, -5.0f); // to tank1 top end // x0 y0 z19
		glutSolidCylinder(2.0f, 5.0f, 20, 20); // fuel line tank1 top
		glTranslatef(0.0f, 0.0f, 5.0f);// to bottom tank1 fuel line // x0 y0 z24
		glutSolidSphere(2.0f, 20, 20); //tip of tank1 fuel line
		glPushMatrix();//2
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			glutSolidCylinder(2.0f, 10.0f, 20, 20); // cross fuel line
		glPopMatrix();//2
		glTranslatef(5.0f, 0.0f, 0.0f); //to middle of cross fuel line //x5 y0 z24
		glutSolidCylinder(2.0f, 5.0f, 20, 20); // middle fuel valve
		glTranslatef(0.0f, 0.0f, 5.0f); // to end of middle fuel valve //x5 y0 z24
		glutSolidCone(2.0f, 2.0f, 20, 20); //tip of fuel valve
		glTranslatef(0.0f, 0.0f, -3.0f); //x5 y0 z21
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f); // black hose begins 
		glutSolidCylinder(1.0f, 3.0f, 20, 20);//
		glTranslatef(0.0f, 0.0f, 3.0f);//z24
		glutSolidCylinder(1.0f, 3.0f, 20, 20);//1
		glTranslatef(0.0f, 0.0f, 3.0f);//z27
		glutSolidCylinder(1.0f, 3.0f, 20, 20);//2
		glTranslatef(0.0f, 0.0f, 3.0f);//z30
		glutSolidCylinder(1.0f, 3.0f, 20, 20);//3
		glTranslatef(0.0f, 0.0f, 3.0f);
		glutSolidCylinder(1.0f, 3.0f, 20, 20);//4
		glTranslatef(0.0f, 0.0f, 3.0f); //z36
		glutSolidCylinder(1.0f, 3.0f, 20, 20);//5
		glPushMatrix();//3
			glScalef(1.25f, 1.0f, 2.0f);
			glColor3f(0.0, 0.0f, 1.0f);
			glutSolidCylinder(2.0f, 4.0f, 20, 20);
		glPopMatrix();//3
		glTranslatef(0.0f, 0.0f, 4.0f); //x5 y0 z40
	
				
	glEndList();
}

void FlameThrower::Reset(){
	fireOn = false;
	FTcount = 0;
	bRunning = false;
}



