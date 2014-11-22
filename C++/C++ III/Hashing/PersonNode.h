/*Barbara Johnston
 *for CIS 2277 Fall 2013
 *File: PersonNode.h
 */

// This is the linked list node class used by the ListMgr class.

#ifndef _PERSON_NODE_H
#define _PERSON_NODE_H

#include <iostream>
#include "PersonGen.h"
using namespace std;

class PersonNode
{
   private:
      PersonNode *prev, *next;
      Person* person;

   public:
      PersonNode() { next = prev = NULL; }

      ~PersonNode()
      {
         //cout << "\nIn PersonNode destructor.  " << person->getName() << endl;
		 delete person;
      }

      void setPrev(PersonNode *p) { prev = p; }
      void setNext(PersonNode *n) { next = n; }
      void setPerson(Person* p) { person = p; }

      PersonNode *getPrev() { return prev; }
      PersonNode *getNext() { return next; }
      Person* getPerson() { return person; }
};

#endif
