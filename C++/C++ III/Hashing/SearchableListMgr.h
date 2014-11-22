

#include "ListMgr.h"
#include "PersonNode.h"
#include "Person.h"

using namespace std;

#ifndef _SRC_LIST_MGR_H
#define _SRC_LIST_MGR_H

class SearchableListMgr : public ListMgr
{
public:
	SearchableListMgr();
	bool isPresent(string name, int mm, int dd, int yy, Person* &pPer);


};

#endif