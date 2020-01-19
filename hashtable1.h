#ifndef HASHTABLE1_H
#define HASHTABLE1_H
#include "node.h"
#include <string>

using namespace std;
// chaining method

struct linked_list 
{
	node<string> * head;
	node<string> * tail;
};
class Hash
{
public:
	Hash();
	~Hash();
	void insert(string dataValue); // insert into hash
	bool spellCheck(string); // spellCheck functionality
	void print(); 


private:
	int charToInt(char); 
	linked_list * data; // store data 
	unsigned size; //size of hashtable
	unsigned capacity = 26; //capacity of hash table 


};


Hash::Hash()
{
	size = 0; 
	// the hash table is currently unpopulated
	// the capacity of the hash table is 26 lists
	data = new linked_list[capacity];
	for (unsigned i = 0; i < capacity; i++)
	{
		data[i].head = NULL;
		data[i].tail = NULL;
	// each list the head and tail pointers each 
	// initially point to nothing
	}
}


Hash:: ~Hash()
{
	delete[] data;
}


void Hash::insert(string dataValue)
{
	/*
		There are two given scenarios in which 
		a given dataValue is inserted into a 
		chained hash table. 
		1. The list at the dataValue's corresponding
			index is empty. In which case, the list's
			head and tail pointers will both point to
			the dataValue's node 
		2. The list at the dataValue's index is populated.
			In which case, the dataValue's node.
	*/

	int index;
	index = charToInt(dataValue[0]);
	// find the index of the list in the
	// data array
	node<string>* newNode = new node<string>;
	newNode->setEntry(dataValue);
	if (data[index].head == NULL && data[index].tail == NULL) 
  {
		data[index].head = newNode;
		data[index].tail = newNode;
		newNode->setNext(data[index].tail);
	}
	else 
  {
		data[index].tail->setNext(newNode);
		data[index].tail = newNode;
	}
	size += 1;
	//increase the size of the hash table by 1
}

int Hash::charToInt(char given) 
{
	int value;
	value = (int)given - 97;
	return value;
}


bool Hash::spellCheck(string dataValue) 
{
	int index;
	int collisions; 
	index = charToInt(dataValue[0]);
	node<string>* current = new node<string>; 
	current = data[index].head;
	while (current -> getNext() != NULL) 
	{
		if(current->getEntry() == dataValue)
		{
			//cout<< collisions<< "comparisions made during search during chainging "<<endl;
			return true;
		}
		current = current -> getNext(); 
		collisions++; 
	}
	//cout<< collisions<< "comparisions made during search during chainging "<<endl;
	return false;
}

void Hash::print()
{
	node<string> * current; 
	cout << "[";
	for (unsigned i = 0; i < capacity; i++)
	{
		current = data[i].head;
		while (current!= data[i].tail )
		{
			cout<< current->getEntry() << ",";
			current = current -> getNext();  
		} 
	}
	cout<< "]";

}

#endif
