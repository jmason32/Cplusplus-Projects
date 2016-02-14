#include <iostream> 
using namespace std;
//A array that contains all the numbers that can be used in the magic square 

void printing(int** magicsq, int size);
bool check(int i, int j, int** magicsq);
bool topa(int i);
bool endright(int j, int size);
void printing(int** magicsq, int size);
void countingrows(int** magicsq, int size);
void countingcolumns(int** magicsq,int size);
void countingcolumns(int** magicsq,int size);
void countingdiagonal(int** magicsq,int size);

int main() {

	int size;
	cout << "What size magic square do you want: ";
	cin >> size;

	//This scale is the number
	int scale = ((size*(size*size + 1)) / 2);
	//cout << scale << endl;

	/* This is an array that contains allthe possible values
	that can be in the magic square*/
	int* set = new int[size*size];
	//Sets the values in the array
	for (int i = 0; i<(size*size);i++) {
		set[i] = (i + 1);
	}
	//Printing set array
	/*for (int i = 0; i<(size*size);i++) {
		cout << set[i] << " ";
	}*/

	//Making a 2D array using pointers 
	int** magicsq = new int*[size];
	for (int i = 0;i < size;i++) {
		magicsq[i] = new int[size];
	}
	cout << endl;

	//Initialy setting every space in the array to zero;
	for (int i = 0; i<size;i++) {
		for (int j = 0; j<size;j++) {
			magicsq[i][j] = 0;
		}
	}

	/*for (int i = 0; i<size;i++) {
		for (int j = 0; j<size;j++) {
			cout << magicsq[i][j] << " ";
		}
		cout << endl;
	}*/

	int middle = (size - 1) / 2;
	//cout << middle << endl;

	int i = 0;
	int j = middle;
	int k = 0;
	magicsq[i][j] = set[k];
	k++;
	//printing(magicsq, size);
	while (k != (size*size)) {
		bool top = topa(i);
		bool endr = endright(j, size);
		bool wasER = false;
		bool wasTOP = false;
		bool allclear = true;
		if (top == true) {
			i = size - 1;
			wasTOP = true;
		}
		else {
			i = i - 1;

		}
		if (endr == true) {
			j = 0;
			wasER = true;
		}

		else {
			j = j + 1;
			wasER = false;

		}


		bool taken = check(i, j, magicsq);
		if (taken == true) {
			if (top == true) {
				i = 0;
			}
			else
				i = i + 1;

			if (endr == true) {
				j = size - 1;
			}
			else
				j = j - 1;

			i = i + 1;
			magicsq[i][j] = set[k];
			k++;
		}

		if (taken == false) {
			magicsq[i][j] = set[k];
			k++;
		}
	}
	printing(magicsq,size);
	
	cout<< "Sum of the rows: ";
	countingrows(magicsq,size);
	cout<<endl;
	cout<< "Sum of the columns: "; 
	countingcolumns(magicsq,size);
	cout<<endl;
	cout<< "Sum of the diagonals: "; 
	countingdiagonal(magicsq,size);
	cout<<endl;
} 



bool check(int i, int j, int** magicsq) {
	bool t = false;
	if (magicsq[i][j] != 0)
		t = true;
	return t;
}

bool topa(int i) {
	bool top = false;
	if (i == 0)
		top = true;
	return top;
}

bool endright(int j, int size) {
	bool endr = false;
	if (j == size - 1)
		endr = true;
	return endr;
}

void printing(int** magicsq, int size) {
	for (int i = 0; i<size;i++) {
		for (int j = 0; j<size;j++) {
			cout << magicsq[i][j] << " ";
		}
		cout << endl;
	}
}

void countingrows(int** magicsq, int size){
	for (int i = 0; i<size;i++) {
		int sum=0;
		for (int j = 0; j<size;j++) {
			sum+=magicsq[i][j];
		}
		cout<< sum << " ";
	}
}

void countingcolumns(int** magicsq,int size){
	for (int j = 0; j<size;j++) {
		int sum=0;
		for (int i = 0; i<size;i++) {
			sum+=magicsq[i][j];
		}
		cout<< sum << " ";
	}
}

void countingdiagonal(int** magicsq,int size){ 
	int f=0;
	for (int i=0; i<size;i++) {
		f+=magicsq[i][i];
	}
	cout<< f << " ";
int l=0;
	for(int i=size-1;i>=0;i--){
		l+=magicsq[i][i];
	}
	cout<< l << " ";
}