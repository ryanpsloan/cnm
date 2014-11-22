#include <gl/freeglut.h>
#include "tAxis.h"

tAxis::tAxis()
{
	distance = 100.0f;
	increment = 10.0f;
	lineWidth = 1.0f;
	tickLength = 5.0f;
	isVisible = true;
	Label = true;
	DrawTicks = true;
	for(int i = 0; i < 3; i++)
	{
		axis[i] = true;
		for(int j = 0; j < 3; j++)
		{
			color[i][j] = 1.0f;
		}
	}
}
void tAxis::Draw()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	if(!isVisible)
	{
		return;
	}
	glLineWidth(lineWidth);

	glBegin(GL_LINES);
		if(axis[XAXIS])
		{
			glColor3fv(color[XAXIS]);
			glVertex3f(-distance,0.0f,0.0f);
			glVertex3f(distance,0.0f,0.0f);
		}
		if(axis[YAXIS])
		{
			glColor3fv(color[YAXIS]);
			glVertex3f(0.0f,-distance,0.0f);
			glVertex3f(0.0f,distance,0.0f);
		}
		if(axis[ZAXIS])
		{
			glColor3fv(color[ZAXIS]);
			glVertex3f(0.0f,0.0f,-distance);
			glVertex3f(0.0f,0.0f,distance);
		}
		if(DrawTicks)
		{
			for(GLfloat i = -distance; i <= distance; i += increment)
			{
				if(i >= -tickLength &&  i <= tickLength)
				{
					continue;
				}
				if(axis[XAXIS])
				{
					glColor3fv(color[XAXIS]);
					glVertex3f(i,-tickLength,0.0f);
					glVertex3f(i,tickLength,0.0f);
				}
				if(axis[YAXIS])
				{
					glColor3fv(color[YAXIS]);
					glVertex3f(-tickLength,i,0.0f);
					glVertex3f(tickLength,i,0.0f);
				}
				if(axis[ZAXIS])
				{
					glColor3fv(color[ZAXIS]);
					glVertex3f(0.0f,-tickLength,i);
					glVertex3f(0.0f,tickLength,i);
				}
			}
		}
	glEnd();
	if(Label)
	{
		if(axis[XAXIS])
		{
			glColor3fv(color[XAXIS]);
			glRasterPos3f(distance+3.0f,-2.0f,0.0f);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'X');
		}
		if(axis[YAXIS])
		{
			glColor3fv(color[YAXIS]);
			glRasterPos3f(-2.0f,distance+3.0f,0.0f);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'Y');
		}
		if(axis[ZAXIS])
		{
			glColor3fv(color[ZAXIS]);
			glRasterPos3f(-3.0f,-2.0f,distance+2.5f);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'Z');
		}
	}
	glPopAttrib();
}

void tAxis::SetAxisColor(int AI, GLfloat r, GLfloat g, GLfloat b)
{
	if((AI < 0) || (AI > 2))
		return;
	color[AI][0] = r;
	color[AI][1] = g;
	color[AI][2] = b;
}
bool tAxis::GetAxis(int AI)
{
	if((AI<0)||(AI > 2))
		return false;
	return axis[AI];
}
void tAxis::SetAxis(int AI, bool Value)
{
	if((AI < 0) || (AI > 2))
		return;
	axis[AI] = Value;
}
void tAxis::SetAxis(bool Value)
{
	for(int i = 0 ; i < 3; i++)
		axis[i] = Value;
}
void tAxis::SetAxisColor(GLfloat r, GLfloat g, GLfloat b)
{
	for(int i = 0; i < 3; i++)
	{
		color[i][0] = r;
		color[i][1] = g;
		color[i][2] = b;
	}
}


