// Implementation of class Vector3D

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "Vector3D.h"

using namespace std;

// Default constructor - a 0-vector
Vector3D::Vector3D() {

	dim = 3;

	elements[0] = 0;
	elements[1] = 0;
	elements[2] = 0;
}

// Constructor with floating point elements as arguments
Vector3D::Vector3D(double a, double b, double c) {

	dim = 3;

	elements[0] = a;
	elements[1] = b;
	elements[2] = c;
}

// Accessor for the elements of the vector
double& Vector3D::operator[] (unsigned int index) {

	double* element;

	// Check if index is valid; return 0 otherwise
	if (index >= dim) {

		throw invalid_argument("Invalid index!");
	}

	element = &elements[index];
	return *element;
}

double Vector3D::operator[] (unsigned int index) const {

	// Check if index is valid; return 0 otherwise
	if (index >= dim) {

		throw invalid_argument("Invalid index!");
	}

	return elements[index];
}


// Define addition of vectors
Vector3D Vector3D::operator+(const Vector3D& rhs) const {

	Vector3D result;

	for (int i = 0; i < 3; i++)
		result[i] = elements[i] + rhs.elements[i];

	return result;
}

// Define subtraction of vectors
Vector3D Vector3D::operator-(const Vector3D& rhs) const {

	Vector3D result;

	for (int i = 0; i < 3; i++)
		result[i] = elements[i] - rhs.elements[i];

	return result;
}

// Define dot product of vectors
double Vector3D::dot(const Vector3D& rhs) const {

	double result = 0;

	for (int i = 0; i < 3; i++)
		result += elements[i] * rhs.elements[i];

	return result;
}

// Define cross product of 3x3 vectors; returns a vector (perpendicular to the given two vectors)
Vector3D Vector3D::cross(const Vector3D& rhs) const {

	Vector3D result;

	for (int i = 0; i < 3; i++)
		result[i] = elements[(i + 1) % 3] * rhs.elements[(i + 2) % 3] - elements[(i + 2) % 3] * rhs.elements[(i + 1) % 3];

	return result;
}

void Vector3D::display() const {

	for (int i = 0; i < 3; i++)
		cout << right << setw(4) << elements[i] << endl;
}