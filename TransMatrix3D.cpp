// Implementation of class TransMatrix3D

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

#include "TransMatrix3D.h"

using namespace std;

// Constructor with a transformation pattern
TransMatrix3D::TransMatrix3D(string name, int dim, queue<string> input) {

	Matrix4D();									// Create an identity matrix as default

	this->name = name;
	this->pat_dim = dim;

	for (int i = 0; i < pat_dim; i++)
		for (int j = 0; j < pat_dim; j++) {

			pattern[i][j] = input.front();
			input.pop();
		}
}

// Argument modifier - coefficients
void TransMatrix3D::setArg(vector<double> coef) {

	for (int i = 0; i < pat_dim; i++)
		for (int j = 0; j < pat_dim; j++) {

			if (pattern[i][j] == "x")
				elements[i][j] = coef[0];
			else if (pattern[i][j] == "y")
				elements[i][j] = coef[1];
			else if (pattern[i][j] == "z")
				elements[i][j] = coef[2];
		}
}

// Argument modifier - angle
void TransMatrix3D::setArg(double angle) {

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
				elements[i][j] = sign * sin(angle * M_PI / 180);
			else if (temp == "cos(x)")
				elements[i][j] = sign * cos(angle * M_PI / 180);
		}
}

// Define transformation name accessor
string TransMatrix3D::getName() const {

	return name;
}

double TransMatrix3D::operator() (unsigned int row, unsigned int col) const {

	// Check if index is valid; return 0 otherwise
	if (row >= dim || col >= dim) {

		throw invalid_argument("Invalid index!");
	}

	return elements[row][col];
}

// Define linear transformation function
Vector4D& TransMatrix3D::transform(const Vector& vec) {

	Vector4D* result = new Vector4D();

	// Check if the vector is in the right dimension; return a 0-vector otherwise
	if (vec.getDim() != 3) {
		cerr << "Invalid operation! Vector must be 3-dimensional!" << endl;
		return *result;
	}

	Vector4D hom_vec(vec[0], vec[1], vec[2], 1);		// Get homogeneous coordinates

	Matrix4D matrix(elements);							// Create a normal 3x3 matrix

	*result = matrix.transform(hom_vec);					// Apply vector-matrix transformation

	return *result;
}

// Define vector coordinate conversion function
Vector3D TransMatrix3D::localize(Vector& vec) {

	return Vector3D(vec[0] / vec[3], vec[1] / vec[3], vec[2] / vec[3]);
}