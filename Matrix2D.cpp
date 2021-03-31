// Implementation of class Matrix2D

#include <iostream>
#include <iomanip>

#include "Matrix2D.h"

// Default constructor - an identity matrix
Matrix2D::Matrix2D() {

	dim = 2;

	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++) {
			if (i == j)
				elements[i][j] = 1;
			else
				elements[i][j] = 0;
		}
}

// Constructor with an array argument
Matrix2D::Matrix2D(double elements[2][2]) {

	dim = 2;

	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			this->elements[i][j] = elements[i][j];
}

// Defintion of virtual destructor
Matrix2D::~Matrix2D() {}

// Define addition of matrices
Matrix2D Matrix2D::operator+(const Matrix2D& rhs) const {

	double result[2][2];
	
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			result[i][j] = elements[i][j] + rhs.elements[i][j];

	return Matrix2D(result);
}

// Define subtraction of matrices
Matrix2D Matrix2D::operator-(const Matrix2D& rhs) const {

	double result[2][2];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			result[i][j] = elements[i][j] - rhs.elements[i][j];

	return Matrix2D(result);
}

// Define multiplication of matrices
Matrix2D Matrix2D::operator*(const Matrix2D& rhs) const {

	double result[2][2] = { {0, 0}, {0, 0}};

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				result[i][j] += elements[i][k] * rhs.elements[k][j];

	return Matrix2D(result);
}

void Matrix2D::display() const {

	for (int i = 0; i < 2; i++) {
		
		for (int j = 0; j < 2; j++)
			cout << right << setw(4) << elements[i][j] << ' ';

		cout << endl;
	}
}

double Matrix2D::operator() (unsigned int row, unsigned int col) const {

	// Check if index is valid; return 0 otherwise
	if (row >= dim || col >= dim) {

		throw invalid_argument("Invalid index!");
	}

	return elements[row][col];
}

// Define matrix-vector multiplication
Vector2D& Matrix2D::transform(const Vector& vec) {

	Vector2D* result = new Vector2D();

	// Check if the vector is in the right dimension; return a 0-vector otherwise
	if (dim != vec.getDim()) {

		cerr << "Invalid operation! Dimensions must match!" << endl;
		return *result;
	}
	
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			result->operator[](i) += round(elements[i][j] * vec[j] * 1000) / 1000;

	return *result;
}

// Return a default value for name accessor
string Matrix2D::getName() const {

	return "2x2 Matrix";
}

// Undertake no action for argument modifiers
void Matrix2D::setArg(double) {}
void Matrix2D::setArg(vector<double>) {}