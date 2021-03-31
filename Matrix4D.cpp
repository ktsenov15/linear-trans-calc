// Implementation of class Matrix4D

#include <iostream>

#include "Matrix4D.h"

// Default constructor - an identity matrix
Matrix4D::Matrix4D() {

	dim = 4;

	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++) {
			if (i == j)
				elements[i][j] = 1;
			else
				elements[i][j] = 0;
		}
}

// Constructor with an array argument
Matrix4D::Matrix4D(double elements[4][4]) {

	dim = 4;

	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			this->elements[i][j] = elements[i][j];
}

// Defintion of virtual destructor
Matrix4D::~Matrix4D() {}

// Define matrix-vector multiplication
Vector4D& Matrix4D::transform(const Vector& vec) {

	Vector4D* result = new Vector4D();

	// Check if the vector is in the right dimension; return a 0-vector otherwise
	if (dim != vec.getDim()) {
		cerr << "Invalid operation! Dimensions must match!" << endl;
		return *result;
	}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			result->operator[](i) += round(elements[i][j] * vec[j] * 1000) / 1000;

	return *result;
}

double Matrix4D::operator() (unsigned int row, unsigned int col) const {

	// Check if index is valid; return 0 otherwise
	if (row >= dim || col >= dim) {

		throw invalid_argument("Invalid index!");
	}

	return elements[row][col];
}

// Return a default value for name accessor
string Matrix4D::getName() const {

	return "4x4 Matrix";
}

// Undertake no action for argument modifiers
void Matrix4D::setArg(double) {}
void Matrix4D::setArg(vector<double>) {}