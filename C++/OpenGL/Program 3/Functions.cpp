//Bounce.cpp
//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
//this to avoid the black console window
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

#include <iostream>
#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>		// Glut (Free-Glut on Windows)
#include "Functions.h"         

using namespace std;

extern GLboolean planesOn;
extern GLboolean axesOn;
extern GLboolean triangleFanOn;
extern GLboolean allItemsOn;
extern GLboolean depthTestingOn;
extern GLboolean teapotOn;
extern GLint toggleTeapot;
extern GLboolean toggleFrontFace;
extern GLboolean toggleBackFace;

extern GLint changeColor;
extern GLfloat r, g, b;
extern GLfloat sizeOfTeapot;//used in renderscene
extern GLint width, height;//used to keep track of w and h globally

extern GLfloat eyex, eyey, eyez;
extern GLint azimuth, elevation, radius;
extern GLint iPivot;

///////////////////////////////////////////////////////////
// Called to draw scene
void RenderScene(void)
{
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	CalculateEye();
	gluLookAt(eyex, eyey, eyez, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//toggle glPolygonMode
	
	if (toggleFrontFace)
		glPolygonMode(GL_FRONT, GL_FILL);
	else
		glPolygonMode(GL_FRONT, GL_LINE);
	
	if (toggleBackFace)
		glPolygonMode(GL_BACK, GL_FILL);
	else
		glPolygonMode(GL_BACK, GL_LINE);
	
	//toggle depth testing
	if(depthTestingOn)
		glEnable(GL_DEPTH_TEST);
	else 
		glDisable(GL_DEPTH_TEST);
	//toggle all items
	if(allItemsOn) {
		//toggle axis planes
		if(planesOn) {
			//Draw red plane on xy axis
			glColor3f(1.00f, 0.00f, 0.00f);
			glBegin(GL_POLYGON);
				glVertex3f(100.0, 100.0, 0.0);
				glVertex3f(100.0, -100.0, 0.0);
				glVertex3f(-100.0, -100.0, 0.0);
				glVertex3f(-100.0, 100.0, 0.0);
			glEnd();
	
			//Draw green plane on yz axis
   			glColor3f(0.00f, 1.00f, 0.00f);
			glBegin(GL_POLYGON);
				glVertex3f(0.0, 100.0, -100.0);
				glVertex3f(0.0, -100.0, -100.0);
				glVertex3f(0.0, -100.0, 100.0);
				glVertex3f(0.0, 100.0, 100.0);
			glEnd();

			//Draw blue plane on xz axis		
			glColor3f(0.00f, 0.00f, 1.00f);
			glBegin(GL_POLYGON);
				glVertex3f(-100.0, 0.0, -100.0);
				glVertex3f(100.0, 0.0, -100.0);
				glVertex3f(100.0, 0.0, 100.0);
				glVertex3f(-100.0, 0.0, 100.0);
			glEnd();
		}

		//toggle axes
		if(axesOn) {
			//draw axes
			glLineWidth(1.5); 
			glBegin(GL_LINES);
			//x y z axis
				//x red
				glColor3f(1.0f,0.0f,0.0f);
				glVertex3f(150.0, 0.0, 0.0);
				glVertex3f(-150.0, 0.0, 0.0);
				//y	green
				glColor3f(0.0f,1.0f,0.0f);
				glVertex3f(0.0, 150.0, 0.0);
				glVertex3f(0.0, -150.0, 0.0);
				//z blue
				glColor3f(0.0f,0.0f,1.0f);
				glVertex3f(0.0, 0.0, 150.0);
				glVertex3f(0.0, 0.0, -150.0);
			glEnd();
		}

		//toggle Triangle fans		
		if(triangleFanOn){	
		
			//Triangle fans
			//bottom fan
			glBegin(GL_TRIANGLE_FAN);
				
				glVertex3f(0.0f, -30.0f, 0.0f);  //fan origin

				for(GLfloat angle = 0.0f; angle < (2.0f * PI); angle += (PI/6.0f))
				{
					GLfloat xtri = 90.0f*sin(angle);
					GLfloat ytri = 90.0f*cos(angle);
			
					// Alternate colors
					if((iPivot%2) == 0)
						glColor3f(1.0f, 1.0f, 0.0f);
					else
						glColor3f(1.0f, 0.0f, 1.0f);
					// Increment pivot to change color next time
					iPivot++;
					glVertex3f(xtri, -30.0, ytri);  // Specify the next vertex for the triangle fan

				}

			glEnd();

			//3D Triangle Fan
			glBegin(GL_TRIANGLE_FAN);
	      
				glVertex3f(0.0f, 90.0f, 0.0f);  //fan origin

				for(GLfloat angle = 0.0f; angle < (2.0f * PI); angle += (PI/6.0f))
				{
					GLfloat xtri = 90.0f*sin(angle);
					GLfloat ytri = 90.0f*cos(angle);
			
					// Alternate colors
					if((iPivot%2) == 0)
						glColor3f(1.0f, 1.0f, 0.0f);
					else
						glColor3f(1.0f, 0.0f, 1.0f);
					// Increment pivot to change color next time
					iPivot++; 
					glVertex3f(xtri, -30.0, ytri);  // Specify the next vertex for the triangle fan

				}
			glEnd();
		}

		//toggle teapot 
		if(teapotOn){
			//Draw color changing teapot
			glColor3f(r, g, b);
			
			if(toggleTeapot == 0)
				glutWireTeapot(sizeOfTeapot);
			else if(toggleTeapot == 1) 
				glutSolidTeapot(sizeOfTeapot);
			//else toggleTeapot > 1
				//no teapot
				//next click resets to 0
		}
	}
	// Flush drawing commands and swap
    glutSwapBuffers();
}

///////////////////////////////////////////////////////////
// Called by GLUT library when idle (window not being
// resized or moved)
void TimerFunction(int value)
{
	changeColor += 5;
	if(changeColor %13 == 0)
	{
		r += 0.05f;
		if(r > 1.0f)
			r = 0.15f;
		g += 0.05f;
		if(g > 1.0f)
			g = 0.15f;
		b += 0.05f;
		if(b > 1.0f)
			b = 0.15f;

	}
	
	glutKeyboardFunc(ChangeFunction);
	glutSpecialFunc(SpecialKeys);
     // Redraw the scene with new coordinates
    glutPostRedisplay();
    glutTimerFunc(33,TimerFunction, 1);
}


///////////////////////////////////////////////////////////
// Setup the rendering state
void SetupRC(void)
{
    // Set clear color 
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glShadeModel(GL_FLAT);
}


///////////////////////////////////////////////////////////
// Called by GLUT library when the window has chanaged size
void ChangeSize(int w, int h)
{
	width = w;
	height = h;
    //GLfloat aspectRatio;

    // Prevent a divide by zero
    if(h == 0)
        h = 1;
		
    // Set Viewport to window dimensions
  	glViewport(0, 0, w, h);
		
    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

   	gluPerspective(90.0, 1.0, 10.0, 400.0); //only takes four arguments

	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void ChangeFunction(GLubyte key, GLint x, GLint y)
{
	if(key == 'f'){
		radius -= 3;
		if (radius <= 0)
		{
			radius  = 0;
		}
	}
	if(key == 'b'){
		radius += 3;
		if (radius >= 400)
		{
			radius = 400;
		}
	}
}	

void CalculateEye()
{
	GLfloat e = elevation * PI / 180.0f;
	GLfloat a = azimuth * PI / 180.0f;
	eyex = radius * cos(e);
	eyey = radius * sin(e);
	eyez = eyex * sin(a);
	eyex = eyex * cos(a);
	
}

void SpecialKeys(int key, int x, int y)
{
	if(key == GLUT_KEY_UP){
		elevation += 3;
		if(elevation >= 89)
		{
			elevation = 89;
		}
		
	}
	if(key == GLUT_KEY_DOWN){
		elevation -= 3;
		if(elevation <= -89)
		{
			elevation = -89;
		}
	}
	if(key == GLUT_KEY_LEFT){
		azimuth += 3;
		if(azimuth >= 359) {
			azimuth = 359;
		}
	}
	if(key == GLUT_KEY_RIGHT){
		azimuth -= 3;
		if(azimuth <= 1){
			azimuth = 1;
		}
	}
}

void SetupMenus()
{
	GLint teapotSubMenu = glutCreateMenu(MenuHandler);
	glutAddMenuEntry("Toggle Wire/Solid teapot", TOGGLE_WIRE);
	glutAddMenuEntry("Toggle Teapot on/off", TOGGLE_TEAPOT);

	GLint objectSubMenu = glutCreateMenu(MenuHandler);
	glutAddSubMenu("Teapot", teapotSubMenu);
	glutAddMenuEntry("Toggle Axes", TOGGLE_AXES);
	glutAddMenuEntry("Toggle Planes", TOGGLE_PLANES);
	glutAddMenuEntry("Toggle Triangle Fans", TOGGLE_TRIANGLES);
	glutAddMenuEntry("Show/Hide All", SHOW_HIDE );
	
	GLint polygonSubMenu = glutCreateMenu(MenuHandler);
	glutAddMenuEntry("Toggle Front Face", TOGGLE_FRONT_FACE);
	glutAddMenuEntry("Toggle Back Face", TOGGLE_BACK_FACE);
	glutAddMenuEntry("Toggle Front and Back Face", TOGGLE_FRONT_AND_BACK_FACE);
		
	GLint mainMenu = glutCreateMenu(MenuHandler);
	glutAddSubMenu("Object", objectSubMenu);
	glutAddSubMenu("Polygon", polygonSubMenu);
	glutAddMenuEntry("Toggle Depth Testing", TOGGLE_DEPTH_TESTING);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	

}

void MenuHandler(int menuEntryValue)
{
	switch(menuEntryValue)
	{
	case 101:
		axesOn = !axesOn;
		break;
	case 102:
		planesOn = !planesOn;
		break;
	case 103:
		triangleFanOn = !triangleFanOn;
		break;
	case 104:
		allItemsOn = !allItemsOn;
		break;
	
	case 201:
		toggleFrontFace = !toggleFrontFace;
		break;
	case 202:
		toggleBackFace = !toggleBackFace;
		break;
	case 203:
		toggleFrontFace = !toggleFrontFace;
		toggleBackFace = !toggleBackFace;
		break;

	case 301:
		depthTestingOn = !depthTestingOn;
		break;

	case 401:
		toggleTeapot += 1;
		if(toggleTeapot == 3)
		{
			toggleTeapot = 0;
		}
		break;
	case 402:
		teapotOn = !teapotOn;
		break;
	}
}




