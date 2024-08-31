/* CS111Project4-Astfalk
*  Create a project that uses a vector of class objects to store student exam data and calculate
*  summary statistics.
*  Created: 3/20/2022
*  Updated: 3/25/2022
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include "ExamClass.h"

//precondtions: exams is an EMPTY vector of ExamStruct
//postconditions: exams is filled with ExamStructs created by info in the data.txt file
void readData(std::vector<ExamClass>& exams);

//precondition: exams holds list of student and their exam scores
//postcondition: returns a float value of the average of all student exam scores
float classAverage(std::vector <ExamClass> exams);

//Preconditions: exams holds list of students and their exam scores; classAverage is the average of all students'
//exam scores
//Postconditions: print studentName studentAverage "Above Average" if the student's average is above the
//class average
void printResults(std::vector<ExamClass> exams, float classAverage);

int main(void) {
	//declare vector of ExamStruct named exams
	std::vector<ExamClass> exams;
	float classAvg = 0.0;

	//read in scores from data.txt
	readData(exams);
	classAvg = classAverage(exams);
	printResults(exams, classAvg);

	return 0;
}

// function definitions:
void readData(std::vector<ExamClass>&exams) {
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
	int i = 0;

	while (inFile >> name >> e1Score >> e2Score >> e3Score) {
		//read in from data.txt and set values using constructor
		exams.push_back(ExamClass(e1Score, e2Score, e3Score, name));

		//compute student average
		exams.at(i).computeStudentAverage();

		//increment i
		++i;
	}

	//check if file is empty
	if (exams.size() == 0) {
		std::cout << "data.txt is empty, program quit\n";
		inFile.close();
		exit(EXIT_FAILURE);
	}

	inFile.close();
}

float classAverage(std::vector<ExamClass> exams) {
	float avg = 0.0;
	for (int i = 0; i < exams.size(); ++i) {
		avg += exams.at(i).getExam1();
		avg += exams.at(i).getExam2();
		avg += exams.at(i).getExam3();
	}

	avg /= exams.size() * 3;
	return avg;
}

void printResults(std::vector<ExamClass> exams, float classAvg) {
	std::cout << std::fixed << std::setprecision(2) << "The class average of the exam averages was " << classAvg << std::endl;
	std::cout << std::left << std::setw(15) << "Name:" << "Exam avg:\n";
	std::cout << "-------------------------\n";
	for (int i = 0; i < exams.size(); ++i) {
		std::cout << std::setw(15) << exams.at(i).getStudentName() << std::setw(10) << exams.at(i).getStudentAverage();
		if (exams.at(i).getStudentAverage() > classAvg)
			std::cout << "Above Average";
		std::cout << std::endl;
	}
}