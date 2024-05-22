//// //// //// //// //// //// //// //// 
// Name: Jeff Calderon
// Class Name: CS131
// Section:  33616
// Program 3 DoubleLinkedList
// Description: Main Function
// Demonstration of functioning double
// linked list class copies from file, 
// writes out in one line with spaces. 
// Also  prints the words without 
// ending punctuation. 
//// //// //// //// //// //// //// //// 

#include "JCNode.h"
#include "DoubleLinkedList.h"
#include "../JCString/JCStringV2.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using std::cout;
using std::endl;

// FUNCTION HEADERS
void saveToFIle(DoubleLinkedList& dll, const char* fileName);
void changer(DoubleLinkedList list);
void readFile(const char* fileName, DoubleLinkedList& ddl);

// GLOBAL VARIABLES
const char INPUT_FILE_1[] = "infile1.txt";
const char INPUT_FILE_2[] = "infile2.txt";
const char OUTPUT_FILE_1[] = "outfile1.txt";
const char OUTPUT_FILE_2[] = "outfile2.txt";

int main()
{
	// INITIALIZE LINKED LIST

	DoubleLinkedList list1;
	DoubleLinkedList list2;
	DoubleLinkedList modList1;
	DoubleLinkedList modList2;

	// READ FILE

	readFile(INPUT_FILE_1, list1);
	readFile(INPUT_FILE_2, list2);
	
	// INITIAL COUNT
	cout << left << setfill('-') << setw(20) << "-" << endl; 
	cout << "Collecting the words into the two list we have:" << endl;
	cout << endl;

	cout << setfill(' ') << "list1 count = " << list1.getCount()<< "\nlist2 count = " << list2.getCount() << endl;
	cout << "modList6 count = " << modList1.getCount() << endl;
	cout << "modList6 count = " << modList2.getCount() << endl;
	cout << left << setfill('-') << setw(20) << "-" << endl; 
	cout << setfill(' ') << endl;

	// COPY LIST 

	cout << "Now we copy like so: \n\nmodList1 = list1;\nmodList2 = list2;" << endl;
	cout << endl;
	cout << "Which results in the following " << endl;
	cout << endl;

	modList1 = list1;
	modList2 = list2;

	cout << "list1 count = " << list1.getCount() << "\nlist2 count = " << list2.getCount() << endl;
	cout << "modList1 count = " << modList1.getCount() << endl;
	cout << "modList2 count = " << modList2.getCount() << endl;
	cout << left << setfill('-') << setw(20) << "-" << endl; 
	cout << setfill(' ') << endl;

	// REMOVE LIST

	modList1.remove(list2);
	modList2.remove(list1);

	cout << "After removing list 2 from mod list 1 and list 1 from \nmod list 2 like this,";
	cout << endl << endl;
	cout << "modList1.remove(list2);\nmodList2.remove(list1);" << endl << endl;
	cout << "We see that the number add up as expected." << endl << endl;
	cout << "list1 count = " << list1.getCount() << "\nlist2 count = " << list2.getCount() << endl;
	cout << "modList1 count = " << modList1.getCount() << endl;
	cout << "modList2 count = " << modList2.getCount() << endl;
	cout << left << setfill('-') << setw(20) << "-" << endl; 
	cout << setfill(' ') << endl;
	
	// CHANGER

	cout << "Calling changer functions like this:" << endl << endl;
	cout << "changer(modList1); changer(modList2)" << endl << endl;

	cout << "printing from inside the changer function the size of the" << endl;
	cout <<	"list is : " << endl << endl;

	cout << "modList1 count = ";
	changer(modList1);

	cout << "modList2 count = ";
	changer(modList2);

	cout << "list1 count = " << list1.getCount() << "\nlist2 count = " << list2.getCount() << endl;
	cout << left << setfill('-') << setw(20) << "-" << endl; 
	cout << setfill(' ') << endl;

	// SAVE TO FILE	
	saveToFIle(modList1, OUTPUT_FILE_1);
	saveToFIle(modList2, OUTPUT_FILE_2);

	return 0;
}
// Reads from a file and inserts without ending punctuation marks
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
// Inserts 2 words into the list
void changer(DoubleLinkedList list)
{
	list.insert("ZIP");
	list.insert("ZAP");
	cout << list.getCount() << endl;
}
// Saves to file using the dll built in operator for writing out contents
void saveToFIle(DoubleLinkedList& dll, const char* fileName)

{
	ofstream outfile(fileName, ios::out);
	if (outfile)
	{
		outfile << dll;
		outfile.close();
	}
	else
	{
		cout << "ERROR READING FILE" << endl;
	}

}
