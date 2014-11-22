//Bresdin O'Malley
//brezomalley@gmail.com
//tree.h
//This tree will be placed in the middle of the scene and will be used for two 
//steps in the rube gold.

#ifndef TREE_H
#define TREE_H

#include <windows.h>
#include <gl/freeglut.h>
#include <math.h>
#include <gl/glut.h>
#include "Component.h"


struct Tri3D
{
	//This struct helps draw the leaves so that x, y, z can be set
	GLfloat x, y, z;
};

class Tree : public Component
{
private:
	GLfloat topSize, bottomSize, swing;
	GLboolean swingForward, moveTree;
	GLuint index, treeCount;
	GLUquadricObj *qobj;

public:
	Tree();
	//Tree(GLfloat x, GLfloat z, GLfloat yaw=0.0);

	//////////////////////////////////////////////

	void Draw();
	void Update();
	void Setup();
	void Reset();

	void Trunk();
	void Leaves();
	void LeafBunch();
	void Hive();
	void LeafMovement(); //move the leaves like wind
	//void ObjectSize(GLfloat s){size = s;} // to scale correctly
	//void GetMyPos(GLfloat &rX, GLfloat &rY, GLfloat &rZ);
};

#endif
