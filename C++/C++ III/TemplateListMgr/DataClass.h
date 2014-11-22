#include "Person.h"
#include <string>
using namespace std;

#ifndef _DATA_CLASS
#define _DATA_CLASS

template<class T> 
class Data : protected Person
{
private:
		T data;
public:
		T getDataClass();
		void setDataClass(T *b);
	
};

template<class T>
T Data<T>::getDataClass()
{ return data; }

template<class T>
void Data<T>::setDataClass(T *b)
{ data = *b; }

#endif
