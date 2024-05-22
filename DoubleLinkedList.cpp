////
// Name: Jeff Calderon
// Class Name: CS131
// Section:  33616
// Program 3 DoubleLinkedList
// Description: Double Linked List implementation 
// implements the linked list. Uses JCNode as 
// nodes. Each holds a JCString data type. List
// alphabetizes as it inserts values list 
// ignores strings that are already in the list.
// Insert has insertFirst and alphaPlacer as helper
// functions. insertBefore member function places 
// string prev to argument string in the list
////
#include "DoubleLinkedList.h"
#include <iostream>
using std::cout;
using std::endl;
//Helper Functions
JCNode* seeker(const char* str, const DoubleLinkedList* dll);

DoubleLinkedList::DoubleLinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->it = nullptr;
	this->count = 0;
}

// copy constructor
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& dll)
{
	dll.resetIteration();

	initHeadNode(dll.next());

	while (dll.hasMore())
	{
		//next moves to prev to prev
		//JCString copy constructor handles memory allocation 
		this->pop_back(dll.next());
	}
}

// Assignment assignment
DoubleLinkedList DoubleLinkedList::operator=(const DoubleLinkedList& dll)
{
	dll.resetIteration();

	initHeadNode(dll.next());

	while (dll.hasMore())
	{
		//next moves to prev to prev
		//JCString copy constructor handles memory allocation 
		this->pop_back(dll.next());
	}
	return *this;
}

// Write out using operator
ostream& operator<<(ostream& outputStrm, const DoubleLinkedList& dll)
{
	dll.resetIteration();
	// While there is a node to write out, as in not nullptr
	while (dll.hasMore())
	{
		JCString str = JCString(dll.next());//write out the current data 
		outputStrm << str << " ";

	}

	return outputStrm;//return input stream for chaining
}

// destructor
DoubleLinkedList::~DoubleLinkedList()
{
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

		this->head->next = newNode;// fix old head next to new node
		newNode->prev = this->head; // New head node's prev points to old head node
		newNode->next = nullptr; // Head node next is always nullptr
		this->head = newNode;// list head ptr to newNode 
		 
		++this->count;

		return true;

	} else {
		return false;
	}

	return false;
}


// Smaller letters come first hence A < B < C etc. list starts small goes large
// If the word is in list already it ignores, regardless of capitalization
bool DoubleLinkedList::insert(const JCString& str)
{
	this->resetIteration();//Start from head
	bool success = false;

	// CASE WHERE LIST IS EMPTY
	if (this->count == 0)
	{
		this->initHeadNode(str);// Place on top
		success = true;

	}
	// CASE WHERE THIS IS ONLY ONE ITEM IN LIST
	else if (this->count == 1)
	{
		//checks if is in already and places
		success = insertFirsts(*this, str);
	}
	// CASE WHERE THERE ARE ALREADY MANY ENTRIES
	else if (this->count > 1)
	{
		// FIST CHECK THE HEAD WHICH MUST BE HANDLED SEPARATELY
		JCString listString = this->next();//examine head node

		if (listString == str.c_str())//using JCString to string compare operator
		{
			return false;
		}
		else if (listString > str)
		{
			success = this->push_back(str);//string becomes new head node
		}
		else
		{	// ADVANCE TO NEXT ENTRIES
			//loop to find next highest entries
			success = alphaPlacer(*this, str);
		}

		this->resetIteration();
	}
	return success;
}

//Goes from head to prev to tail. inserts before next highest string in alpha
bool alphaPlacer(DoubleLinkedList& dll, const JCString& str)
{
	bool success = false;

	do
	{
		// Record the node for placement
		JCNode* listNode = dll.it;
		// Extract string and advance the pointer
		JCString listString = dll.next();
		
		// JCString == string compares
		if (listString == str.c_str())
		{
			// Already in list, return false
			success = true;
			dll.it = nullptr;// end search
		}
		else if (listString > str)  // If arg String comes before
		{
			if (listNode != nullptr)// Check for dereference nullptr
			{
				// increments and adds to the list
				dll.insertBefore(listNode, str);
				success = true;
			}
			else {
				cout << "ERROR" << endl;
			}

			// Return true and end search
			dll.it = nullptr;// Ends loop
		}

	} while (dll.hasMore());
	//reached the bottom 
	if (success==false)
	{
		//places on the bottom
		dll.pop_back(str);
		success = true;
	}

	return success;
}

bool DoubleLinkedList::hasMore() const
{
	bool isNull = false;
	if ( this->it != nullptr)
	{  
		isNull = true;
	}
	return isNull;
}

JCString DoubleLinkedList::next() const
{
	JCString itString = this->it->data; // copy string
	this->it = this->it->prev; // move iter down the list

	return itString;
}

void DoubleLinkedList::testValues() const
{
	this->resetIteration();
	int counter = 1;
	while (this->hasMore())
	{
		++counter;
	}
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

// newNode is smaller so comes before the iter node
 void DoubleLinkedList::insertBefore(JCNode* iter, const JCString& str)
{
	// Place before the next node 
	JCNode* newNode =  new JCNode(str); 
	newNode->prev = iter; //point prev to iter
	newNode->next = iter->next;//point next to iter's next
	iter->next->prev = newNode;
	iter->next = newNode; // point iters next to this node

	++this->count;

}

// assumes at least one thing on the top
 //places on the bottom 
bool DoubleLinkedList::pop_back(const JCString& str)
{
	JCNode* newNode =  new JCNode(str); 
	this->tail->prev = newNode;
	newNode->next = this->tail;
	newNode->prev = nullptr;
	//change tail ptr
	this->tail = newNode;

	++this->count;

	return true;
}

//Remove a another list worth of strings
// If any of the strings were removed return true otherwise false
bool DoubleLinkedList::remove(const DoubleLinkedList& dll)
{
	bool success = false;
	int checkCount = this->count;
	
	dll.resetIteration();

	while (dll.hasMore())
	{
		this->remove(dll.next());
	}
	if (checkCount > this->count)
	{
		success = true;
	}
	return success;
}

//Remove a string
bool DoubleLinkedList::remove(const JCString& str)
{
	bool success = false;
	JCNode* key = seeker(str.c_str(), this);// Checks that it has more than one node
	if (key != nullptr)
	{
		if (key == this->head)//if key head is removed
		{
			if (key->prev == nullptr)
			{
				this->head = nullptr;
				this->tail = nullptr;
				cout << "removed last entry "<< endl;
			}
			else
			{
				this->head = key->prev;//remove top replace with next in line
				key->prev->next = nullptr;// replace itself with nullptrS
			}
		}
		else if (key == this->tail)//if tail is removed
		{
			this->tail = key->next;
			key->next->prev= nullptr;
		}
		else
		{
			key->next->prev = key->prev;
			key->prev->next = key->next;
		
		}
		--this->count;
		delete key;
	}
	
	return success;
}


//	Free standing helper function to find an item in list using a string
JCNode* seeker(const char* str, const DoubleLinkedList* dll)
{
	bool found = false;
	JCNode* foundNode = nullptr;

	if (dll->getCount() != 0)
	{
		char* checkString = nullptr; //looking for this string

		dll->it = dll->head; // start at the head node

		while (!found && dll->it != nullptr) //go until we prev ptr is null
		{	
			if(dll->it->data == str) //if we find it 
			{
				foundNode =  dll->it; //return it ptr
				found = true;
			}
			else 
			{
				//move down towards tail
				dll->it = dll->it->prev;
			}
		}
	}
	return foundNode; 
}

bool insertFirsts(DoubleLinkedList& dll, const JCString& str)
{
	bool result = false;
	//check for repeats
	if (dll.head->data != str.c_str())
	{

		if (dll.head->data > str)// Arg String comes before 
		{
			dll.push_back(str);
			result = true;// added item return true

		}
		else if (dll.head->data < str) // Arg String goes under first
		{
			dll.pop_back(str);
			result = true;// added item return true
		}
	}

	return result;

}
