/* CS111Project6-Astfalk
*  Create a project that uses a stack to store student exam data and calculate
*  summary statistics.
*  Michael Astfalk
*  Created: 4/12/2022
*  Updated: 4/24/2022
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include "ExamClass.h"
#include "ExamStack.h"

//precondtions: exams is an EMPTY vector of ExamStruct
//postconditions: exams is filled with ExamStructs created by info in the data.txt file
void readData(ExamStack& h);

//Preconditions: exams holds list of students and their exam scores; classAverage is the average of all students'
//exam scores
//Postconditions: print studentName studentAverage "Above Average" if the student's average is above the
//class average
void printResults(ExamStack& h);

int main(void) {
	//declare vector of ExamStruct named exams
	ExamStack stack;

	//read in scores from data.txt
	readData(stack);
	printResults(stack);

	return 0;
}

// function definitions:
void readData(ExamStack& h) {
	ExamClassPtr temp = NULL;
	std::ifstream inFile;	//ifstream for data.txt
	float e1Score = 0.0, e2Score = 0.0, e3Score = 0.0;
	std::string name = "NA";

	//open data.txt file
	inFile.open("data.txt");

	//check if data.txt failed to open
	if (inFile.fail()) {
		std::cout << "data.txt failed to open, program quit\n" << std::endl;
		exit(EXIT_FAILURE);
	}

	//File format: name exam1 exam2 exam3

	while (inFile >> name >> e1Score >> e2Score >> e3Score) {
		//read in from data.txt and set values using constructor
		temp = new ExamClass(e1Score, e2Score, e3Score, name);
		h.push(temp);
	}

	//check if file is empty
	if (h.isEmpty()) {
		std::cout << "data.txt is empty, program quit\n";
		inFile.close();
		exit(EXIT_FAILURE);
	}

	inFile.close();
}

void printResults(ExamStack& h) {
	std::cout << std::fixed << std::setprecision(2) << std::endl;
	std::cout << std::left << std::setw(15) << "Name:" << "Exam avg:\n";
	std::cout << "-------------------------\n";
	while (!h.isEmpty()) {
		ExamClassPtr itr = h.pop();
		std::cout << std::setw(15) << itr->getStudentName() << std::setw(10) << itr->getStudentAverage() << std::endl;
		delete itr;
	}
}