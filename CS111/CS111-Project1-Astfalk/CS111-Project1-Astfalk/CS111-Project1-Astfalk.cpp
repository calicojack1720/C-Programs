/* Michael Astfalk
*  CS111 Section 1
*  Project 1
*  Due: 2 Feb. 2022
*  Objective: use a 2D array to simulate temperature profile in a container of water
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define NUM_ROWS 15
#define NUM_COLS 15

typedef float Matrix[NUM_ROWS][NUM_COLS];

//precondition: matrix is the 2D array, size is number of columns and rows
//postcondition: matrix is initialized to border temperature.
// Ask the user to supply a boundary temperature greater than 0
// All non­border elements are all set to zero.
void initializeSimulation(Matrix m, int size);			//initialize the matrix
void setBoundary(Matrix m, int size, float boundary);	//sets the cell values equal to the entered boundary value
void initCells(Matrix m, int size);						//sets all non-boundary elements to 0


//precondition: matrix is the 2D array, size is number of columns and rows,
// tolerance is the value that the largest change in any cell must be less than
//postcondition: matrix contains the simulation values after the simulation completes.
void simulate(Matrix m, int size, float tolerance);		//run simulation until cells values are within tolerance
float averageCell(Matrix m, int row, int col);			//set cell equal to the average of bordering cells
float averageMatrix(Matrix m, int size);				//average the entire matrix

//precondition: matrix is the 2D array, size is number of columns and rows
//postcondition: the contents of the matrix are output to the screen
// set precision to two and width to six
void printMatrix(Matrix m, int numRows, int numCols);	//print out the matrix


int main(void) {
	Matrix simulation;
	float tolerance = 0.01;

	initializeSimulation(simulation, NUM_ROWS);
	simulate(simulation, NUM_ROWS, tolerance);

	cout << "\nAveraged matrix with tolerance of 0.01 and 98% value of neighboring cells:" << endl;
	printMatrix(simulation, NUM_ROWS, NUM_COLS);

	return 0;
}

void initializeSimulation(Matrix m, int size) {
	float boundaryVal = 0.0;

	//get the boundary value from the user
	do {
		cout << "Enter a boundary value greater than 0: ";
		cin >> boundaryVal;

		if (boundaryVal <= 0)
			cout << "\nPlease enter a value greater than 0\n\n";
	} while (boundaryVal <= 0);
	
	setBoundary(m, size, boundaryVal);

	initCells(m, size);
}

void setBoundary(Matrix m, int size, float boundary) {
	//set values to the boundary value
	for (int row = 0; row < size; ++row) {
		for (int col = 0; col < size; ++col) {
			m[row][col] = boundary;
		}
	}
}

void initCells(Matrix m, int size) {
	//set non-boundary elements to 0
	for (int row = 1; row < size - 1; ++row) {
		for (int col = 1; col < size - 1; ++col) {
			m[row][col] = 0;
		}
	}
}



float averageCell(Matrix m, int row, int col) {
	//set cell equal to the average of bordering cells
	float avg = 0;

	avg = m[row][col - 1] + m[row][col + 1] + m[row - 1][col] + m[row + 1][col];
	avg *= .98;
	avg /= 4;

	return avg;
}

float averageMatrix(Matrix m, int size) {
	//average the entire matrix
	float delta = 0;

	for (int row = 1; row < size - 1; ++row) {
		for (int col = 1; col < size - 1; ++col) {
			float oldCellValue = m[row][col];
			m[row][col] = averageCell(m, row, col);
			delta = fabs(oldCellValue - m[row][col]);
		}
	}

	return delta;
}

void simulate(Matrix m, int size, float tolerance) {
	//run simulation until cells values are within tolerance
	float delta = FLT_MAX;

	for (int i = 1; delta > tolerance; ++i) {
		float newDelta = averageMatrix(m, size);
		if (delta > newDelta)
			delta = newDelta;
	}
}

void printMatrix(Matrix m, int numRows, int numCols) {
	//print out the matrix with precision set to 2 and width set to 6
	for (int row = 0; row < numRows; ++row) {
		for (int col = 0; col < numCols; ++col) {
			cout << setprecision(2) << setw(6);
			cout << m[row][col] << " ";
		}
		cout << endl;
	}
}