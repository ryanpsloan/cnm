//Component.h

#ifndef COMPONENT_H
#define COMPONENT_H
#include <gl/freeglut.h>

class Component
{
	protected:
		GLfloat XPos, YPos, ZPos; //current position
		GLfloat RotAngle;
		float ColorR, ColorG, ColorB;
		bool bRunning, bStartNext;
		GLfloat DegreeStart,AngleXStart,AngleYStart,AngleZStart;
		GLfloat ScaleX ,ScaleY,ScaleZ;
		GLint index;

	public:
		Component();
		virtual void Draw() = 0;
		virtual void Update() = 0;
		virtual void Setup() = 0;
		virtual void Reset() = 0;
		
		void SetRunning(bool b) {bRunning = b;}
		void SetStartPos(float XStart, float YStart, float ZStart);
		void SetColor(float R, float G, float B);

		bool isTimeToStartNext() {return bStartNext;}
		bool isRunning() {return bRunning;}

		void SetScale(GLfloat x, GLfloat y, GLfloat z);
		void SetRotation(GLfloat degrees, GLfloat x, GLfloat y, GLfloat z);

};
#endif

