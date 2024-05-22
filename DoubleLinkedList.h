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
	bool push_back(const JCString& str);
	bool pop_back(const JCString& str);
	bool insert(const JCString& str);
	bool remove(const JCString& str);
	bool remove(const DoubleLinkedList& dll);
	int getCount() const;
	void testValues()const;
	DoubleLinkedList operator=(const DoubleLinkedList& dll); // Assignment assignment
	friend ostream& operator<<(ostream& outputStrm, const DoubleLinkedList& dll);		// Write out using operator

private:

	void resetIteration() const;
	JCString next() const;
	bool hasMore() const;
	void insertBefore(JCNode* iter, const JCString& str);
	void initHeadNode(const JCString& str); 

	// Private helpers used for encapsulation
	friend bool insertFirsts(DoubleLinkedList& dll, const JCString& str);
	friend bool alphaPlacer(DoubleLinkedList& dll, const JCString& str);

};



#endif
