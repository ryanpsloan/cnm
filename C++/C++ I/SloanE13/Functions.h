//Arrays_SearchIt
//This program will read in an array of up to
//300 ints and then sort it.  It will also ask
//the user for two ints, and search for them 
//in the sorted array.  It will return true or
//false for each int searched for.

//Functions.h

//prototypes
void Header();
bool ReadFile(int nums[], int &rtotal);
void Sort(int nums[], int total);
void Get2Integers(int &rn1, int &rn2);
void SearchIt(int nums[], int total, int n1, int n2, bool &rsearch1, bool &rsearch2);