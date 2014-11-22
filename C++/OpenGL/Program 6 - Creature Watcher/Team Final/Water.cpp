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
#include "WaterMolecule.h"
#include "Water.h"

void Water::Melt(){
	
	for(int p = 0; p < MAX_WATERMOLECULES; ++p){
			glColor4f(FlowingWater[p].R, FlowingWater[p].G, FlowingWater[p].B, 1.0);	
			
			glBegin(GL_POINTS);
				
				for (int i = 0; i < 25; ++i)
				{
					FlowingWater[p].X += rand()%25/100.0f - 0.12f;
					FlowingWater[p].Y += rand()%5/100.0f;
					FlowingWater[p].Z += rand()%25/100.0f - 0.12f; 
					glVertex3f(FlowingWater[p].X, FlowingWater[p].Y, FlowingWater[p].Z);
					
				}
				
			glEnd();
			if(FlowingWater[p].Y < 0.75f)
			{
				if(FlowingWater[p].X > 0.0f)
					FlowingWater[p].X -= 1.0f;
				else
					FlowingWater[p].X += 1.0f;
				
				if(FlowingWater[p].Z > 0.0f)
					FlowingWater[p].Z -= 1.0f;
				else
					FlowingWater[p].Z += 1.0f;
			}
			if(FlowingWater[p].Y > 0.50f)
			{
				FlowingWater[p].B -= 0.1f;
				if(FlowingWater[p].B <= 0.0) 
					FlowingWater[p].B = 0.0f;
				
				if(FlowingWater[p].X > 0.0f)
					FlowingWater[p].X -= 0.70f;
				else
					FlowingWater[p].X += 0.70f;
				if(FlowingWater[p].Z > 0.0f)
					FlowingWater[p].Z -= 0.70f;
				else
					FlowingWater[p].Z += 0.70f;
			}
			if(FlowingWater[p].Y > 1.0f){
				FlowingWater[p].G -= 0.1f;
				if(FlowingWater[p].G <= 0.0) 
					FlowingWater[p].G = 0.0f;
				
				if(FlowingWater[p].X > 0.0f)
					FlowingWater[p].X -= 0.5f;
				else
					FlowingWater[p].X += 0.5f;
				
				if(FlowingWater[p].Z > 0.0f)
					FlowingWater[p].Z -= 0.5f;
				else
					FlowingWater[p].Z += 0.5;
			}
			if(FlowingWater[p].Y > 2.0f){
				
				FlowingWater[p].R -= 0.1f;
				if(FlowingWater[p].R <= 0.0) 
					FlowingWater[p].R = 0.0f;
				
			}
			if(FlowingWater[p].Y > 5.0f){
				FlowingWater[p].InitWaterMolecule();
			}
	}
}