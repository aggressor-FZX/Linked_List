#include "DoubleLinkedList.h"
#include <iostream>
using std::cout;
using std::endl;
//Helper functions
bool isLargerAlpha(const JCString& listString, const JCString& newString);
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
ostream& operator<<(ostream& inputStrm, const DoubleLinkedList& dll)
{
	// While there is a node to write out, as in not nullptr
	while (dll.hasMore())
	{
		inputStrm << dll.next() << "\n";//write out the current data
	}

	return inputStrm;//return input stream for chaining
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


// Smaller letters come first hence A < B < C etc. list starts small goes large
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
				success = true;// added item return true
			}
		}
	}
	// CASE WHERE THERE ARE ALREADY MANY ENTRIES
	else if(this->count > 1) 
	{	
		// FIST CHECK THE HEAD WHICH MUST BE HANDLED SEPARATELY

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
		{	// ADVANCE TO NEXT ENTRIES
			do
			{
				JCNode* listNode = this->it;
				listString = this->next();

				if (listString == str.c_str())// use JCString to string compare operator
				{
					// Already in list, return false
					success = true;
					this->it = nullptr;// end search
				}
				else if (listString > str)  // If arg String comes before
				{
					if (listNode != nullptr)// Check for dereference nullptr
					{
						// Insert behind prev from iterator since we advanced iter after next() call
						
						this->insertBefore(listNode, str);// increments and adds to the list
					}
					else {
						this->testValues();
					}
					// Return true and end search
					success = true;
					this->it = nullptr;// Ends loop
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
	this->resetIteration();
	int counter = 1;
	while (this->hasMore())
	{
		cout << "Number " << counter << " is " << this->next() << " of " << this->count << endl;
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

bool DoubleLinkedList::remove(const JCString& str)
{
	bool success = false;
	JCNode* key = seeker(str.c_str(), this);// Checks that it has more than one node
	if (key != nullptr)
	{
		if (key == this->head)//if head is removed
		{
			this->head = key->prev;//remove top replace with next in line
			key->prev->next = nullptr;// replace itself with nullptr
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
	bool notFound = true;
	JCNode* result = nullptr;

	if (dll->getCount() != 0)
	{
		char* checkString = nullptr; //looking for this string

		dll->it = dll->head; // start at the head node

		while (notFound && dll->it != nullptr) //go until we prev ptr is null
		{	
			if(dll->it->data == str) //if we find it 
			{
				result =  dll->it; //return it ptr
				notFound = false;
			}
			else 
			{//move down towards tail
				dll->it = dll->it->prev;
			}
		}
	}
	return result; 
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
