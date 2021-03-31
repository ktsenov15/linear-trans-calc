// Implementation of class Vector4D

#include <iostream>
#include <stdexcept>

#include "Vector4D.h"

using namespace std;

// Default constructor - a 0-vector
Vector4D::Vector4D() {

	dim = 4;

	elements[0] = 0;
	elements[1] = 0;
	elements[2] = 0;
	elements[3] = 0;
}

// Constructor with floating point elements as arguments
Vector4D::Vector4D(double a, double b, double c, double d) {

	dim = 4;

	elements[0] = a;
	elements[1] = b;
	elements[2] = c;
	elements[3] = d;
}

// Accessor for the elements of the vector
double& Vector4D::operator[] (unsigned int index) {

	double* element;

	//// Check if index is valid; return 0 otherwise
	//if (index >= dim) {

	//	throw invalid_argument("Invalid index!");
	//}

	element = &elements[index];
	return *element;
}

double Vector4D::operator[] (unsigned int index) const {

	// Check if index is valid; return 0 otherwise
	if (index >= dim) {

		throw invalid_argument("Invalid index!");
	}

	return elements[index];
}
