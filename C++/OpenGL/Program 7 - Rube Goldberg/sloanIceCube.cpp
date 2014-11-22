#include <windows.h>		// Must have for Windows platform builds
#include <gl\freeglut.h>
#include "Functions.h"
#include "sloanIceCube.h"
//#include <iostream>
using namespace std;

GLfloat vert[][3] = 
	{
		{-1,-1,-1},
		{-1,1,-1},
		{-1,1,1},
		{-1,-1,1},
		{1,-1,-1},
		{1,1,-1},
		{1,1,1},
		{1,-1,1},
	};
	int side[][4] =
	{
		{0,1,5,4},			//front face
		{3,7,6,2},			//Back face
		{3,2,1,0},			//Right face
		{4,5,6,7},			//Left face
		{1,2,6,5},			//Top face
		{0,4,7,3},			//Back face
	};
	GLfloat cColor[8][3] =
	{
		{1,1,1},			
		{0.5,0.5,0.5},
		{0,0,1},			
		{0.5,0.5,0.5},			
		{0,0,1},			
		{0.5,0.5,0.5},	
		{1,1,1},			
		{0.5,0.5,0.5} 
	};

IceCube::IceCube(){
	cubeScale = 0.02f;
	puddleScale = 0.2f;
	cSize = 4.2f;
	pSize = 10.0f;
	XPos = 0.0f;
	YPos = 0.0f;
	ZPos = -60.0f;
	bRunning = false;
	ICcount = 0;
}

void IceCube::Draw(){

	glPushAttrib(GL_ALL_ATTRIB_BITS);

		glPushMatrix(); //3
			glScalef(4.2f, cSize, 4.2f);
			glTranslatef(0.0f, 10.0f, 0.0f);
			glCallList(index);
		glPopMatrix(); //3
		glPushMatrix();//4
			glColor4f(0.0f, 0.0f, 1.0f, 0.5);
			glScalef(2.5f, 0.015f, 2.5f);
			glutSolidSphere(pSize, 20, 20);
		glPopMatrix(); //4

	glPopAttrib();
}

void IceCube::Update(){
	ICcount++;
	//cout << "ICcount: " << ICcount << " ";
	cSize -= cubeScale;
	pSize += puddleScale;
	if(pSize >= 50.0)
		pSize = 50.0f;
	//cout << "cSize: " << cSize << "   ";
	//cout << "pSize: " << pSize << "   ";
	if(cSize <= 0.001f){
		cSize = 0.001f;
		bRunning = false;
		bStartNext = true;
	}
}	
			
void IceCube::Setup(){
	index = glGenLists(1);
	glNewList(index, GL_COMPILE);
		
		glTranslatef(XPos, YPos, ZPos);
		glScalef(ScaleX, ScaleY, ScaleZ);
		glRotatef(DegreeStart, AngleXStart, AngleYStart, AngleZStart);
		
		glPushMatrix();//1
		for(int a = 0; a < 6; a++)
		{
			glBegin(GL_POLYGON);
				for(int i = 0; i < 4; i++)
				{
					GLfloat x = vert[side[a][i]][0];
					GLfloat y = vert[side[a][i]][1]; //draw verticies of ice cube
					GLfloat z = vert[side[a][i]][2]; //code borrowed from Bresdin
					glColor3fv(cColor[side[a][i]]);
					glVertex3f(x*10, y*10, z*10);
				}
			glEnd();
		}
		glPopMatrix();//1
	glEndList();

	
}
void IceCube::Reset(){
		ICcount = 0;
		cSize = 2.5f;
		pSize = 1.0f;
		bRunning = false;
}