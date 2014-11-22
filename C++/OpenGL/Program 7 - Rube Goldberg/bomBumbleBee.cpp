//Bresdin O'Malley
//brezomalley@gmail.com
//bumblebee.cpp

#include "bomBumbleBee.h"
#include "Component.h"
#include <windows.h>
#include <gl/freeglut.h>
#include <stdio.h>
#include <math.h>
#define WING_POINTS 20
#define PI 3.14159265
#define ToRad(x) PI * x / 180.0f
#define ToDeg(x) 180.0f * x / PI

BumbleBee::BumbleBee() : Component()
{
	flyUp = false;
	fly = 0;

	previousTime = 0;

	Yaw = 90.0f;
}

void BumbleBee::Draw()
{
	//Call calllists aka render()
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();
	
		glTranslatef(XPos, YPos, ZPos);
		glScalef(ScaleX, ScaleY, ScaleZ);
		glRotatef(DegreeStart, AngleXStart, AngleYStart, AngleZStart);

		glRotatef(Yaw, 0.0, 1.0, 0.0);

			glPushMatrix();
				glTranslatef(0.0f, 10.0f, 0.0f);
				glCallList(index);			//Bee Body
			glPopMatrix();

			glPushMatrix();
				glRotatef(fly, 0, 0, 1);
				glCallList(index + 1);		//wings
			glPopMatrix();

			glPushMatrix();
				glRotatef(-fly, 0, 0, 1);
				glRotatef(180, 0, 1, 0);
				glCallList(index + 1);		//wings
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0.0f, 15.0f, 10.0f);
				glCallList(index + 2);		//head
			glPopMatrix();

			Update();

	glPopMatrix();
	glPopAttrib();
}

void BumbleBee::Update()
{
	//change positions

	double unit = (5);
	
	if (fly < -unit)
		flyUp = true;
	else if (fly > unit)
		flyUp = false;

	if (flyUp)
		fly += 5.0;
	else
		fly -= 5.0;

	//Check to see if it is bees turn to move
	if(bStartNext == true)
	{
		bStartNext = false;
	}

	if(bRunning == true)
	{
		//The bee needs to exit the hive and then 
		//fly towards the flower
		
		if(YPos >= 25.0)
		{
			//Move down the Y axis
			YPos -= 1.0;
		}
		else if(XPos <= 100.0)
		{
			//Move forward on the Z axis
			ForwardMove(.50);

			if(XPos >= 80.0)
			{
				AngleYStart = 1;
				DegreeStart += -1.0;
			}
		}
		else
		{
			bStartNext = true;
			bRunning = false;
		}
	}

}

void BumbleBee::Setup()
{
	SetTexture();

	//call lists here
	index = glGenLists(3);

	glNewList(index, GL_COMPILE);
		BeeBody();
	glEndList();

	glNewList(index + 1, GL_COMPILE);
		FullWing();
	glEndList();

	glNewList(index + 2, GL_COMPILE);
		BeeHead();
	glEndList();

	
}

void BumbleBee::Reset()
{
	//puts back at begining
}

void BumbleBee::BeeBody()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();

		GLUquadricObj * obj;
		obj = gluNewQuadric();
		glEnable(GL_TEXTURE_2D);
		gluQuadricTexture(obj, GL_TRUE);
		gluSphere(obj, 10, 20, 20);
		glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	glPopAttrib();
	gluDeleteQuadric(obj);

}

void BumbleBee::BeeHead()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
		 GLUquadricObj * obj2;
		obj2 = gluNewQuadric();

		//---------------------------- Head
		glColor3ub(255, 255, 0);
		glutSolidSphere(4, 15, 15);
		
		//----------------------------- Eye balls
		glPushMatrix();
			glTranslatef(1.5f, 3.0, 2.0f);
			glColor3ub(255, 255, 255);
			glutSolidSphere(1, 15, 15);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-1.5f, 3.0, 2.0f);
			glutSolidSphere(1, 15, 15);
		glPopMatrix();

		//----------------------------- PUPILS
		glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslatef(1.5f, 3.0f, 3.0f);
			gluQuadricDrawStyle(obj2, GLU_FILL); /* flat shaded */
			gluQuadricNormals(obj2, GLU_FLAT);
			gluDisk(obj2, 0.0, 0.40, 20, 4);
		glPopMatrix();

		glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslatef(-1.5f, 3.0f, 3.0f);
			gluQuadricDrawStyle(obj2, GLU_FILL); /* flat shaded */
			gluQuadricNormals(obj2, GLU_FLAT);
			gluDisk(obj2, 0.0, 0.40, 20, 4);
		glPopMatrix();
	
		//------------------------------- White reflection dots
		glPushMatrix();
			glColor3ub(255, 255, 255);
			glTranslatef(-1.65f, 3.0f, 3.02f);
			gluQuadricDrawStyle(obj2, GLU_FILL); /* flat shaded */
			gluQuadricNormals(obj2, GLU_FLAT);
			gluDisk(obj2, 0.0, 0.10, 20, 4);
		glPopMatrix();

		glPushMatrix();
			glColor3ub(255, 255, 255);
			glTranslatef(1.35f, 3.0f, 3.02f);
			gluQuadricDrawStyle(obj2, GLU_FILL); /* flat shaded */
			gluQuadricNormals(obj2, GLU_FLAT);
			gluDisk(obj2, 0.0, 0.10, 20, 4);
		glPopMatrix();

		//-------------------------------------- SMILE
		glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslatef(0.0f, 1.0f, 4.0f);
			gluQuadricDrawStyle(obj2, GLU_FILL); /* flat shaded */
			gluQuadricNormals(obj2, GLU_FLAT);
			gluPartialDisk(obj2, 1.40, 1.50, 20.0, 4.0, -90.0, -180.0);
		glPopMatrix();

		//-------------------------------- Antenna		
		glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslatef(1.5f, 7.0, 0.0f);
			glRotatef(90, 1, 0, 0);
			glutSolidCylinder(.1, 5, 15, 15);
		glPopMatrix();

		glPushMatrix();			
			glTranslatef(-1.5f, 7.0, 0.0f);
			glRotatef(90, 1, 0, 0);
			glutSolidCylinder(.1, 5, 15, 15);		
		glPopMatrix();

		glPushMatrix();			
			glTranslatef(-1.5f, 7.0, 0.0f);
			glutSolidCylinder(.1, 5, 15, 15);		
		glPopMatrix();

		glPushMatrix();			
			glTranslatef(1.5f, 7.0, 0.0f);
			glutSolidCylinder(.1, 5, 15, 15);		
		glPopMatrix();

		//------------------------------- Needle
		glPushMatrix();
			glColor3ub(176, 93, 30);
			glTranslatef(0.0f, -5.0f, -18.0f);
			glRotatef(180, 0, 1, 0);
			glutSolidCone(2, 5, 15, 15);
		glPopMatrix();

	glPopAttrib();

	gluDeleteQuadric(obj2);


}

void BumbleBee::Wing()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();
		//create 3 arrays

		Tri A[WING_POINTS];
		Tri B[WING_POINTS];
		Tri C[WING_POINTS];

		//---------------------------------- round tip of wing
		for(int i = 0; i <WING_POINTS; i++)
		{
			//Middle
			B[i].x = (-i/2.0f)+1; //-(i+(1.0f/(float)(i+1)))+1;
			B[i].y = 0;
			B[i].z = 0;
		}

		for(int i = 0; i < WING_POINTS; i++)
		{
			//- Side B
			A[i].x = (-i/2.0f)+1;
			A[i].y = 0;
			A[i].z = 8 - (i * i)/45.0;
		}

		for(int i = 0; i < WING_POINTS; i++)
		{
			//- Side A
			C[i].x = (-i/2.0f)+1;
			C[i].y = 0;
			C[i].z = -(8 - (i * i)/45.0);
		}

		glEnable(GL_BLEND);
		glDisable(GL_LIGHTING);
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		for(int i = 0; i < WING_POINTS-1; i++)
		{
			glBegin(GL_TRIANGLES);
				//-------------- Side A
				glNormal3f(0, 1, 0);
				glColor4ub(255, 255, 255, 80);
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
		
		for(int i =0; i <WING_POINTS-1; i++)
		{
			glBegin(GL_TRIANGLES);
				//---------- Side A
				glNormal3f(0, 1, 0);
					//White-->
				glColor4ub(255, 255, 255, 80);	
				glVertex3f(B[i].x, B[i].y, B[i].z);
					//Blue-->
				//glColor4ub(0, 0, 255, 95);
				glVertex3f(A[i + 1].x, A[i + 1].y, A[i + 1].z);
				glVertex3f(A[i].x, A[i].y, A[i].z);
				//---------- Side B
				glNormal3f(0, 1, 0);
				glVertex3f(B[i].x, B[i].y, B[i].z);
				glVertex3f(C[i + 1].x, C[i + 1].y, C[i + 1].z);
					//Blue-->
				//glColor4ub(0, 0, 255, 95);
				glVertex3f(C[i].x, C[i].y, C[i].z);
			glEnd();		
		}		

		for(int i = 0; i <WING_POINTS; i++)
		{
			//Middle
			B[i].x = i*2.0f+(1.0f/(float)(i+1))-3;
			B[i].y = 0;
			B[i].z = 0;
		}

		for(int i = 0; i < WING_POINTS; i++)
		{
			//- Side B
			A[i].x = i*1.8;
			A[i].y = 0;
			A[i].z = 8 - (i * i)/50.0;//(i * 5/16.0);
		}

		for(int i = 0; i < WING_POINTS; i++)
		{
			//Side A
			C[i].x = i*1.9;
			C[i].y = 0;
			C[i].z = -(8 - (i * i)/50.0);
		}

		glColor4ub(255, 255, 255, 80);
		for(int i = 0; i < WING_POINTS-1; i++)
		{
			glBegin(GL_TRIANGLES);
				//-------------- Side A
					//Blue-->
				//glColor4ub(0, 0, 255, 95);
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

		for(int i =0; i <WING_POINTS-1; i++)
		{
			glBegin(GL_TRIANGLES);
				//---------- Side A
				glNormal3f(0, 1, 0);
					//White-->
				glColor4ub(255, 255, 255, 80);	
				glVertex3f(B[i].x, B[i].y, B[i].z);
					//Blue-->
				//glColor4ub(0, 0, 255, 95);
				glVertex3f(A[i + 1].x, A[i + 1].y, A[i + 1].z);
					
				glVertex3f(A[i].x, A[i].y, A[i].z);

							
				//---------- Side B	
				glNormal3f(0, 1, 0);
				glVertex3f(B[i].x, B[i].y, B[i].z);				
				glVertex3f(C[i + 1].x, C[i + 1].y, C[i + 1].z);
				glVertex3f(C[i].x, C[i].y, C[i].z);
			
			glEnd();
		}
		
		//Blue-->
		//Draws the detail in the wing
		glPushMatrix();
			glTranslatef(-8.0f, 0.0f, 0.0f);
			glColor4ub(0, 0, 255, 50);
			glRotatef(90, 0, 1, 0);
			glutSolidCylinder(.20f, 35.0f, 15, 15);
		glPopMatrix();

		glPushMatrix();
			glColor4ub(0, 0, 255, 50);
			glRotatef(40, 0, 1, 0);
			glutSolidCylinder(.20f, 8.0f, 15, 15);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-5.0f, 0.0f, 0.0f);
			glColor4ub(0, 0, 255, 50);
			glRotatef(40, 0, 1, 0);
			glutSolidCylinder(.20f, 6.0f, 15, 15);
		glPopMatrix();

		glPushMatrix();	
			glTranslatef(10.0f, 0.0f, 0.0f);
			glColor4ub(0, 0, 255, 50);
			glRotatef(40, 0, 1, 0);
			glutSolidCylinder(.20f, 8.0f, 15, 15);
		glPopMatrix();

		glPushMatrix();	
			glTranslatef(2.0f, 0.0f, 0.0f);
			glColor4ub(0, 0, 255, 50);
			glRotatef(180, 1, 0, 0);
			glRotatef(40, 0, 1, 0);
			glutSolidCylinder(.20f, 8.0f, 15, 15);
		glPopMatrix();

		glPushMatrix();	
			glTranslatef(20.0f, 0.0f, 0.0f);
			glColor4ub(0, 0, 255, 50);
			glRotatef(180, 1, 0, 0);
			glRotatef(40, 0, 1, 0);
			glutSolidCylinder(.20f, 6.0f, 15, 15);
		glPopMatrix();
		
		glEnable(GL_LIGHTING);
		glDisable(GL_BLEND);
		
	glPopMatrix();
	glPopAttrib();
}

void BumbleBee::FullWing()
{
	glPushMatrix();
		glTranslatef(18.0f, 19.0f, 0.0f);
		glRotatef(180.0f, 0, 1, 0);
		glScalef(.40f, .40f, .40f);
		Wing();		//Wings	
	glPopMatrix();

	glPushMatrix();
		glTranslatef(18.0f, 19.01f, 0.0f);
		glRotatef(180.0f, 0, 1, 0);
		glScalef(.40f, .40f, .40f);
		Wing();		//Wings	
	glPopMatrix();	

	glPushMatrix();
		glTranslatef(13.0f, 19.0f, 3.0f);
		glRotatef(160.0f, 0, 1, 0);
		glScalef(.30f, .20f, .30f);
		Wing();		//Wings	
	glPopMatrix();

	glPushMatrix();
		glTranslatef(13.0f, 19.01f, 3.0f);
		glRotatef(160.0f, 0, 1, 0);
		glScalef(.30f, .30f, .30f);
		Wing();		//Wings	
	glPopMatrix();	
}
void BumbleBee::MoveWings()
{
	double unit = (3);
	

	if (fly < -unit)
		flyUp = true;
	else if (fly > unit)
		flyUp = false;

	if (flyUp)
		fly += 1;
	else
		fly -= 1;
}

void BumbleBee::ForwardMove(GLfloat unit)
{
	XPos += sin(ToRad(Yaw)) * unit;
	ZPos += cos(ToRad(Yaw)) * unit;
}

void BumbleBee::Rotate(GLfloat angle)
{
	Yaw += angle;

	if(Yaw > 360.0f)
		Yaw -= 360.0f;
	else if(Yaw < 0.0f)
		Yaw += 360.0f;
}


GLuint BumbleBee::loadBMP_custom(const char * imagepath)
{
	//Put these as file scope
	//GLuint image = loadBMP_custom("./my_texture.bmp");

	////First, we’ll need some data. These variable will be set when reading the file.
	//// Data read from the header of the BMP file
	//unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	//unsigned int dataPos;     // Position in the file where the actual data begins
	//unsigned int width, height;
	//unsigned int imageSize;   // = width*height*3
	//// Actual RGB data
	//unsigned char * data;

	//We now have to actually open the file
	// Define the file object  (from C)
	//Object type that identifies a stream and contains the information needed to control it, 
	//including a pointer to its buffer, its position indicator and all its state indicators.

	FILE * file ;

	//Open the file.  These are the access modes:
	//"r" read: Open file for input operations. The file must exist. 
	//With the mode specifiers above the file is open as a text file. 
	//In order to open a file as a binary file, a "b" character has to be 
	//included in the mode string. 

	fopen_s(&file, imagepath,"rb");
	if (!file)                              
	{
		printf("Image could not be opened\n");
		return 0;
	}

	/*The first thing in the file is a 54-bytes header. It contains information such as 
	“Is this file really a BMP file?”, the size of the image, the number of bits per pixel, 
		etc. So let’s read this header :*/
	if ( fread(header, 1, 54, file)!=54 )
	{ // If not 54 bytes read : problem
    printf("Not a correct BMP file\n");
    return false;
	}

	//The header always begins by BM. So we have to check that the two first bytes are really ‘B’ and ‘M’ :
 
	if ( header[0]!='B' || header[1]!='M' )
	{
		printf("Not a correct BMP file\n");
		return 0;
	}
 
	//Now we can read the size of the image, the location of the data in the file, etc : 
	// Read ints from the byte array
	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);

	//We have to make up some info if it’s missing :
	 // Some BMP files are misformatted, guess missing information
	if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos==0)      dataPos=54; // The BMP header is done that way

	//Now that we know the size of the image, we can allocate some memory to read the image into, and read : 
	// Create a buffer
	data = new unsigned char [imageSize];
 
	// Read the actual data from the file into the buffer
	fread(data,1,imageSize,file);
 
	//Everything is in memory now, the file can be closed
	fclose(file);
 
	//We arrive now at the real OpenGL part. Creating textures is very similar to creating vertex buffers : 
	//Create a texture, bind it, fill it, and configure it.

	/*In glTexImage2D, the GL_RGB indicates that we are talking about a 3-component color, 
	and GL_BGR says how exactly it is represented in RAM. As a matter of fact, BMP does not store 
	Red->Green->Blue but Blue->Green->Red, so we have to tell it to OpenGL.*/

	//IN: No longer defined in Windows, but GL_BGR_EXT is, or use the additional header

	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);
 
	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);
 
	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);

 
	//Default fltering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


	//We’ll explain those last two lines later. Meanwhile, on the C++-side, you can use your new function to load a texture :
	//GLuint Texture = loadBMP_custom("uvtemplate.bmp");
	return textureID;
}


/*********************************************************************************************/
void BumbleBee::SetTexture()
{
	//GLubyte *bits = nullptr;
	//BITMAPINFO * info;
	Texture = loadBMP_custom("black_yellow.bmp");

	//// Set the current texture
	glBindTexture(GL_TEXTURE_2D, 1);
	// Set the state for the current texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	// Set how the current texture is mapped
	glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_DECAL);
	// Set the bits that make up the current texture
	glTexImage2D(GL_TEXTURE_2D, 0,  GL_RGB,
				width, height,	0,	GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
 }
/*********************************************************************************************/