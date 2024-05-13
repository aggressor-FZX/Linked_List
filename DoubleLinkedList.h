#include "JCNode.h"
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <istream>

using namespace std;

class DoubleLinkedList
{
public:
	JCNode* head;
	JCNode* tail;
	mutable JCNode* it;
	int count = 0;


	DoubleLinkedList(); // default
	~DoubleLinkedList(); // destructor

	DoubleLinkedList(const DoubleLinkedList& dll);// copy constructor
	bool insert(const JCString& str);
	bool remove(const JCString& str);
	int getCount() const;
	
	DoubleLinkedList operator=(const DoubleLinkedList& dll); // Assignment assignment
	friend ostream& operator<<(ostream& inputStrm, const DoubleLinkedList& dll);		// Write out using operator

private:

	void resetIteration() const;
	JCString next() const;
	bool hasMore() const;


};



#endif
