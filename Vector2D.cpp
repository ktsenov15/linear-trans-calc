// Implementation of class Vector2D

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "Vector2D.h"

using namespace std;

// Default constructor - a 0-vector
Vector2D::Vector2D() {

	dim = 2;

	elements[0] = 0;
	elements[1] = 0;
}

// Constructor with floating point elements as arguments
Vector2D::Vector2D(double a, double b) {

	dim = 2;

	elements[0] = a;
	elements[1] = b;
}

// Accessor for the elements of the vector
double& Vector2D::operator[] (unsigned int index) {

	double* element;

	// Check if index is valid; return 0 otherwise
	if (index >= dim) {
		
		throw invalid_argument("Invalid index!");
	}
	
	element = &elements[index];
	return *element;
}

double Vector2D::operator[] (unsigned int index) const {

	// Check if index is valid; return 0 otherwise
	if (index >= dim) {

		throw invalid_argument("Invalid index!");
	}

	return elements[index];
}

// Define addition of vectors
Vector2D Vector2D::operator+(const Vector2D& rhs) const {

	Vector2D result;

	for (int i = 0; i < 2; i++)
		result[i] = elements[i] + rhs.elements[i];

	return result;
}

// Define subtraction of vectors
Vector2D Vector2D::operator-(const Vector2D& rhs) const {

	Vector2D result;

	for (int i = 0; i < 2; i++)
		result[i] = elements[i] - rhs.elements[i];

	return result;
}

// Define dot product of vectors
double Vector2D::dot(const Vector2D& rhs) const {

	double result = 0;

	for (int i = 0; i < 2; i++)
		result += elements[i] * rhs.elements[i];

	return result;
}

// Define cross product of 2x2 vectors; returns a number - the determinant of the resulting matrix
double Vector2D::cross(const Vector2D& rhs) const {

	return elements[0] * rhs.elements[1] - elements[1] * rhs.elements[0];
}

void Vector2D::display() const {

	for (int i = 0; i < 2; i++)
		cout << right << setw(4) << elements[i] << endl;
}