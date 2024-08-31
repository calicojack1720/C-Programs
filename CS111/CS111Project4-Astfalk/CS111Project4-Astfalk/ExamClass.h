#pragma once

#include<iostream>

class ExamClass
{
private:
	std::string studentName;
	float exam1Score;
	float exam2Score;
	float exam3Score;
	float studentAverage;

public:
	//constructors:
	ExamClass();
	ExamClass(float e1Score, float e2Score, float e3Score, std::string name);

	//setters:
	void setStudentName(std::string name);
	void setExam1(float e1Score);
	void setExam2(float e2Score);
	void setExam3(float e3Score);

	//getters:
	std::string getStudentName();
	float getExam1();
	float getExam2();
	float getExam3();
	float getStudentAverage();

	//helper functions:
	//preconditions: vector of type ExamStruct has been declared and has exam scores from user input
	//postconditions: calculates and sets the studentAverage member variable
	void computeStudentAverage();
};

