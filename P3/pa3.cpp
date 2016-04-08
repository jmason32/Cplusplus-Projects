//First we must support file input/handling 

#include <fstream> 	//This is the header file that allows file handling
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//Stack using linked list 

struct node {
	string KW; //KW= KeyWord
	node* link = NULL;
};

//For the stack I only need to insert and delete from the stack

class stack {

	node* head;
	node* now;
	node* temp;
public:

	stack() {
		head = NULL;
		now = NULL;
		temp = NULL;
	};

	void push(string KW) { //insert only from the top
		temp = new node;
		temp->KW = KW;

		if (head == NULL) {
			head = temp;
			now = head;
		
		}

		else {
			temp->link = head;
			head = temp;
		}
	};

	bool empty() {
		bool empty = false;

		if (head == NULL) {
			empty = true;
		}
		return empty;
	};

	void pop() {
		if (empty())
			return;
		else {
			now = head->link;
			delete head;
			head = now;
		}
	};

};

void repeats(string array[20]);


int main(int argc, char* argv[]) {

	char* file;

	if (argc!=2){
		cout<< "Invaid input" << endl;
		return -1;
	}
	else {
	 	file = argv[1];
	}

	stack* s1 =  new stack();
	int maxD = 0;
	int depth = 0;

	string keywords[20]; int k = 0;
	string error[20]; int e = 0;
	string identifiers[20]; int m = 0;
	string constants[20]; int c = 0;
	string delimiters[20]; int d = 0;
	string operators[20]; int o = 0;
	int i = 0, j = 0, l = 0, n = 0;		//counters for filling arrays 
	int pr[10] = { 0 };				//counters for printing identifier arrays




									//You must declare your own objects to read and write files 

	ifstream file_reader(file); //this searches for the text file test1
	if (!file_reader.is_open()) {
		cout << "File is not in directiory could not be opened" << endl;
		return -1;
	}
	//is_open is a method checking to see if the file could be opened, bool method true
	//We need to know read the file into a string object

	//string test_code;

	//file_reader >> test_code; //This line only gets the character before the first whitespace
	//cout << test_code;  		//Need some code that will parse through the entire file

	/*while(!file_reader.eof()){
	file_reader >> test_code;
	}
	cout << test_code << endl;
	*///This only gets the last line, the string is being over written. 

	string test_code[100];	//This creates a array of 1000 spaces
	string line;
	int count = 0;

	for (int i = 0; i<100;i++)
		test_code[i] = "0";
	//This sets every space to 0;

	while (!file_reader.eof()) {
		file_reader >> line;
		test_code[i] = line;
		i++;
	}

	for (int i = 0; i<100;i++) {
		//cout << test_code[i] << endl;
		if (test_code[i] != "0")
			count++;
	}
	//cout << count;

	string* temp = new string[count];

	for (int i = 0; i<count; i++) {
		temp[i] = test_code[i];
	}

	//delete[] test_code;
	string* code = new string[count];

	for (int i = 0; i<count; i++) {
		code[i] = temp[i];
	}

	//delete temp;

	/*for (int i = 0; i<count; i++) {
		cout << code[i] << endl;
	}*/

	//Now we need to extract keywords, identifiers, constants, operators, delimiters
	//Need to parse throught the arrary and take out all characters that 
	//"()"

	//int j=0;
	for (int i = 0; i < 20; i++) {
		keywords[i] = "0";
	}

	for (int i = 0; i < 20; i++) {
		error[i] = "0";
	}

	for (int i = 0; i < 20; i++) {
		identifiers[i] = "0";
	}

	for (int i = 0; i < 20; i++) {
		constants[i] = "0";
	}

	for (int i = 0; i < 20; i++) {
		delimiters[i] = "0";
	}

	for (int i = 0; i < 20; i++) {
		operators[i] = "0";
	}



	//This gets the size of the string at the index of the array 
	for (int i = 0; i < count; i++) {
		if (code[i].compare("BEGIN") == 0 || code[i].compare("END") == 0 || code[i].compare("FOR") == 0) {
			keywords[k] = code[i];
			k++;
		}

		else if (isupper(code[i].at(0))) {
			error[e] = code[i];
			e++;
		}

		else {
			for (int j = 0; j < code[i].size(); j++) {
				if (isalpha(code[i].at(j))) {
					string whole;
					whole = code[i].at(j);

					while (j != code[i].size() - 1) {
						if (isalpha(code[i].at(j + 1))) {
							whole = whole + code[i].at(j + 1);
							j++;
						}
						else
							break;
					}

					identifiers[m] = whole;
					m++;
				}

				else if (isdigit(code[i].at(j))) {
					string wholeint;
					wholeint = code[i].at(j);

					while (j != code[i].size() - 1) {
						if (isdigit(code[i].at(j + 1))) {
							wholeint = wholeint + code[i].at(j + 1);
							j++;
						}
						else
							break;
					}

					constants[c] = wholeint;
					c++;
				}

				else if (code[i].at(j) == ';' || code[i].at(j) == ',') {
					delimiters[d] = code[i].at(j);
					d++;
				}

				else if (code[i].at(j) == '=' || code[i].at(j) == '/' || code[i].at(j) == '*') {
					operators[o] = code[i].at(j);
					o++;
				}

				else if (code[i].at(j) == '+') {
					string wholeop;
					wholeop = code[i].at(j);

					while (j != code[i].size() - 1) {
						if (code[i].at(j + 1) == '+') {
							wholeop = wholeop + code[i].at(j + 1);
							break;
						}
						else
							break;
					}
					operators[o] = wholeop;
					o++;
				}

				else if (code[i].at(j) == '-') {
					string wholeop;
					wholeop = code[i].at(j);

					while (j != code[i].size() - 1) {
						if (code[i].at(j + 1) == '-') {
							wholeop = wholeop + code[i].at(j + 1);
							break;
						}
						else
							break;
					}
					operators[o] = wholeop;
					o++;
				}
			}
		}
	}


	// We get the size of the string, and then search that string for other syntax

	/*
	else {

	for (int j=0; j < code[i].size(); j++)  {
	if (isalpha(code[i].at(j))) {

	}
	}
	}
	*/

	repeats(identifiers);
	repeats(delimiters);
	repeats(operators);
	repeats(constants);

	/*
	for (int i = 0; i < 20;) {
		if (keywords[i] == "0")
			i++;
		else {
			cout << keywords[i] << endl;
			i++;
		}
	}


	for (int i = 0; i < 20;) {
		if (error[i] == "0")
			i++;
		else {
			cout << error[i] << endl;
			i++;
		}
	}


	for (int i = 0; i < 20;) {
		if (identifiers[i] == "0")
			i++;
		else {
			cout << identifiers[i] << endl;
			i++;
		}
	}

	for (int i = 0; i < 20;) {
		if (constants[i] == "0")
			i++;
		else {
			cout << constants[i] << endl;
			i++;
		}
	}

	for (int i = 0; i < 20;) {
		if (delimiters[i] == "0")
			i++;
		else {
			cout << delimiters[i] << endl;
			i++;
		}
	}

	for (int i = 0; i < 20;) {
		if (operators[i] == "0")
			i++;
		else {
			cout << operators[i] << endl;
			i++;
		}
	}*/

	/*Now i need to go through every array other than the keyword array
	and take out an repeats*/

	for (int i = 0; i < 20; i++) {
		string key = keywords[i];
		if (key.compare("FOR") == 0) {
			s1->push("FREE");
			depth++;
			if (depth>maxD) {
				maxD = depth;
			}
		}
		else if (key.compare("END") == 0) {
			if (s1->empty()) {
				cout << "syntax error" << endl;
			}
			else {
				depth = 0;
				s1->pop();
			}
		}
	}

	//cout << maxD << endl;

	repeats(keywords);

	/*for (int i = 0; i < 20;) {
		if (keywords[i] == "0")
			i++;
		else {
			cout << keywords[i] << endl;
			i++;
		}
	}*/


	cout << "The maximum depth of nested loop(s) is "<< maxD << endl;

	cout << "Keywords: ";
	for (int i = 0; i < 20;) {
		if (keywords[i] == "0")
			i++;
		else {
			cout << keywords[i] << " ";
			i++;
		}
	}
	cout << endl;

	cout << "Identifier: ";
	for (int i = 0; i < 20;) {
		if (identifiers[i] == "0")
			i++;
		else {
			cout << identifiers[i] << " ";
			i++;
		}
	}
	cout << endl;

	cout << "Constants: ";
	for (int i = 0; i < 20;) {
		if (constants[i] == "0")
			i++;
		else {
			cout << constants[i] << " ";
			i++;
		}
	}
	cout << endl;

	cout << "Operators: ";
	for (int i = 0; i < 20;) {
		if (operators[i] == "0")
			i++;
		else {
			cout << operators[i] << " ";
			i++;
		}
	}
	cout << endl;


	cout << "Delimiter: ";
	for (int i = 0; i < 20;) {
		if (delimiters[i] == "0")
			i++;
		else {
			cout << delimiters[i] << " ";
			i++;
		}
	}
	cout << endl;

	cout << "Syntax Error(s): ";
	for (int i = 0; i < 20;) {
		if (error[i] == "0")
			i++;
		else {
			cout << error[i] << " ";
			i++;
		}
	}
	cout << endl;






}




void repeats(string array[20]) {

	string key;

	for (int i = 0; i < 20; i++) {
		key = array[i];

		for (int j = i + 1; j < 20; j++) {

			if (key.compare(array[j]) == 0) {
				array[j] = "0";
			}
		}
	}
}