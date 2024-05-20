#include "JCNode.h"
#include "DoubleLinkedList.h"
#include "../JCString/JCStringV2.h"
#include <iostream>
#include <vector>
#include <fstream>

using std::cout;
using std::endl;
// Function Headers
void saveToFIle(const vector<JCString>& wordVec, const char* fileName, int wordPerLin);
// GLOBAL VARIABLES
const char INPUT_FILE[] = "infile3.txt";
const char OUTPUT_FILE[] = "outfile_case.txt";
const int WORD_LENGTH = 1; //words to concatenate per JCString
const int WORDS_PER_LINE = 4; //JCStrings per output to file

int main()
{
	DoubleLinkedList dll;
	JCString jcstr0("a");
	JCString jcstr1("Hello");
	JCString jcstr2("World");
	JCString jcstr3("Goodbye.");
	jcstr3.removePunctuation();
	cout << "removed punctutation " << jcstr3 << endl;
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
//	dll.remove(jcstr3);
//dll.remove(jcstr0);
//dll.remove(jcstr1);
//dll.remove(jcstr2);
//dll.testValues() ;

	DoubleLinkedList secondDll;
	secondDll = dll;
//	DoubleLinkedList thirdDll;
//	thirdDll.insert(jcstr3);
//	thirdDll.insert(jcstr4);
//	thirdDll.insert(jcstr5);
//	thirdDll.insert(jcstr6);
//	secondDll.remove(thirdDll);

	secondDll.testValues();


	cout << "second list Count: " << secondDll.getCount() << endl;
	cout << "removing  World " << endl;
	secondDll.remove(jcstr5);
	cout << secondDll << endl;

	cout << "Count: " << dll.getCount() << endl;


	return 0;

}
	// READ FILE
	//vector<JCString> words;
//	ifstream fileInput(INPUT_FILE);
/*/

	if (fileInput.fail()) {
		cout << "ERROR READING FILE";
		exit(1);
	}


	int wordCnt = 0;
	JCString fileString;// single jcstring to read in file data
	JCString pushString; //jcstring  to collect concatenated string


	// Loop reads in each words into JCString object iterates thru jcstring vector
	do
	{
		//if multiple of 5 and jcstring is not empty 
		if (wordCnt % WORD_LENGTH == 0 && pushString.c_str()[0] != '\0')
		{
			//then push into vector
			words.push_back(pushString);
			//reset push string
			pushString = "";
		}
		fileInput >> fileString; //collect word from stream to jcstring
		pushString = pushString + fileString; //concatenate word to push string

		// If end of file, push back what ever is left
		if (fileInput.eof())
		{
			words.push_back(pushString);
		}
		++wordCnt;
	} while (!fileInput.eof());



	// SAVE TO FILE	
//	saveToFIle(DoubleLinkedList & dll, OUTPUT_FILE, WORDS_PER_LINE);




// Saves a JCString vector to a file
/*void saveToFIle(DoubleLinkedList & dll, const char* fileName, int wordPerLin)
{
	ofstream outfile(fileName, ios::out);
	if (!outfile)
	{
		cout << "ERROR READING FILE" << endl;
	}

	int line = 0;

	for (const JCString str : wordVec)
	{
		// left aligning and spaced 
		// cout << str.c_str() << endl;
		outfile <<
			left << setw(13) << str << " " << str.length() << ":" << setw(10)
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

