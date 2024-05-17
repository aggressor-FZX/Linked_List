#include "JCNode.h"
#include "DoubleLinkedList.h"
#include "../JCString/JCStringV2.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	DoubleLinkedList dll;
	JCString jcstr0("a");
	JCString jcstr1("Hello");
	JCString jcstr2("World");
	JCString jcstr3("Goodbye");
	JCString jcstr4("Cruel");
	JCString jcstr5("World");
	JCString jcstr6("aa");
	JCString jcstr7("b");
	JCString jcstr8("cat");
	JCString jcstr9("dog");
	JCString jcstr10("emu");
	dll.insert(jcstr0);
	dll.insert(jcstr1);
	dll.insert(jcstr2);
	dll.insert(jcstr3);
	dll.insert(jcstr4);
	dll.insert(jcstr5);
	dll.insert(jcstr6);
	dll.insert(jcstr7);
	dll.insert(jcstr8);
	dll.insert(jcstr9);
	dll.insert(jcstr10);
	dll.testValues();

//	cout << dll << endl;

//	cout << "Count: " << dll.getCount() << endl;

	//dll.remove(jcstr2);
	//cout << dll << endl;

	//cout << "Count: " << dll.getCount() << endl;


	return 0;

}


