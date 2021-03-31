// Implementation of class Prompt

#include <iostream>

#include "Prompt.h"

using namespace std;

void Prompt::SelectOperationType() {
	
	cout << "Select the type of operation you would like to perform:" << endl;
	cout << "-------------------------------------------------------" << endl << endl;
	
	cout << "	1) Matrix arithmetic operation" << endl;
	cout << "	2) Vector arithmetic operation" << endl;
	cout << "	3) Vector transformation" << endl << endl;
	
	cout << "To exit, please enter X" << endl << endl;
}

void Prompt::GetValidInput(char& input, int options) {

	int n;
	
	cout << "Enter a number: ";
	cin >> input;

	if (isdigit(input))
		n = input - '1';
	else
		n = options;

	while ((n >= options || n < 0) && input != 'X' && input != 'R') {

		cout << "Please, enter valid input: ";
		cin >> input;

		if (isdigit(input))
			n = input - '1';
		else
			n = options;
	}
}

void Prompt::GetValidDimension(int& dim) {

	cin >> dim;

	while (dim != 2 && dim != 3) {

		cout << "Dimension must either be 2 or 3. Please, enter another value: ";
		cin >> dim;
	}
}

void Prompt::SelectMatrixOperation() {

	cout << "Select operation:" << endl;
	cout << "--------------------" << endl << endl;
	
	cout << "	1) + (addition)" << endl;
	cout << "	2) - (subtraction)" << endl;
	cout << "	3) * (multiplication)" << endl << endl;

	cout << "To reset, please enter R" << endl << endl;
}

void Prompt::SelectVectorOperation() {

	cout << "Select operation:" << endl;
	cout << "--------------------" << endl << endl;

	cout << "	1) + (addition)" << endl;
	cout << "	2) - (subtraction)" << endl;
	cout << "	3) . (dot product)" << endl;
	cout << "	4) x (cross product)" << endl << endl;

	cout << "To reset, please enter R" << endl << endl;
}

void Prompt::SelectTransformationType() {

	cout << "Select operation:" << endl;
	cout << "-----------------" << endl << endl;

	cout << "	1) Vector-matrix multiplication" << endl;
	cout << "	2) Apply linear transformation" << endl << endl;

	cout << "To reset, please enter R" << endl << endl;
}