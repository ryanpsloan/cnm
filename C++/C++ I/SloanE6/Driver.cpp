//CIS1275 - Feridoon Ghanbari
// Exercise 6
// Ryan Sloan, rsloan2@hotmail.com
// SloanE6/Driver.cpp

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	vector<int> integers;
	vector<int>::iterator iter;
	vector<int>::iterator iter2;

	cout << "Ryan Sloan" << endl;
	cout << "Exercise 6 - Practice with Vectors" << endl;
	cout << "Objective: Practicing and learning vectors." << endl;
	cout << endl;
	
	string answer;
	do
	{
		cout << "Please enter one value at a time. -99 will stop the input loop." << endl;
		int numiter = 0;
		int total = 0;
		int i = 1;
		double average;
		while (numiter != -99)
		{
			cout << "==> " << i << ".  " ;
			cin >> numiter;
			cin.ignore();
			total += numiter;
			if (numiter != -99)
			{
				integers.push_back(numiter);
			}
			++i;
		}
		if (integers.size() > 0)
		{
			iter = max_element(integers.begin(), integers.end());
			iter2 = min_element(integers.begin(), integers.end());
		}
		
		average = static_cast<double>(total)/integers.size();
				
		if (integers.size() == 0)
		{
			cout << "Results:" << endl;
			cout << "You didn't enter any values." << endl;
			 
		}
		else
		{
			cout << fixed << showpoint;
			cout.precision(5);
			cout << "Results:" << endl;
			cout << "You entered " << integers.size() << " values, the low is ";
			cout << *iter2 << ", the high is " << *iter << ", the average is " << average << "." << endl;
		}
		integers.clear();
		cout << "Do Another? Enter yes/no ";
		getline(cin, answer);
		cout << endl;
	} while (answer == "yes");
		
	cout << "END";
	
	return 0;
}
