// CIS1275 - Feridoon Ghanbari
// Ryan Sloan, rsloan2@cnm.edu
// SloanE8/Driver.cpp

#include "Triangles.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Header();
	cout << "A triangle is valid if the sum of any two edges" << endl;
	cout << "is greater than the third edge." << endl;
	cout << endl;
	int count = 0;
	string another;
	do
	{
		double edge1, edge2, edge3;
		cout << "Enter 3 sides that represent a triangle (such as 1  2.2  3)" << endl;
		cout << "==> ";
		cin >> edge1 >> edge2 >> edge3;
		cin.ignore();
		cout << endl;
		bool valid = ValidateEdges(edge1, edge2, edge3);
		if (valid == true)
		{
			cout << "Result: A triangle with edges " << edge1 << ", " << edge2 << ", " << edge3 << " is a valid triangle." << endl;
		}
		if (valid == false)
		{
			cout << "Result: A triangle with edges " << edge1 << ", " << edge2 << ", " << edge3 << " is NOT a valid triangle." << endl;
		}
		cout << "Do another? yes/no";
		getline(cin, another);
		cout << endl;
		count++;
	} while (another == "yes");
	cout << "You tested " << count << " triangles." << endl;
	cout << "Goodbye!" << endl;
	cout << endl;
	
	return 0;
}