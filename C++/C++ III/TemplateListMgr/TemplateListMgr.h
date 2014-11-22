#include "DataClass.h"
#include "TemplateDataNode.h"
#include "PersonGen.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <fstream>
#include <istream>

#ifndef _TEMP_LISTMGR
#define _TEMP_LISTMGR

template <class T> 
class TemplateListMgr : protected Person
{
protected:
	int count;
	TemplateDataNode<T> *first, *last;

public:
	 TemplateListMgr<T>();
	 ~TemplateListMgr<T>();
	 void push_front(T* t);
	 void push_back(T* t);
	 void pop_front();
	 void pop_back();
	 int size(){return count;}
	 T front();
	 T back();
	 bool empty();
	 void remove(T d);
	 void removePerson(T d);
	 void erase(int pos);
	 void clear();
	 void show();
	 void showPerson();
	 string showString();
	 string showPersonStr();
     
};


template<class T> 
TemplateListMgr<T>::TemplateListMgr()
	{
		first = last = NULL;
		count = 0;

	}

	//Person* input, added to the front of the list
template <class T> 
void TemplateListMgr<T>::push_front(T* d)
   {
		//Create a data node
	   TemplateDataNode<T> *newNode = new TemplateDataNode<T>();
	   //set the data node
	   newNode->setData(d);
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

   
template <class T>   
void TemplateListMgr<T>::push_back(T* d)
   {
	   TemplateDataNode<T> *newNode = new TemplateDataNode<T>();
	   newNode->setData(d);
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
template<class T>   
void TemplateListMgr<T>::pop_front()
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
					TemplateDataNode<T> *tempNode;
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
template<class T>   
void TemplateListMgr<T>::pop_back()
   {
	   if (count > 0) 
	   {
			if (count > 1) 
			{
				TemplateDataNode<T> * tempNode;
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
template<class T>   
T TemplateListMgr<T>::front()
   {
	   T x;
	   if(first != NULL) {
			return first->getData();
	   }
	   else {
		   return x;
	   }
   }

   //Returns a pointer to the last Person
template<class T>
T TemplateListMgr<T>::back()
   {
	   T x;
	   if(last != NULL){
			return last->getData();
	   }
	   else
	   {
			return x;
	   }
   }

   //Returns true if the list is empty, false if not
  template<class T>
  bool TemplateListMgr<T>::empty()
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
  template <class T>
  void TemplateListMgr<T>::remove(T d)
   {
	   if(count > 0) {
		TemplateDataNode<T> *tempNode;
		TemplateDataNode<T> *nextNode;
		TemplateDataNode<T> *prevNode;
		tempNode = first->getNext();
		int i = 0;
		while (i < count - 1)
		{
			if (tempNode->getData() == d)
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

template <class T>
void TemplateListMgr<T>::removePerson(T d)
{
	TemplateDataNode<T> *tempNode;
	TemplateDataNode<T> *nextNode;
	TemplateDataNode<T> *prevNode;
	
	string firstPlace = first->getData().getName();
	string lastPlace = last->getData().getName();
	size_t evalVar = firstPlace.find(d.getName(),0);
	size_t evalVar2 = lastPlace.find(d.getName(),0);

	if(d.getName() == firstPlace || evalVar != string::npos )
	{
		tempNode = first->getNext();
		delete first;
		tempNode->setPrev(NULL);
		first = tempNode;
		count--;
	}
	else if (d.getName() == lastPlace || evalVar2 != string::npos)
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
			string personName = tempNode->getData().getName();
			size_t eval = personName.find(d.getName(),0);
			if (d.getName() == personName || eval != string::npos)
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
			
   //Removes the PersonNode at position pos.
   //Note: first string is #1
  template<class T> 
  void TemplateListMgr<T>::erase(int pos)
   {
	if(pos <= count) {

		if(pos == 1)
		{
			TemplateDataNode<T> * temp;
			temp = first->getNext();
			delete first;
			first = temp;
			count--;

		}
		else if (pos == count)
		{
			TemplateDataNode<T> * temp;
			temp = last->getPrev();
			delete last;
			last = temp;
			count--;
		}
		else
		{
			TemplateDataNode<T> * temp; 
			TemplateDataNode<T> * tempNext;
			TemplateDataNode<T> * tempPrev;
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
template<class T>
void TemplateListMgr<T>::clear()
   {
	   TemplateDataNode<T> * placeMarker;
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
template <class T>   
void TemplateListMgr<T>::show(){
	
	    cout << "\nList Size: " << count << endl;
		if (count == 0)
		{
			cout << "\nThe list is empty." << endl;

		}
		else 
		{
			TemplateDataNode<T> *temp;
			temp = first;
			for (int i = 0; i < count; i++) 
			{
				cout << temp->getData() << " | " << endl;
				TemplateDataNode<T> *next = temp->getNext();
				temp = next;
				
			}
			cout << endl;
		}
   }

   //This show function returns a string that has the same features
   //of the show(), except it has been stringstreamed into a string
template<class T>   
string TemplateListMgr<T>::showString()
   {
	   stringstream ss;
	   ss << "\nList Size: " << count;
		if (count == 0)
		{
			ss << "\nThe list is empty." << endl;

		}
		else 
		{
			TemplateDataNode<T> * temp;
			temp = first;
			for (int i = 0; i < count; i++) 
			{
				if (i % 2 == 0)
				{
					ss << endl;
				}
				ss << temp->getData() << " | ";
				TemplateDataNode<T> *next = temp->getNext();
				temp = next;
			}
			ss << endl;
		}
		   
	   return ss.str();
   }

   //Destructor, clears the list
template<class T>   
TemplateListMgr<T>::~TemplateListMgr()
   {
		clear();
		
   }

template<class T>
string TemplateListMgr<T>::showPersonStr() 
{
		stringstream ss;
		ss << "\nList Size: " << count << endl;
		if (count == 0)
		{
			ss << "\nThe list is empty." << endl;

		}
		else 
		{
			TemplateDataNode<T> * temp;
			temp = first;
			for (int i = 0; i < count; i++) 
			{
				ss << temp->getData().getFullDesc() << endl;
				TemplateDataNode<T> *next = temp->getNext();
				temp = next;
			}
		ss << endl;
		}
		   
	   return ss.str();
}
	
 template <class T>
 void TemplateListMgr<T>::showPerson()
 {
 
		cout << "\nList Size: " << count << endl;
		if (count == 0)
		{
			cout << "\nThe list is empty." << endl;

		}
		else 
		{
			TemplateDataNode<T> *temp;
			temp = first;
			for (int i = 0; i < count; i++) 
			{
				cout << temp->getData().getFullDesc() << endl;
				TemplateDataNode<T> *next = temp->getNext();
				temp = next;
				
			}
			cout << endl;
		}
}
 
 
 
 
 
#endif