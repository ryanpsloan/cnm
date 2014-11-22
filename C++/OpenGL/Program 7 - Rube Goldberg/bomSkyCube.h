//Bresdin O'Malley 
//bomalley2@cnm.edu
//Cube.cpp
//Program 4 Teapot Forest, objects, glCallLists, Translation, scaling and lighting
//OpenGL

#ifndef _CUBE_H
#define _CUBE_H

#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include <windows.h>		// Must have for Windows platform builds
#include <gl/glut.h>		// Glut(Free-Glut on Windows)
#include <stdio.h>


class SkyBox
{
private:
	GLuint index;
	GLuint skybox[6];
	//-------------------------- To use texture mapping
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;

public:
	SkyBox();
	void DrawSky();
	void DrawScene();
	void DrawSkybox(double D);
	void DrawBeach();
	void CallList();
	
};

#endif
