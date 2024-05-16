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
	cout << "in linked list destructor" << endl;

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

	if (this->count == 0)
	{
		// fist node, create new head node
		this->initHeadNode(str);

		return true;

	}
	else if(this->count > 0)
	{
		JCNode* newNode;
		newNode = new JCNode(str);

		this->head->next = newNode; //old head's 'next' points to new head node
		newNode->prev = this->head; // New head node's previous points to old head node;A
		newNode->next = nullptr; // New head node's next points to nullptr
		this->head = newNode;//place on top of stack
		 
		++this->count;

		return true;

	} else {
		return false;
	}

	return false;
}

bool DoubleLinkedList::remove(const JCString& str)
{
	return false;
}

// Smaller letters come first hence A < B < C etc. list starts small goes large
bool DoubleLinkedList::insert(const JCString& str)
{
	bool success = false;

	// Case where list is empty
	if (this->count == 0)
	{
		// Place on top of list and return true
		this->initHeadNode(str);

		success = true;
		
	}// Case where this is only one item in list
	else if(this->count == 1)
	{
		
		this->it = this->head;
		
		if (this->it->data == str)//using JCString to string compare operator
		{
			// Already in list, return false
			success = false;
		}
		else if (this->it->data > str)// Arg String comes before 
		{
			//string arg becomes new head
			// call push back to handle it and increment this->count
			success = this->push_back(str);
		}
		else if (this->it->data < str) // Arg String comes after
		{
			// Create new node with string arg
			JCNode* newNode = new JCNode(str);

			// Place node behind the head
			this->it->prev = newNode; // point prev to  this node
			newNode->next = this->head; // newNode next points to the head
			newNode->prev = nullptr; // only two items in list

			// New node is bottom of list
			this->tail = newNode;

			// Increment list
			++this->count;

			// Reset iter
			this->resetIteration();
			success = true;
		}

	}
	
	return success;
}

void DoubleLinkedList::initHeadNode(const JCString& str)
{
	JCNode* newNode =  new JCNode(str); 
	this->head = newNode;
	this->tail = newNode;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	++this->count;

}

//	Free standing helper function
JCNode* seeker(const char* str, const DoubleLinkedList* dll)
{	
	char* checkString = nullptr; //looking for this string

	dll->it = dll->head; // start at the head node

	while (dll->it != nullptr) //go until we prev ptr is null
	{	
		if(dll->it->data == str) //if we find it 
		{
			return dll->it; //return it ptr
		}
		else 
		{//move backwards
			dll->it = dll->it->prev;
		}
	}

	return nullptr; //didn't find it return null
}
