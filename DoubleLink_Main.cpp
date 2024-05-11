#include "JCNode.h"
#include "DoubleLinkedList.h"
#include "../JCString/JCStringV2.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	DoubleLinkedList dll;
	JCString jcstr1("Hello");
	JCString jcstr2("World");
	JCString jcstr3("Goodbye");
	JCString jcstr4("Cruel");
	JCString jcstr5("World");

	dll.insert(jcstr1);
	dll.insert(jcstr2);
	dll.insert(jcstr3);
	dll.insert(jcstr4);
	dll.insert(jcstr5);

	cout << dll << endl;

	cout << "Count: " << dll.getCount() << endl;
	dll.remove(jcstr2);
	cout << dll << endl;

	cout << "Count: " << dll.getCount() << endl;


	return 0;

}


