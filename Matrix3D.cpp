// Implementation of class Matrix3D

#include <iostream>
#include <iomanip>

#include "Matrix3D.h"

// Default constructor - an identity matrix
Matrix3D::Matrix3D() {

	dim = 3;

	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++) {
			if (i == j)
				elements[i][j] = 1;
			else
				elements[i][j] = 0;
		}
}

// Constructor with an array argument
Matrix3D::Matrix3D(double elements[3][3]) {

	dim = 3;

	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			this->elements[i][j] = elements[i][j];
}

// Defintion of virtual destructor
Matrix3D::~Matrix3D() {}

// Define addition of matrices
Matrix3D Matrix3D::operator+(const Matrix3D& rhs) const {

	double result[3][3];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			result[i][j] = elements[i][j] + rhs.elements[i][j];

	return Matrix3D(result);
}

// Define subtraction of matrices
Matrix3D Matrix3D::operator-(const Matrix3D& rhs) const {

	double result[3][3];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			result[i][j] = elements[i][j] - rhs.elements[i][j];

	return Matrix3D(result);
}

// Define multiplication of matrices
Matrix3D Matrix3D::operator*(const Matrix3D& rhs) const {

	double result[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				result[i][j] += elements[i][k] * rhs.elements[k][j];

	return Matrix3D(result);
}

void Matrix3D::display() const {

	for (int i = 0; i < 3; i++) {
		
		for (int j = 0; j < 3; j++)
			cout << right << setw(4) << elements[i][j] << ' ';

		cout << endl;
	}
}

double Matrix3D::operator() (unsigned int row, unsigned int col) const {

	// Check if index is valid; return 0 otherwise
	if (row >= dim || col >= dim) {

		throw invalid_argument("Invalid index!");
	}

	return elements[row][col];
}

// Define matrix-vector multiplication
Vector3D& Matrix3D::transform(const Vector& vec) {

	Vector3D* result = new Vector3D();

	// Check if the vector is in the right dimension; return a 0-vector otherwise
	if (dim != vec.getDim()) {
		cerr << "Invalid operation! Dimensions must match!" << endl;
		return *result;
	}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			result->operator[](i) += round(elements[i][j] * vec[j] * 1000) / 1000;

	return *result;
}

// Return a default value for name accessor
string Matrix3D::getName() const {

	return "3x3 Matrix";
}

// Undertake no action for argument modifiers
void Matrix3D::setArg(double) {}
void Matrix3D::setArg(vector<double>) {}