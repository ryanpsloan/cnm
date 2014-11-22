//Ryan Sloan
//Star Class 
// - SloanP6 -
//OpenGL
//CIS 2270
//rsloan2@cnm.edu

#include <windows.h>		// Must have for Windows platform builds
#include <gl\gl.h>			// Microsoft OpenGL headers (version 1.1 by themselves)
#include <gl\glu.h>			// OpenGL Utilities
#include <gl\glut.h>
#include "Particle.h"
#include "Functions.h"
#include "ParticleEngine.h"
#include "Star.h"
#include "Space.h"
#include "Snow.h"

Snow::Snow(){}
void Snow::LetItSnow()
{
	for(int p = 0; p < MAX_SNOWFLAKES; ++p){
			
		glColor3f(SnowFlakes[p].R, SnowFlakes[p].G, SnowFlakes[p].B);	
		SnowFlakes[p].Y += rand()%3/-1.0f;	
		glBegin(GL_POINTS);
		
			SnowFlakes[p].X += rand()%5/100.0f-0.2f;
			SnowFlakes[p].Z += rand()%5/100.0f-0.2f;
			
			glVertex3f(SnowFlakes[p].X, SnowFlakes[p].Y, SnowFlakes[p].Z);
		
		glEnd();
		SnowFlakes[p].Y += rand()%3/-1.0f;
		glBegin(GL_POINTS);
		
			SnowFlakes[p].X += rand()%5/100.0f-0.2f;
			SnowFlakes[p].Z += rand()%5/100.0f-0.2f;
			
			glVertex3f(SnowFlakes[p].X, SnowFlakes[p].Y, SnowFlakes[p].Z);
		
		glEnd();
		glBegin(GL_POINTS);
		
			SnowFlakes[p].X += rand()%5/100.0f-0.2f;
			SnowFlakes[p].Z += rand()%5/100.0f-0.2f;
			
			glVertex3f(SnowFlakes[p].X, SnowFlakes[p].Y, SnowFlakes[p].Z);
		
		glEnd();
		SnowFlakes[p].Y += rand()%3/-1.0f;
		glBegin(GL_POINTS);
		
			SnowFlakes[p].X += rand()%5/100.0f-0.2f;
			SnowFlakes[p].Z += rand()%5/100.0f-0.2f;
			
			glVertex3f(SnowFlakes[p].X, SnowFlakes[p].Y, SnowFlakes[p].Z);
		
		glEnd();
		SnowFlakes[p].Y += rand()%3/-1.0f;
		glBegin(GL_POINTS);
		
			SnowFlakes[p].X += rand()%5/100.0f-0.2f;
			SnowFlakes[p].Z += rand()%5/100.0f-0.2f;
			
			glVertex3f(SnowFlakes[p].X, SnowFlakes[p].Y, SnowFlakes[p].Z);
		
		glEnd();
		SnowFlakes[p].Y += rand()%3/-1.0f;
		glBegin(GL_POINTS);
		
			SnowFlakes[p].X += rand()%5/100.0f-0.2f;
			SnowFlakes[p].Z += rand()%5/100.0f-0.2f;
			
			glVertex3f(SnowFlakes[p].X, SnowFlakes[p].Y, SnowFlakes[p].Z);
		
		glEnd();
		SnowFlakes[p].Y += rand()%3/-1.0f;
		glBegin(GL_POINTS);
		
			SnowFlakes[p].X += rand()%5/100.0f-0.2f;
			SnowFlakes[p].Z += rand()%5/100.0f-0.2f;
			
			glVertex3f(SnowFlakes[p].X, SnowFlakes[p].Y, SnowFlakes[p].Z);
		
		glEnd();
		glBegin(GL_POINTS);
		
			SnowFlakes[p].X += rand()%5/100.0f-0.2f;
			SnowFlakes[p].Z += rand()%5/100.0f-0.2f;
			
			glVertex3f(SnowFlakes[p].X, SnowFlakes[p].Y, SnowFlakes[p].Z);
		
		glEnd();
		glBegin(GL_POINTS);
		
			SnowFlakes[p].X += rand()%5/100.0f-0.2f;
			SnowFlakes[p].Z += rand()%5/100.0f-0.2f;
			
			glVertex3f(SnowFlakes[p].X, SnowFlakes[p].Y, SnowFlakes[p].Z);
		
		glEnd();
		SnowFlakes[p].Y += rand()%3/-1.0f;
		glBegin(GL_POINTS);
		
			SnowFlakes[p].X += rand()%5/100.0f-0.2f;
			SnowFlakes[p].Z += rand()%5/100.0f-0.2f;
			
			glVertex3f(SnowFlakes[p].X, SnowFlakes[p].Y, SnowFlakes[p].Z);
		
		glEnd();
			
		if(SnowFlakes[p].Y < 2.0f){
				SnowFlakes[p].InitSnowFlake();
		}
	}
	
}