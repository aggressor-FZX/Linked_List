#include "JCNode.h"
#include "DoubleLinkedList.h"
#include "../JCString/JCStringV2.h"
#include <iostream>
#include <vector>
#include <fstream>

using std::cout;
using std::endl;
// Function Headers
void saveToFIle(DoubleLinkedList& dll, const char* fileName, int wordPerLin);
void changer(DoubleLinkedList list);
void readFile(const char* fileName, DoubleLinkedList& ddl);
// GLOBAL VARIABLES
const char INPUT_FILE_1[] = "infile1.txt";
const char INPUT_FILE_2[] = "infile2.txt";
const char OUTPUT_FILE_1[] = "outfile1.txt";
const char OUTPUT_FILE_2[] = "outfile2.txt";
const int WORD_LENGTH = 1; //words to concatenate per JCString
const int WORDS_PER_LINE = 4; //JCStrings per output to file

int main()
{
	DoubleLinkedList list1;
	DoubleLinkedList list2;
	DoubleLinkedList modList1;
	DoubleLinkedList modList2;
	// READ FILE
	readFile(INPUT_FILE_1, list1);
	readFile(INPUT_FILE_2, list2);

	cout << " collecting the words into the two list we have" << endl;
	cout << "list1 count = " << list1.getCount()<< "\nlist2 count = " << list2.getCount() << endl;
	cout << "modList1 count = " << modList1.getCount() << endl;
	cout << "modList2 count = " << modList2.getCount() << endl;

	// COPY LIST 

	cout << " now we copy " << endl;
	modList1 = list1;
	modList2 = list2;

	cout << "like so: \n modList1 = list1\n modList2 = list2" << endl;
	cout << "list1 count = " << list1.getCount() << "\nlist2 count = " << list2.getCount() << endl;
	cout << "modList1 count = " << modList1.getCount() << endl;
	cout << "modList2 count = " << modList2.getCount() << endl;

	// REMOVE LIST

	modList1.remove(list2);
	modList2.remove(list1);

	cout << " After removing list2 from mod1 and list1 from mod2 ";
	cout << "\nmodList1.remove(list2);\nmodList2.remove(list1);" << endl;
	cout<<"the we see that the number add up as expected" << endl;
	cout << "list1 count = " << list1.getCount() << "\nlist2 count = " << list2.getCount() << endl;
	cout << "modList1 count = " << modList1.getCount() << endl;
	cout << "modList2 count = " << modList2.getCount() << endl;
	cout << "	modList1.remove(list2);\nmodList2.remove(list1);" << endl;
	
	// CHANGER
	cout << "calling changer functions" << endl;
	cout << "changer(modList1); changer(modList2)" << endl;

	changer(modList1);
	changer(modList2);

	cout << "Now the size of the list is: " << endl;
	cout << "list1 count = " << list1.getCount() << "\nlist2 count = " << list2.getCount() << endl;
	cout << "modList1 count = " << modList1.getCount() << endl;
	cout << "modList2 count = " << modList2.getCount() << endl;

	// SAVE TO FILE	

	saveToFIle(modList1, OUTPUT_FILE_1, WORDS_PER_LINE);
	saveToFIle(modList2, OUTPUT_FILE_2, WORDS_PER_LINE);

	return 0;
}
void readFile(const char* fileName,DoubleLinkedList& dll)
{
	ifstream fileInput(fileName);
	JCString fileString;
	if (fileInput.fail()) {
		cout << "ERROR READING FILE";
		exit(1);
	}
	while (!fileInput.eof())
	{
		fileInput >> fileString; //collect word from stream to jcstring
		fileString.removePunctuation();//remove punctuation
		dll.insert(fileString);
	}
}
void changer(DoubleLinkedList list)
{
	list.insert("ZIP");
	list.insert("ZAP");
}


void saveToFIle(DoubleLinkedList& dll, const char* fileName, int wordPerLin)

{
	ofstream outfile(fileName, ios::out);
	if (!outfile)
	{
		cout << "ERROR READING FILE" << endl;
	}

	int line = 0;

	while(dll.hasm)	
	{
		// left aligning and spaced 
		// cout << str.c_str() << endl;
		outfile << left << setw(13) << str << " " << str.length() << ":" << setw(10)
			<< str.capacity();

		line++;

		// words per line before carriage return 
		if (line % wordPerLin == 0)
		{
			outfile << endl;
		}
	}
	outfile.close();
}
*/

