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
#include "Functions.h"
#include "Fire.h"

extern GLfloat starX, starY, starZ;

Fire::Fire(){};
void Fire::Pos()
{
	for(int p = 0; p < MAX_PARTICLES; ++p){
			
			
			glBegin(GL_POINTS);
				
				for (int i = 0; i < 25; ++i)
				{
					glColor3f(1.0f, 0.777f, 0.0f);
					Particles[p].X += rand()%5/100.0f - 0.02f;
					Particles[p].Y += rand()%5/100.0f;
					Particles[p].Z += rand()%5/100.0f - 0.02f; 
					glVertex3f(Particles[p].X, Particles[p].Y, Particles[p].Z);
					Particles[p].B -= 0.1f;
					if(Particles[p].B <= 0.0f){
						Particles[p].G -= 0.1f;
						if(Particles[p].G <= 0.0f)
						{
							Particles[p].InitParticle();
						}
					}
					
			
				}
				
			glEnd();
			
	}
	
}

void Fire::Neg()
{

	for(int p = 0; p < MAX_PARTICLES; ++p){
			
			
			glBegin(GL_POINTS);
				
				for (int i = 0; i < 25; ++i)
				{
					glColor3f(1.0f, 0.777f, 0.0f);
					Particles[p].X += rand()%5/100.0f - 0.02f;
					Particles[p].Y += rand()%5/-100.0f;
					Particles[p].Z += rand()%5/100.0f - 0.02f; 
					glVertex3f(Particles[p].X, Particles[p].Y, Particles[p].Z);
					Particles[p].B -= 0.1f;
					if(Particles[p].B <= 0.0f){
						Particles[p].G -= 0.1f;
						if(Particles[p].G <= 0.0f)
						{
							Particles[p].InitParticle();
						}
					}
			
			}
				
			glEnd();
							
	}
}
	

void Fire::Neu()
{

	for(int p = 0; p < MAX_PARTICLES; ++p){
			
			
			glBegin(GL_POINTS);
				
				for (int i = 0; i < 25; ++i)
				{
					glColor3f(1.0f, 0.777f, 0.0f);
					Particles[p].X += rand()%222/1000.0f - 0.111f;
					Particles[p].Y += rand()%222/1000.0f - 0.111f;
					Particles[p].Z += rand()%222/1000.0f - 0.111f; 
					glVertex3f(Particles[p].X, Particles[p].Y, Particles[p].Z);
					
				}
				
			glEnd();
			
	}
	
}