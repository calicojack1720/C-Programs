/* Michael Astfalk
*  CS110-02
*  Project 4
*  Due: 10 December 2021
*  Objective: Read in scores from a txt file, calculate the average, highest, and lowest scores, and output
*  the results to a txt file
*/

#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

double CalculateAvg(const double numList[], const int SIZE);	//calculate average of data values
double FindMax(const double numList[], const int SIZE);			//find the highest value in an array
double FindMin(const double numList[], const int SIZE);			//find the lowest value in an array

int main() {
	ifstream inFile;			//reads in from data.txt
	ofstream outFile;			//outputs to score analysis.txt
	const int MAX_SIZE = 25;	//size of the array numList
	double numList[25];			//array holding the list of numbers
	int count = 0;				//counts the number of entered data
	double avg, max, min;		//double variables for the average, highest, and lowest values

	//open data.txt
	inFile.open("data.txt");

	//test to see if file was opened successfully
	if (inFile.fail())
		cout << "data.txt failed to open properly\n";
	//if file opens successfully
	else {
		//reads in data from data.txt
		while (inFile >> numList[count] && count < MAX_SIZE) {
			++count;
		}

		inFile.close();

		const int SIZE = count;		//total number of scores read into the array from data.txt

		//use functions to get the average, highest, and lowest values
		avg = CalculateAvg(numList, SIZE);
		max = FindMax(numList, SIZE);
		min = FindMin(numList, SIZE);

		//open the output file
		outFile.open("scoreAnalysis.txt");

		//check if scoreAnalysis.txt opened properly
		if (outFile.fail())
			cout << "scoreAnalysis.txt failed to open properly\n";
		//if file opens properly
		else {
			outFile << fixed << setprecision(2) << "The average score is " << avg << endl;
			outFile << setprecision(0) << "The highest score is " << max << endl;
			outFile << setprecision(0) << "The lowest score is " << min << endl;
			outFile << setprecision(0) << "The total number of scores is " << SIZE << endl;

			outFile.close();

			//output message letting the user know the program ran successfully
			cout << "Data analysis and calculations successful!\n";
		}
	}

	return 0;
}

double CalculateAvg(const double numList[], const int SIZE) {
	double avg = 0;		//average of values in an array
	
	//calculate average
	for (int i = 0; i < SIZE; ++i)
		avg += numList[i];

	avg /= SIZE;

	return avg;
}

double FindMax(const double numList[], const int SIZE) {
	double max = numList[0];	//highest number in an array

	//find the highest number in the array
	for (int i = 0; i < SIZE; ++i) {
		if (numList[i] > max)
			max = numList[i];
	}

	return max;
}

double FindMin(const double numList[], const int SIZE) {
	double min = numList[0];	//lowest number in the array

	//find the lowest number in the array
	for (int i = 0; i < SIZE; ++i) {
		if(numList[i] < min)
			min = numList[i];
	}

	return min;
}