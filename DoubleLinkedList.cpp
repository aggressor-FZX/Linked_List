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
		inputStrm << current->data << "\n";//write out the current data
		current = current->prev;//move to the next and try to repeat until nullptr
	}

	return inputStrm;//return input stream for chaining
}

// destructor
DoubleLinkedList::~DoubleLinkedList()
{
	cout << "in linkedlist destructor" << endl;

	// Changing to "current" for clarity
	JCNode* current = this->head; // creat pointer to head
	JCNode* holdNext = nullptr; // pointer to hold memory address 

	// While there are nodes to delete, nullptr being the last
	while (current != nullptr) 
	{
		holdNext = current->next ;// use hold,thru current to SAVE the next node
		delete current;// Delete the present node
		current = holdNext ; // next next node becomes current, repeat
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
	JCNode* nowPtr = new JCNode();
	nowPtr	= this->it;
	this->it = this->head->next;

	return nowPtr->data;
 }
bool DoubleLinkedList::hasMore() const
{
	return false;
}
bool DoubleLinkedList::push_back(const JCString& str)
{
	//create new node

	if (this->count == 0)
	{
		this->initHeadNode(str);
		++this->count;

		return true;

	}
	else 
	{
		JCNode* newNode =  new JCNode(str); 
		this->head->next = newNode;//old head's 'next' points to new head node
		newNode->prev = this->head; // New head node's previous points to old head node;
		this->head = newNode;//place on top of stack
		 
		++this->count;
	}
	return true;
}
bool DoubleLinkedList::remove(const JCString& str)
{
	return false;
}
bool DoubleLinkedList::insert(const JCString& str)
{
	//create new node
	JCNode* newNode =  new JCNode(str); 
	//compare 

	
}
void DoubleLinkedList::initHeadNode(const JCString& str)
{
	JCNode* newNode =  new JCNode(str); 
	this->head = newNode;
	this->tail = newNode;
	newNode->next = nullptr;
	newNode->prev = nullptr;

}
