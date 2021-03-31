// Implementation of class TransMatrix2D

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

#include "TransMatrix2D.h"

// Constructor with a transformation pattern
TransMatrix2D::TransMatrix2D(string name, int dim, queue<string> input) {

	Matrix3D();									// Create an identity matrix as default

	this->name = name;
	this->pat_dim = dim;

	for (int i = 0; i < pat_dim; i++)
		for (int j = 0; j < pat_dim; j++) {
			
			pattern[i][j] = input.front();
			input.pop();
		}
}

// Argument modifier - coefficients
void TransMatrix2D::setArg(vector<double> coef) {

	for (int i = 0; i < pat_dim; i++)
		for (int j = 0; j < pat_dim; j++) {

			if (pattern[i][j] == "x")
				elements[i][j] = coef[0];
			else if (pattern[i][j] == "y")
				elements[i][j] = coef[1];
		}
}

// Argument modifier - angle
void TransMatrix2D::setArg(double angle) {

	int sign;
	string temp;

	for (int i = 0; i < pat_dim; i++)
		for (int j = 0; j < pat_dim; j++) {

			temp = pattern[i][j];

			if (temp.at(0) == '-') {
				
				sign = -1;
				temp.replace(0, 1, "");
			}
			else
				sign = 1;

			if (temp == "sin(x)")
				elements[i][j] = sign * sin(angle / 180 * M_PI);
			else if (temp == "cos(x)")
				elements[i][j] = sign * cos(angle / 180 * M_PI);
		}
}

// Define transformation name accessor
string TransMatrix2D::getName() const {

	return name;
}

double TransMatrix2D::operator() (unsigned int row, unsigned int col) const {

	// Check if index is valid; return 0 otherwise
	if (row >= dim || col >= dim) {

		throw invalid_argument("Invalid index!");
	}

	return elements[row][col];
}

// Define linear transformation function
Vector3D& TransMatrix2D::transform(const Vector& vec) {

	Vector3D* result = new Vector3D();
	
	// Check if the vector is in the right dimension; return a 0-vector otherwise
	if (vec.getDim() != 2) {
		cerr << "Invalid operation! Vector must be 2-dimensional!" << endl;
		return *result;
	}

	Vector3D hom_vec(vec[0], vec[1], 1);		// Get homogeneous coordinates

	Matrix3D matrix(elements);					// Create a normal 3x3 matrix

	*result = matrix.transform(hom_vec);			// Apply vector-matrix transformation

	return *result;
}

// Define vector coordinate conversion function
Vector2D TransMatrix2D::localize(Vector& vec) {

	return Vector2D(vec[0] / vec[2], vec[1] / vec[2]);
}