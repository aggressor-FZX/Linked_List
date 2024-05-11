#include "DoubleLinkedList.h"
#include <iostream>
using std::cout;
using std::endl;

DoubleLinkedList::DoubleLinkedList()
{
	cout << "in constructor" << endl;
	this->head = nullptr;
	this->tail = nullptr;
	this->it = nullptr;
	this->count = 0;
}

// copy constructor
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& dll)
{
	this->head = dll.head;
	this->tail = dll.tail;
	this->count = dll.count;
	this->it = dll.it;
}

// Assignment assignment
DoubleLinkedList DoubleLinkedList::operator=(const DoubleLinkedList& dll)
{
	this->head = dll.head;
	this->tail = dll.tail;
	this->count = dll.count;
	this->it = dll.it;
	return *this;
}

// Write out using operator
ostream& operator<<(ostream& inputStrm, const DoubleLinkedList& dll)
{
	cout << " in the << operator " << endl;
	// Changing to "current" for clarity
	JCNode* current = dll.head;
	// While there is a node to write out, as in not nullptr
	while (current)
	{
		inputStrm << current->data;//write out the current data
		current = current->next;//move to the next and try to repeat until nullptr
	}

	return inputStrm;//return input stream for chaining
}

// destructor
DoubleLinkedList::~DoubleLinkedList()
{
	cout << "in linkedlist destructor" << endl;

	// Changing to "current" for clarity
	JCNode* current = head;
	// While there are nodes to delete
	while (head) 
	{
		JCNode* next = current->next;// save the next node
		delete current;// delete the present node
		current = next; // next next node becomes current, repeat
	}
	// Set to nullptr when done	
	head = nullptr;
	tail = nullptr;
}

void DoubleLinkedList::resetIteration() const
{
	this->it = this->head;
}

int DoubleLinkedList::getCount() const
{
	return this->count;
}

JCString DoubleLinkedList::next() const
{
	JCNode* nowPtr = this->it;
	this->it = this->head->next;

	return nowPtr->data;
 }
bool DoubleLinkedList::hasMore() const
{
	return false;
}
bool DoubleLinkedList::insert(const JCString& str)
{
	JCNode* newNode(str);
	this->head = newNode;
	return false;
}
bool DoubleLinkedList::remove(const JCString& str)
{
	return false;
}
