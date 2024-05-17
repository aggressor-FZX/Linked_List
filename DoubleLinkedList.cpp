#include "DoubleLinkedList.h"
#include <iostream>
using std::cout;
using std::endl;
//Helper functions
bool isLargerAlpha(const JCString& listString, const JCString& newString);
JCNode* seeker(const char* str, const DoubleLinkedList* dll);

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
	this->resetIteration();
	bool success = false;

	// Case where list is empty
	if (this->count == 0)
	{
		this->initHeadNode(str);
		success = true;
		
	}
	// Case where this is only one item in list
	else if(this->count == 1)
	{
		if (this->head->data == str.c_str())//using JCString to string compare operator
		{
			// Already in list, return false
			 return false;
		}
		else
		{
			success  = isLargerAlpha(this->head->data, str);
			if (success)
			{
				this->push_back(str);
			}
			else 
			{
				this->pop_back(str);
				success = true;
			}
		}
	}
	// Case where there are already many entries
	else if(this->count > 1) 
	{	// Fist check the head which must be handled separately

		JCString listString = this->next();//examine head node

		if (listString == str.c_str())//using JCString to string compare operator
		{
			return false;
		}
		else if( listString > str)
		{
			success = this->push_back(str);//string becomes new head node
		}
		else
		{	//advance to next entry
			do
			{
				listString = this->next();

				if (listString == str.c_str())// use JCString to string compare operator
				{
					// Already in list, return false
					cout << "in the list" << endl;
					success = true;
					this->it = nullptr;// end search
				}
				else if (listString > str)  // Arg String comes before
				{
					this->insertBefore(this->it, str);//increments and adds to the list
					success = true;
					this->it = nullptr;//end search
				}
			} while (this->hasMore());

			//reached the bottom without success place on bottom
			if (success == false)
			{
				this->pop_back(str);
				success = true;
			}
		}
	}

	this->resetIteration();
	//this->testValues();
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
	int counter = 1;
	this->it = this->head;
	while (this->it)
	{
		cout << "Number " << counter << " is " << this->it->data.c_str() << " of " << this->count << endl;
		this->it = this->it->prev;
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
void DoubleLinkedList::pop_back(const JCString& str)
{
	JCNode* newNode =  new JCNode(str); 
	this->tail->prev = newNode;
	newNode->next = this->tail;
	newNode->prev = nullptr;
	//change tail ptr
	this->tail = newNode;

	++this->count;

}

//	Free standing helper function to find an item in list using a string
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
bool isLargerAlpha(const JCString& listString, const JCString& newString)
{
	bool comesBefore = false;
	
	if(listString > newString )// Arg String comes before 
	{
		//string arg becomes new head
		comesBefore = true;
		// call push back to handle it and increment this->count
	}
	else if (listString < newString) // Arg String goes under first
	{
		comesBefore =false;
	}

	return comesBefore;

}
