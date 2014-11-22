//Ryan Sloan
//Particle Definition for Particle Engine 
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

using namespace std;

ParticleEngine::ParticleEngine(){

	
}

void ParticleEngine::Pos()
{
	for(int p = 0; p < MAX_PARTICLES; ++p){
			glColor4f(Particles[p].R, Particles[p].G, Particles[p].B, 1.0);	
			
			glBegin(GL_POINTS);
				
				for (int i = 0; i < 25; ++i)
				{
					Particles[p].X += rand()%25/100.0f - 0.12f;
					Particles[p].Y += rand()%5/100.0f;
					Particles[p].Z += rand()%25/100.0f - 0.12f; 
					glVertex3f(Particles[p].X, Particles[p].Y, Particles[p].Z);
					
				}
				
			glEnd();
			if(Particles[p].Y < 0.75f)
			{
				if(Particles[p].X > 0.0f)
					Particles[p].X -= 1.0f;
				else
					Particles[p].X += 1.0f;
				
				if(Particles[p].Z > 0.0f)
					Particles[p].Z -= 1.0f;
				else
					Particles[p].Z += 1.0f;
			}
			if(Particles[p].Y > 0.50f)
			{
				Particles[p].B -= 0.1f;
				if(Particles[p].B <= 0.0) 
					Particles[p].B = 0.0f;
				
				if(Particles[p].X > 0.0f)
					Particles[p].X -= 0.70f;
				else
					Particles[p].X += 0.70f;
				if(Particles[p].Z > 0.0f)
					Particles[p].Z -= 0.70f;
				else
					Particles[p].Z += 0.70f;
			}
			if(Particles[p].Y > 1.0f){
				Particles[p].G -= 0.1f;
				if(Particles[p].G <= 0.0) 
					Particles[p].G = 0.0f;
				
				if(Particles[p].X > 0.0f)
					Particles[p].X -= 0.5f;
				else
					Particles[p].X += 0.5f;
				
				if(Particles[p].Z > 0.0f)
					Particles[p].Z -= 0.5f;
				else
					Particles[p].Z += 0.5;
			}
			if(Particles[p].Y > 2.0f){
				
				Particles[p].R -= 0.1f;
				if(Particles[p].R <= 0.0) 
					Particles[p].R = 0.0f;
				
			}
			if(Particles[p].Y > 5.0f){
				Particles[p].InitParticle();
			}
	}
	
}

void ParticleEngine::Neg()
{

	for(int p = 0; p < MAX_PARTICLES; ++p){
			glColor4f(Particles[p].R, Particles[p].G, Particles[p].B, 1.0);	
			
			glBegin(GL_POINTS);
				
				for (int i = 0; i < 25; ++i)
				{
					Particles[p].X += rand()%25/100.0f - 0.12f;
					Particles[p].Y += rand()%5/-100.0f;
					Particles[p].Z += rand()%25/100.0f - 0.12f; 
					glVertex3f(Particles[p].X, Particles[p].Y, Particles[p].Z);
					
				}
				
			glEnd();
			if(Particles[p].Y < -0.75f)
			{
				if(Particles[p].X > 0.0f)
					Particles[p].X -= 1.0f;
				else
					Particles[p].X += 1.0f;
				
				if(Particles[p].Z > 0.0f)
					Particles[p].Z -= 1.0f;
				else
					Particles[p].Z += 1.0f;
			}
			if(Particles[p].Y < -0.50f)
			{
				Particles[p].B -= 0.1f;
				if(Particles[p].B <= 0.0) 
					Particles[p].B = 0.0f;
				
				if(Particles[p].X > 0.0f)
					Particles[p].X -= 0.70f;
				else
					Particles[p].X += 0.70f;
				if(Particles[p].Z > 0.0f)
					Particles[p].Z -= 0.70f;
				else
					Particles[p].Z += 0.70f;
			}
			if(Particles[p].Y < -1.0f){
				Particles[p].G -= 0.1f;
				if(Particles[p].G <= 0.0) 
					Particles[p].G = 0.0f;
				
				if(Particles[p].X > 0.0f)
					Particles[p].X -= 0.5f;
				else
					Particles[p].X += 0.5f;
				
				if(Particles[p].Z > 0.0f)
					Particles[p].Z -= 0.5f;
				else
					Particles[p].Z += 0.5;
			}
			if(Particles[p].Y < -2.0f){
				
				Particles[p].R -= 0.1f;
				if(Particles[p].R <= 0.0) 
					Particles[p].R = 0.0f;
				
			}
			if(Particles[p].Y < -5.0f){
				Particles[p].InitParticle();
			}
	}
	
}
void ParticleEngine::Neu()
{

	for(int p = 0; p < MAX_PARTICLES; ++p){
			glColor4f(Particles[p].R, Particles[p].G, Particles[p].B, 1.0);	
			
			glBegin(GL_POINTS);
				
				for (int i = 0; i < 25; ++i)
				{
					Particles[p].X += rand()%444/1000.0f - 0.222f;
					Particles[p].Y += rand()%444/1000.0f - 0.222f;
					Particles[p].Z += rand()%444/1000.0f - 0.222f; 
					glVertex3f(Particles[p].X, Particles[p].Y, Particles[p].Z);
					
				}
				
			glEnd();
			
	}
	
}