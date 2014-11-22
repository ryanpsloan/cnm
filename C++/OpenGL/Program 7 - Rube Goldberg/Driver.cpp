//Driver.cpp
//Ryan Sloan - CIS 2270
//rsloan2@cnm.edu
//this to avoid the black console window
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

#include <windows.h>		// Must have for Windows platform builds
#include <gl\freeglut.h>
#include "Functions.h"
#include "tAxis.h"
#include "Component.h"

//-------------------------- Ryan Sloans Classes
	//-- derived from flamethrower
#include "sloanFire.h"
	//-- Draw Flamethrower
#include "sloanFlameThrower.h"
	//-- Draw Ice Cube
#include "sloanIceCube.h"
	//-- Create the particles
#include "sloanParticle.h"
	//-- put particles together and create form
#include "sloanParticleEngine.h"

//-------------------------- Bresdin O'Malley's Classes
	//-- draw bumblebee (uses texture mapping)
#include "bomBumbleBee.h"
	//-- Draw coconut
#include "bomCoconut.h"
	//-- Draw flower
#include "bomFlower.h"
	//-- Draw Tree
#include "bomTree.h"
	//-- Draw Landscape and sky
#include "bomSkyCube.h"


using namespace std;

//Components
// -- Ryans Objs
FlameThrower fire;
IceCube ice;

// -- Bresdin's objs
BumbleBee bee;
Coconut coco;
Flower flow;
Tree palmtree;
SkyBox sandybeach;

Component * puzzle[8];

GLboolean planeOn = true, axesOn = true;
GLboolean startMachine = false, reset;

//Perspective Variables
GLfloat eyeX, eyeY, eyeZ;
GLint azimuth = 35, elevation = 10, radius = 300;
tAxis axis;



///////////////////////////////////////////////////////////
// Main program entry point
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(700, 1100);
    glutCreateWindow("Ryan Sloan - SloanP7");
	glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
	glutTimerFunc(100, TimerFunc, 1);
	setupMenu();

	SetupRC();
	glutKeyboardFunc(ChangeFunction);
	glutSpecialFunc(SpecialKeys);
	glutMainLoop();
    
    return 0;
}