#include "DataClass.h"
#include <string>
#ifndef _TEMPLATE_DATA_NODE_H
#define _TEMPLATE_DATA_NODE_H
using namespace std;

template<class T> 
class TemplateDataNode 
{
private:
	TemplateDataNode<T> *prev, *next;
	Data<T> obj;
public:
	TemplateDataNode<T>() { next = prev = NULL; }
	~TemplateDataNode<T>() {}
	
      void setPrev(TemplateDataNode<T> *p) { prev = p; }
      void setNext(TemplateDataNode<T> *n) { next = n; }
	  void setData(T* d) { obj.setDataClass(d); }

      TemplateDataNode<T> *getPrev() { return prev; }
      TemplateDataNode<T> *getNext() { return next; }
	  T getData() { return obj.getDataClass(); }

};

#endif