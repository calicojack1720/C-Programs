#include "ExamClass.h"

//ExamClass member functions:
//constructors:
ExamClass::ExamClass() {
	studentName = "NA";
	exam1Score = 0.0;
	exam2Score = 0.0;
	exam3Score = 0.0;
	studentAverage = 0.0;
}

ExamClass::ExamClass(float e1Score, float e2Score, float e3Score, std::string name) {
	exam1Score = e1Score;
	exam2Score = e2Score;
	exam3Score = e3Score;
	studentName = name;
}

//setters:
void ExamClass::setStudentName(std::string name) { studentName = name; }
void ExamClass::setExam1(float e1Score) { exam1Score = e1Score; }
void ExamClass::setExam2(float e2Score) { exam2Score = e2Score; }
void ExamClass::setExam3(float e3Score) { exam3Score = e3Score; }

//getters:
std::string ExamClass::getStudentName() { return studentName; }
float ExamClass::getExam1() { return exam1Score; }
float ExamClass::getExam2() { return exam2Score; }
float ExamClass::getExam3() { return exam3Score; }
float ExamClass::getStudentAverage() { return studentAverage; }

//helper function:
void ExamClass::computeStudentAverage() {	//average the student's exam scores
	studentAverage = (exam1Score + exam2Score + exam3Score) / 3;
}