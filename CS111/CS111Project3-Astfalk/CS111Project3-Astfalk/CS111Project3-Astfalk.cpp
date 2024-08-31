/*CS111Project3-Astfalk
* Create a project that uses a vector of structs to store student exam data and calculate
* summary statistics.
* Michael Astfalk
* Created: 3/10/2022
* Updated: 3/18/2022
*/

#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>

//Struct definition
struct ExamStruct {
	std::string studentName;
	float exam1Score;
	float exam2Score;
	float exam3Score;
	float studentAverage;

	//constructors:
	ExamStruct();
	ExamStruct(float e1Score, float e2Score, float e3Score, std::string name);

	//helper functions:
	//preconditions: vector of type ExamStruct has been declared and has exam scores from user input
	//postconditions: calculates and sets the studentAverage member variable
	void computeStudentAverage();

	//preconditions: exams is a vector of ExamStruct that has had data read in from a file
	//postconditions: returns a boolean value if the first struct of ExamStruct vector is empty
	bool checkEmpty();

};

//precondtions: exams is an EMPTY vector of ExamStruct
//postconditions: exams is filled with ExamStructs created by info in the data.txt file
void readData(std::vector<ExamStruct> &exams);

//precondition: exams holds list of student and their exam scores
//postcondition: returns a float value of the average of all student exam scores
float classAverage(std::vector <ExamStruct> exams);

//Preconditions: exams holds list of students and their exam scores; classAverage is the average of all students'
//exam scores
//Postconditions: print studentName studentAverage "Above Average" if the student's average is above the
//class average
void printResults(std::vector<ExamStruct> exams, float classAverage);

int main(void) {
	//declare vector of ExamStruct named exams
	std::vector<ExamStruct> exams;
	float classAvg = 0.0;

	//read in scores from data.txt
	readData(exams);
	classAvg = classAverage(exams);
	printResults(exams, classAvg);

	return 0;
}

//ExamStruct member functions:
//constructors:
ExamStruct::ExamStruct() {
	studentName = "NA";
	exam1Score = 0.0;
	exam2Score = 0.0;
	exam3Score = 0.0;
	studentAverage = 0.0;
}

ExamStruct::ExamStruct(float e1Score, float e2Score, float e3Score, std::string name) {
	exam1Score = e1Score;
	exam2Score = e2Score;
	exam3Score = e3Score;
	studentName = name;
}

//helper function:
void ExamStruct::computeStudentAverage() {	//average the student's exam scores
	studentAverage = (exam1Score + exam2Score + exam3Score) / 3;
}

bool ExamStruct::checkEmpty() {
	if (studentName == "NA")
		return true;

	return false;
}

//functions:
void readData(std::vector<ExamStruct>& exams) {
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
	
	while(inFile >> name >> e1Score >> e2Score >> e3Score) {
		//read in from data.txt and set values using constructor
		exams.push_back(ExamStruct(e1Score, e2Score, e3Score, name));

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



float classAverage(std::vector<ExamStruct> exams) {
	float avg = 0.0;
	for (int i = 0; i < exams.size(); ++i) {
		avg += exams.at(i).exam1Score;
		avg += exams.at(i).exam2Score;
		avg += exams.at(i).exam3Score;
	}

	avg /= exams.size() * 3;
	return avg;
}

void printResults(std::vector<ExamStruct> exams, float classAvg) {
	std::cout << std::fixed << std::setprecision(2) << "The class average of the exam averages was " << classAvg << std::endl;
	std::cout << std::left << std::setw(15) << "Name:" << "Exam avg:\n";
	std::cout << "-------------------------\n";
	for (int i = 0; i < exams.size(); ++i) {
		std::cout << std::setw(15) << exams.at(i).studentName << std::setw(10) << exams.at(i).studentAverage;
		if (exams.at(i).studentAverage > classAvg)
			std::cout << "Above Average";
		std::cout << std::endl;
	}
}