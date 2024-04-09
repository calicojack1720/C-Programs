/* Michael Astfalk
*  CS110 C++ Programming I Section 2
*  Project 3
*  Due: 15 November 2021
*  Calculate an algebraic equation with the given operation and numbers using switch statements
*/

#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	double num1, num2;	//numbers input by user
	char calcOperator;	//holds selected mathematical operator (+, -, *, /)
	double calcAnswer;	//the answer of the math statement dictated by the user

	

	for (int i = 0; i < 6; ++i)
	{
		

		//get user input for num1 and check to make sure input is a number
		cout << "\nEnter number 1: ";
		cin >> num1;
		

		//get user input for the operator
		cout << "\nEnter the math operator that you want to use: Addition ('+'), Subtraction ('-'), ";
		cout << "Multiplication ('*'), or Division ('/')\n";
		cin >> calcOperator;

		//get user input for num2 and check to make sure input is a number
		cout << "\nEnter number 2: ";
		cin >> num2;
		
		//perform the entered calculation using a swtich statement
		switch (calcOperator) {
		case '+':
			calcAnswer = num1 + num2;
			break;
		case '-':
			calcAnswer = num1 - num2;
			break;
		case '*':
			calcAnswer = num1 * num2;
			break;
		case '/':
			calcAnswer = num1 / num2;
			break;
		default:
			cout << "\n\nERROR 404: Operator not found! Expected '+', '-', '*', or '/'\n\n";
			--i;
		}
		
		//output answer if the user entered a valid operator
		if(calcOperator == '+' || calcOperator == '-' || calcOperator == '*' || calcOperator == '/')
			cout << endl << fixed << setprecision(1) << num1 << " " << calcOperator << " " << num2 << " = " << calcAnswer << endl << endl;
	}

	

	return 0;
}