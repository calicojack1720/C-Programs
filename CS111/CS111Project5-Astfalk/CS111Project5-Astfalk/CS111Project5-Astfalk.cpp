/* CS111Project5-Astfalk
*  Create a project that uses a vector of class objects to store student exam data and calculate
*  summary statistics.
*  Created: 4/1/2022
*  Updated: 4/9/2022
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include "ExamClass.h"

//precondtions: exams is an EMPTY vector of ExamStruct
//postconditions: exams is filled with ExamStructs created by info in the data.txt file
void readData(ExamClassPtr &head);

//precondition: exams holds list of student and their exam scores
//postcondition: returns a float value of the average of all student exam scores
float classAverage(ExamClassPtr head);

//Preconditions: exams holds list of students and their exam scores; classAverage is the average of all students'
//exam scores
//Postconditions: print studentName studentAverage "Above Average" if the student's average is above the
//class average
void printResults(ExamClassPtr head, float classAverage);

//Preconditions: head and newNode are ExamClassPtr that point to linked lists
//Postconditions: inserts newNode at the front of head
void headInsert(ExamClassPtr& head, ExamClassPtr& newNode);

//Preconditions: head points to a linked list
//Postconditions: deletes the linked list that head points to
void deleteList(ExamClassPtr& head);

int main(void) {
	//declare vector of ExamStruct named exams
	ExamClassPtr head = NULL;
	float classAvg = 0.0;

	//read in scores from data.txt
	readData(head);
	classAvg = classAverage(head);
	printResults(head, classAvg);
	deleteList(head);

	return 0;
}

// function definitions:
void readData(ExamClassPtr &head) {
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
		headInsert(head, temp);
	}

	//check if file is empty
	if (head == NULL) {
		std::cout << "data.txt is empty, program quit\n";
		inFile.close();
		exit(EXIT_FAILURE);
	}

	inFile.close();
}

float classAverage(ExamClassPtr head) {
	ExamClassPtr temp = NULL;
	float avg = 0.0;
	int i = 0;

	//TODO: getting an infinite loop here
	temp = head;
	while (temp != NULL) {
		avg += temp->getExam1();
		avg += temp->getExam2();
		avg += temp->getExam3();
		temp = temp->getNext();
		++i;
	}

	temp = NULL;
	avg /= i * 3;
	return avg;
}

void printResults(ExamClassPtr head, float classAvg) {
	std::cout << std::fixed << std::setprecision(2) << "The class average of the exam averages was " << classAvg << std::endl;
	std::cout << std::left << std::setw(15) << "Name:" << "Exam avg:\n";
	std::cout << "-------------------------\n";
	for (ExamClassPtr itr = head; itr != NULL; itr = itr->getNext()) {
		std::cout << std::setw(15) << itr->getStudentName() << std::setw(10) << itr->getStudentAverage();
		if (itr->getStudentAverage() > classAvg)
			std::cout << "Above Average";
		std::cout << std::endl;
	}
}

void headInsert(ExamClassPtr& head, ExamClassPtr& newNode) {
	newNode->setNext(head);
	head = newNode;
	newNode = NULL;
}

void deleteList(ExamClassPtr &head) {
	while (head != NULL) {
		ExamClassPtr temp = head;
		temp = temp->getNext();
		delete head;
		head = temp;
	}
}