#include "SearchableListMgr.h"
#include "ListMgr.h"
using namespace std;


SearchableListMgr::SearchableListMgr()
{}

bool SearchableListMgr::isPresent(string name, int mm, int dd, int yy, Person* &pPerC)
{
	PersonNode *firstNode = first;
	PersonNode *nextNode = firstNode->getNext();
	Person *p = firstNode->getPerson();
	Person *tempPtr = p;
	 
	if(name == p->getName() 
	&& mm == p->getDate().GetMonth() 
	&& dd == p->getDate().GetDay() 
	&& yy == p->getDate().GetYear())
	{
		pPerC = tempPtr;
		return true;
	}
						
	for (int j = 1; j < count; ++j)
	{
		Person *p2 = nextNode->getPerson();
		tempPtr = p2;
	
		if(name == p2->getName() 
		&& mm == p2->getDate().GetMonth() 
		&& dd == p2->getDate().GetDay() 
		&& yy == p2->getDate().GetYear())
		{
			pPerC = tempPtr;
			return true;
		}
		
		nextNode = nextNode->getNext();
	}
					
				
	pPerC = NULL;			
	return false;
					
}