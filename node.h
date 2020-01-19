#ifndef NODE_H
#define NODE_H
#include <string>
template <typename T>
class node
{
public: 
	node (const T & = T()); 
	void setEntry(const T &); 
	T &getEntry(); 
	void setNext (node <T> *); 
	void setPrev (node <T> *); 
	node <T>* getNext () const; 
	node <T>* getPrev () const; 
private: 
	T entry; 
	node <T> * next; 
	node <T> * prev; 

};


//constructor
template <typename T> 
node<T> :: node (const T &entry)
{
	this-> entry = entry; 
	this-> next = 0; 
	this-> prev = 0; 
}

template <typename T> 
void node<T>:: setEntry (const T &entry)
{
	this -> entry = entry; 
}

template <typename T> 
T &node<T>:: getEntry()
{
	return entry; 
}

template <typename T>
void node<T>::setNext( node<T> *next)
{
  this->next= next;
} 

template <typename T>
void node<T>::setPrev( node<T> *prev)
{
  this->prev = prev;
} 

template <typename T>

node<T> *node<T>::getNext() const
{
  return next;
} 

template <typename T>
node<T> *node<T>::getPrev() const
{
  return prev;
} 
#endif