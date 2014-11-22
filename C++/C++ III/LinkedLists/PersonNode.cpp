#include "ListMgr.h"
#include <iostream>
#include "SloanPersonGen\PersonGen.h"
#include "PersonNode.h"
using namespace std;

PersonNode::PersonNode() { next = prev = NULL; }

PersonNode::~PersonNode()
{
   cout << "\nIn PersonNode destructor.  " << person->getName();
   delete person;  
}

void PersonNode::setPrev(PersonNode *p) { prev = p; }
void PersonNode::setNext(PersonNode *n) { next = n; }
void PersonNode::setPerson(Person* p) { person = p; }

PersonNode* PersonNode::getPrev() { return prev; }
PersonNode* PersonNode::getNext() { return next; }
Person* PersonNode::getPerson() { return person; }
