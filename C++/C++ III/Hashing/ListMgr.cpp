#include "PersonNode.h"
#include "PersonGen.h"
#include "ListMgr.h"
#include <string>
#include <sstream>
using namespace std;

	ListMgr::ListMgr()
	{
		first = last = NULL;
		count = 0;

	}

	//Person* input, added to the front of the list
   void ListMgr::push_front(Person* p)
   {
		//Create a person node
	   PersonNode* newNode = new PersonNode();
	   //set the person node
	   newNode->setPerson(p);
	   if(count == 0)
	   {
		   newNode->setNext(NULL);
		   newNode->setPrev(NULL);
		   first = last = newNode;
	   }
	   else if(count == 1)
	   {
		   newNode->setNext(first);
		   newNode->setPrev(NULL);
		   first->setPrev(newNode);
		   last = first;
		   first = newNode;
		   
	   }
	   else if (count >= 2)
	   {
			newNode->setNext(first);
			newNode->setPrev(NULL);
			first->setPrev(newNode);
			first = newNode;
	   }
	   count++;
	   
   }

   //Person* input, added to the end of the list
   void ListMgr::push_back(Person *p)
   {
	   PersonNode* newNode = new PersonNode();
	   newNode->setPerson(p);
	   if(count == 0)
	   {
		   newNode->setNext(NULL);
		   newNode->setPrev(NULL);
		   first = last = newNode;
	   }
	   else if(count >= 1)
	   {
		   newNode->setNext(NULL);
		   newNode->setPrev(last);
		   last->setNext(newNode);
		   last = newNode;
	   }
	   count++;
	   
   }

   //Removes from the front of the list
   void ListMgr::pop_front()
   {
		   if (count > 0) 
		   {
				if(count == 1) 
				{
					delete first;
					count--;
				}
				else 
				{
					PersonNode * tempNode;
					tempNode = first->getNext();
					tempNode->setPrev(NULL);
					delete first;
					first = tempNode;
					count--;
				}
	   }
	   else
	   {
		cout << "\nThe List is Empty." << endl;
	   }
   }

   //Removes from the end of the list
   void ListMgr::pop_back()
   {
	   if (count > 0) 
	   {
			if (count > 1) 
			{
				PersonNode * tempNode;
				tempNode = last->getPrev();
				tempNode->setNext(NULL);
				delete last;
				last = tempNode;
				count--;
			}
			else
			{
				delete last;
				count--;
			}
	   }
	   else
	   {
		cout << "\nThe List is Empty." << endl;
	   }
   }

   //Returns a pointer to the first Person
   Person* ListMgr::front()
   {
	   if(first != NULL) {
			return first->getPerson();
	   }
	   else {
		   return NULL;
	   }
   }

   //Returns a pointer to the last Person
   Person* ListMgr::back()
   {
	   if(last != NULL){
			return last->getPerson();
	   }
	   else
	   {
			return NULL;
	   }
   }

   //Returns true if the list is empty, false if not
   bool ListMgr::empty()
   {
	   if (count == 0) 
	   {
			return true;
	   }
	   else
	   {
			return false;
	   }
   }

   //Removes any (and all) PersonNode from the list that contains "n" in name
   //n could be full or partial name
   void ListMgr::remove(string n)
   {
	   if(count > 0) {
		PersonNode * tempNode;
		PersonNode * nextNode;
		PersonNode * prevNode;
		string firstPlace = first->getPerson()->getName();
		string lastPlace = last->getPerson()->getName();
		size_t evalVar = firstPlace.find(n,0);
		size_t evalVar2 = lastPlace.find(n,0);

		if(n == firstPlace || evalVar != string::npos )
		{
			tempNode = first->getNext();
			delete first;
			tempNode->setPrev(NULL);
			first = tempNode;
			count--;
			
		}
		else if (n == lastPlace || evalVar2 != string::npos)
		{
			tempNode = last->getPrev();
			delete last;
			tempNode->setNext(NULL);
			last = tempNode;
			count--;
		}
		else
		{
			tempNode = first->getNext();
			int i = 0;
			while (i < count - 1)
			{
				string personName = tempNode->getPerson()->getName();
				size_t eval = personName.find(n,0);
				if (n == personName || eval != string::npos)
				{
					nextNode = tempNode->getNext();
					prevNode = tempNode->getPrev();
					delete tempNode;
					nextNode->setPrev(prevNode);
					prevNode->setNext(nextNode);
					count--;
					tempNode = nextNode;
				}
				else
				{

					tempNode = tempNode->getNext();

				}
				i++;
			}	
			
		  }
	   }	
   }

   //Removes the PersonNode at position pos.
   //Note: first string is #1
   void ListMgr::erase(int pos)
   {
	if(pos <= count) {

		if(pos == 1)
		{
			PersonNode * temp;
			temp = first->getNext();
			delete first;
			first = temp;
			count--;

		}
		else if (pos == count)
		{
			PersonNode * temp;
			temp = last->getPrev();
			delete last;
			last = temp;
			count--;
		}
		else
		{
			PersonNode * temp; 
			PersonNode * tempNext;
			PersonNode * tempPrev;
			if (pos == 2)
			{
				temp = first->getNext();
				first->setNext(temp->getNext());
				tempNext = temp->getNext();
				tempNext->setPrev(first);
				delete temp;
				count--;

			}
			else if (pos >= 3) 
			{
				temp = first->getNext();
				for (int i = 3; i <= pos; ++i) 
				{
					temp = temp->getNext();
				}
				tempNext = temp->getNext();
				tempPrev = temp->getPrev();
				tempNext->setPrev(tempPrev);
				tempPrev->setNext(tempNext);
				delete temp;
						
				count--;
			}
		}
	}
	else
	{
		cout << "\nThat Position Doesn't exist" << endl;
	}
}
   //Clears all PersonNodes from the list
   void ListMgr::clear()
   {
	   PersonNode * placeMarker;
	   while (count > 0)
	   {
			placeMarker = last->getPrev();
			delete last;
			last = placeMarker;
			count--;
	   }

	  
   }

   //Shows the list, names only. First line states number in list
   //Second, 3rd, + lines shows names of people in the list. 
   //Place several names on one line. 
   //Separate names using obvious symbol, such as --> or :: 
   void ListMgr::show(){
	
	    cout << "\nList Size: " << count << endl;
		if (count == 0)
		{
			cout << "\nThe list is empty." << endl;

		}
		else 
		{
			PersonNode * temp;
			temp = first;
			for (int i = 0; i < count; i++) 
			{
				if (i % 4 == 0)
				{
					cout << endl;
				}
				cout << temp->getPerson()->getName() << " | ";
				PersonNode* next = temp->getNext();
				temp = next;
				
			}
			cout << endl;
		}
   }

   //This show function returns a string that has the same features
   //of the show(), except it has been stringstreamed into a string
   string ListMgr::showString()
   {
	   stringstream ss;
	   ss << "\nList Size: " << count << endl;
		if (count == 0)
		{
			ss << "\nThe list is empty." << endl;

		}
		else 
		{
			PersonNode * temp = new PersonNode();
			temp = first;
			for (int i = 0; i < count; i++) 
			{
				if (i % 3 == 0)
				{
					ss << endl;
				}
				ss << temp->getPerson()->getName() << " | ";
				PersonNode* next = temp->getNext();
				temp = next;
			}
		}
		   
	   return ss.str();
   }

   //Destructor, clears the list
   ListMgr::~ListMgr()
   {
		clear();
   }
