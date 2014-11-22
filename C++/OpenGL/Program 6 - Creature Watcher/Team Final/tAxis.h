#include <gl/freeglut.h>
/************************************************************************
Programmer: Aaron "Tomrel" Gresham

Glut Demo:
1) In the driver include this header file
        #include "tAxis.h"
2) above the main function create an instance of the axis
		tAxis axis;
3) extern over to any cpp that may require the axis (functions.cpp)
	also, include this header whereever you use.
		extern tAxis axis;
4) Set up the axis however you wish with the various Set functions
		axis.SetAxisColor(XAXIS, 1.0f, 0.0f, 0.0f);
		axis.SetIncrement(10.0f);
		...etc...
5) where ever you wanna Draw the axis use the axis.Draw function
	the Axis will draw at the current (0,0,0) on the matrix stack.
		axis.Draw();

wx Demo:
1) In your derived wxGLCanvas class header file 
	include this header file.
		#include "tAxis.h"
2) create an instance of this class as a class member.
		tAxis axis
3) In your classes constructor or where you initialize your OpenGL
	you can set up the axis using the various set functions
		axis.SetAxisColor(XAXIS, 1.0f, 0.0f, 0.0f);
		axis.SetIncrement(10.0f);
		...etc...
4) where ever you wanna Draw the axis use the axis.Draw function
	the Axis will draw at the current (0,0,0) on the matrix stack.
		axis.Draw();
*********************************************************************/

#ifndef __TAXIS__
#define __TAXIS__


//you can use these definitions \
//where it askes for the "axis index"
#define XAXIS 0
#define YAXIS 1
#define ZAXIS 2

class tAxis
{
private:
	GLfloat distance;
	GLfloat increment;
	GLfloat lineWidth;
	GLfloat tickLength;
	GLfloat color[3][3];
	bool axis[3];
	bool Label;
	bool isVisible;
	bool DrawTicks;




public:
	tAxis();
	//Set Distance from origin
	void SetDistance(GLfloat d) { distance = d; }
	//set how far to increment each tick mark
	void SetIncrement(GLfloat i) { increment = i; }
	//sets line width
	void SetLineWidth(GLfloat lw) { lineWidth = lw; }
	//sets how long the tick marks are from the axis line
	void SetTickLength(GLfloat tl) { tickLength = tl; }
	//turns specific axis on or off
	void SetAxis(int AI, bool Value);
	//turns every axis on or off
	void SetAxis(bool Value);
	//change color of specific axis
	void SetAxisColor(int AI, GLfloat r, GLfloat g, GLfloat b);
	//changes color of all axis
	void SetAxisColor(GLfloat r, GLfloat g, GLfloat b);
	// shows x y and z labels
	void ShowLabel() { Label = true; }
	//hides the labels
	void HideLabel() { Label = false; }
	//turn on tick marks
	void ShowTicks() { DrawTicks = true; }
	// turn off tick marks
	void HideTicks() { DrawTicks = false; }
	// toggle the labels
	void ToggleLabel() { Label = !Label; }
	// shows the axis
	void Show() { isVisible = true; }
	//hides the axis
	void Hide() { isVisible = false; }
	// is axis shown
	bool GetAxis(int AI);
	GLfloat GetTickLength() { return tickLength; }
	GLfloat GetDistance() { return distance; }
	GLfloat GetIncrement() { return increment; }
	GLfloat GetLineWidth() { return lineWidth; }
	//draws the axis centered at current (0,0,0)
	void Draw();
};

#endif
