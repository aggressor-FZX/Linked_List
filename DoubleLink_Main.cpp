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
	JCString jcstr3("World");
	bool compare = jcstr1 == jcstr2.c_str();
	cout << " compare result hello to world " << compare << endl;
	bool compare2 = jcstr2 == jcstr3.c_str();
	cout << " compare result world to world " << compare2 << endl;

	JCString jcstr3("Goodbye");
	JCString jcstr4("Cruel");
	JCString jcstr5("World");

	dll.insert(jcstr1);
	dll.insert(jcstr2);
	dll.push_back(jcstr3);
	dll.push_back(jcstr4);
	dll.push_back(jcstr5);

	cout << dll << endl;

	cout << "Count: " << dll.getCount() << endl;

	dll.remove(jcstr2);
	cout << dll << endl;

	cout << "Count: " << dll.getCount() << endl;


	return 0;

}


