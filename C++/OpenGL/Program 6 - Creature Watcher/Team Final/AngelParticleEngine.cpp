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
#include <random>

#include "Particle.h"
#include "Functions.h"
#include "ParticleEngine.h"
#include "AngelParticleEngine.h"

using namespace std;

default_random_engine generator;
uniform_real_distribution<GLfloat> distribution;
uniform_real_distribution<GLfloat> dist2;
GLboolean behavior;
GLfloat Xcoor =0.1f, Ycoor =0.1f, Zcoor = 0.1f, Bcolor = 0.10f, Gcolor = 0.10f;

AngelParticleEngine::AngelParticleEngine(){

	
}

void AngelParticleEngine::SunFire()
{
	
	for(int p = 0; p < MAX_PARTICLES; ++p){
		for(int i = 0; i < 100; ++i)
		{
				glBegin(GL_POINTS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glColor4f(Particles[p].R, Particles[p].G, Particles[p].B, 1.0);	
					glVertex3f(Particles[p].X, Particles[p].Y, Particles[p].Z);	
				glEnd();
				//Down Back and to the Left
				Particles[p].X -= Xcoor;
				Particles[p].Y -= Ycoor;
				Particles[p].Z -= Zcoor;
				Particles[p].B -= Bcolor;
				if(Particles[p].B <= 0.0f){
					Particles[p].G -= Gcolor;
					if(Particles[p].G <= 0.0f)
						Particles[p].InitParticle();
				}
				
				glBegin(GL_POINTS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glColor4f(MirrorParticles[p].R, MirrorParticles[p].G, MirrorParticles[p].B, 1.0);	
					glVertex3f(MirrorParticles[p].X, MirrorParticles[p].Y, MirrorParticles[p].Z);	
				glEnd();
				//Up Forward and to the Right
				MirrorParticles[p].X += Xcoor;
				MirrorParticles[p].Y += Ycoor;
				MirrorParticles[p].Z += Zcoor;
				MirrorParticles[p].B -= Bcolor;
				if(MirrorParticles[p].B <= 0.0f){
					MirrorParticles[p].G -= Gcolor;
					if(MirrorParticles[p].G <= 0.0f){
						MirrorParticles[p].InitParticle();
					}
				}
				
				glBegin(GL_POINTS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glColor4f(ParticlesA[p].R, ParticlesA[p].G, ParticlesA[p].B, 1.0);	
					glVertex3f(ParticlesA[p].X, ParticlesA[p].Y, ParticlesA[p].Z);	
				glEnd();
				//Right. Back. Up.
				ParticlesA[p].X += Xcoor;
				ParticlesA[p].Y += Ycoor;
				ParticlesA[p].Z -= Zcoor;
				ParticlesA[p].B -= Bcolor;
				if(ParticlesA[p].B <= 0.0f){
					ParticlesA[p].G -= Gcolor;
					if(ParticlesA[p].G <= 0.0)
						ParticlesA[p].InitParticle();
				}
				
				glBegin(GL_POINTS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glColor4f(MirrorParticlesA[p].R, MirrorParticlesA[p].G, MirrorParticlesA[p].B, 1.0);	
					glVertex3f(MirrorParticlesA[p].X, MirrorParticlesA[p].Y, MirrorParticlesA[p].Z);	
				glEnd();
				//Left Down Forward
				MirrorParticlesA[p].X -= Xcoor;
				MirrorParticlesA[p].Y -= Ycoor;
				MirrorParticlesA[p].Z += Zcoor;
				MirrorParticlesA[p].B -= Bcolor;
				if(MirrorParticlesA[p].B <= 0.0f){
					MirrorParticlesA[p].G -= Gcolor;
					if(MirrorParticlesA[p].G <= 0.0){
						MirrorParticlesA[p].InitParticle();
					}
				}
				
				glBegin(GL_POINTS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glColor4f(ParticlesB[p].R, ParticlesB[p].G, ParticlesB[p].B, 1.0);	
					glVertex3f(ParticlesB[p].X, ParticlesB[p].Y, ParticlesB[p].Z);	
				glEnd();
				//Right Down Forward
				ParticlesB[p].X += Xcoor;
				ParticlesB[p].Y -= Ycoor;
				ParticlesB[p].Z += Zcoor;
				ParticlesB[p].B -= Bcolor;
				if(ParticlesB[p].B <= 0.0f){
					ParticlesB[p].G -= Gcolor;
					if(ParticlesB[p].G <= 0.0f)
						ParticlesB[p].InitParticle();
				}
				
				
				glBegin(GL_POINTS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glColor4f(MirrorParticlesB[p].R, MirrorParticlesB[p].G, MirrorParticlesB[p].B, 1.0);	
					glVertex3f(MirrorParticlesB[p].X, MirrorParticlesB[p].Y, MirrorParticlesB[p].Z);	
				glEnd();
				//Left up Back
				MirrorParticlesB[p].X -= Xcoor;
				MirrorParticlesB[p].Y += Ycoor;
				MirrorParticlesB[p].Z -= Zcoor;
				MirrorParticlesB[p].B -= Bcolor;
				if(MirrorParticlesB[p].B <= 0.0f){
					MirrorParticlesB[p].G -= Gcolor;
					if(MirrorParticlesB[p].G <= 0.0f){
						MirrorParticlesB[p].InitParticle();
					}
				}
			
				glBegin(GL_POINTS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glColor4f(ParticlesC[p].R, ParticlesC[p].G, ParticlesC[p].B, 1.0);	
					glVertex3f(ParticlesC[p].X, ParticlesC[p].Y, ParticlesC[p].Z);	
				glEnd();
				//Left Up Forward
				ParticlesC[p].X -= Xcoor;
				ParticlesC[p].Y += Ycoor;
				ParticlesC[p].Z += Zcoor;
				ParticlesC[p].B -= Bcolor;
				if(ParticlesC[p].B <= 0.0f){
					ParticlesC[p].G -= Gcolor;
					if(ParticlesC[p].G <= 0.0f)
						ParticlesC[p].InitParticle();
				}
			
				glBegin(GL_POINTS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glColor4f(MirrorParticlesC[p].R, MirrorParticlesC[p].G, MirrorParticlesC[p].B, 1.0);	
					glVertex3f(MirrorParticlesC[p].X, MirrorParticlesC[p].Y, MirrorParticlesC[p].Z);	
				glEnd();
				//Right Down Back
				MirrorParticlesC[p].X += Xcoor;
				MirrorParticlesC[p].Y -= Ycoor;
				MirrorParticlesC[p].Z -= Zcoor;
				MirrorParticlesC[p].B -= Bcolor;
				if(MirrorParticlesC[p].B <= 0.0f){
					MirrorParticlesC[p].G -= Gcolor;
					if(MirrorParticlesC[p].G <= 0.0f){
						MirrorParticlesC[p].InitParticle();
					}
				}
		}
	}
}

