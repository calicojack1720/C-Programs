/* CS111Project2-Astfalk
*  Compares linear and binary search
*  Michael Astfalk
*  Created: 2/21/2022
*  Updated: 3/9/2022
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;

#define NOT_FOUND -1
const int SIZE = 20000;
typedef int Data[SIZE];



//precondition: integer array with size n is declared
//postcondition: each element of the array is initialized with its index
void initializeArraySorted(Data array, int size);

//precondition: integer array with size n is declared, integer value of target
//postcondition: the index of target in the array is returned or -1 if it is not found using linear search
int linearSearch(Data array, int size, int target);

//precondition: integer array with size n is declared, integer value of target
//postcondition: the index of target in the array is returned or -1 if it is not found using binary search
int binarySearch(Data array, int size, int target);

// insert function signatures for linear and binary search
int gCOUNT_LINEAR = 0;
int gCOUNT_BINARY = 0;

int main(void) {
	// initialize srand
	srand(time(0));
	Data a;
	initializeArraySorted(a, SIZE);
	int target = 0;

	//declare ofstream to output data to
	ofstream outFile;
	
	//open file
	outFile.open("myData.txt");
	if (outFile.fail()) {
		cout << "myData.txt failed to open";
		return 1;
	}

	for (int workingArraySize = 10; workingArraySize < SIZE; workingArraySize += 10) {
		gCOUNT_LINEAR = 0;
		gCOUNT_BINARY = 0;
		target = rand() % workingArraySize;
		cout << "Target " << target << " ";

		//each search function should increment the proper global to keep track of the
		//number of comparisons
		int b = linearSearch(a, workingArraySize, target);
		b = binarySearch(a, workingArraySize, target);

		

		//output workingArraySize, gCOUNT_LINEAR, and gCOUNT_BINARY
		outFile << workingArraySize << " " << gCOUNT_LINEAR << " " << gCOUNT_BINARY << endl;
	}

	//close txt file
	outFile.close();

	return 0;
}

void initializeArraySorted(Data array, int size) {
	for (int i = 0; i < size; ++i) {
		array[i] = i;
	}
}

int linearSearch(Data array, int size, int target) {
	for (int i = 0; i < size; ++i) {
		++gCOUNT_LINEAR;
		if (array[i] == target) {
			return i;
		}
	}

	return -1;
}

int binarySearch(Data array, int size, int target) {
	int left = 0;
	int right = size - 1;

	while (right >= left) {
		int middle = (left + right) / 2;
		++gCOUNT_BINARY;
		if (array[middle] == target)
			return middle;
		if (target < array[middle])
			right = middle - 1;
		else
			left = middle + 1;

		
	}
	
	return -1;
}