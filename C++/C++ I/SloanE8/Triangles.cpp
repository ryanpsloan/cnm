// CIS1275 - Feridoon Ghanbari
// Ryan Sloan, rsloan2@cnm.edu
// SloanE8/Triangles.cpp

#include <iostream>
using namespace std;

void Header()
{
	cout << "Ryan Sloan" << endl;
	cout << "Validating Triangles" << endl;
	cout << "Objective: Using Functions" << endl;
	cout << endl;
}

bool ValidateEdges(double edge1, double edge2, double edge3)
{
	if ( edge1 + edge2 > edge3 || edge2 + edge3 > edge1 || edge3 + edge1 > edge2 )
		return true;
	else
		return false;
}