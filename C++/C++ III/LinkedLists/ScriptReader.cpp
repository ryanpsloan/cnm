#include "ScriptReader.h"
#include <string>
using namespace std;


//only constructor, is passed the name of the file
ScriptReader::ScriptReader(string file)
{
	in.open(file);
}

	//returns the next integer value it finds 
int ScriptReader::getNextInt()
{
	string temp;
	char var = in.peek();
	while (var == '#' || var == ' ' || var == '\n') {
		getline(in, temp);
		var = in.peek();
		}
	getline(in, temp);
	int conversion = atoi(temp.c_str());
	return conversion;
	

}
	
	//returns the next valid string 
string ScriptReader::getNextString()
{
	string temp;
	getline(in,temp);
	return temp;
}