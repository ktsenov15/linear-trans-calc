// Interface of class Vector3D - this class instantiates 3-dimensional vectors

#include "Vector.h"

#pragma once

class Vector3D : public Vector {

public:
	Vector3D();
	Vector3D(double, double, double);

	double& operator[] (unsigned int);	// Operator to access an element of a vector; inherited from class Vector
	double operator[] (unsigned int) const;

	// Basic arithmetic operations with vectors
	Vector3D operator+(const Vector3D&) const;
	Vector3D operator-(const Vector3D&) const;

	// Dot and cross product of vectors
	double dot(const Vector3D&) const;
	Vector3D cross(const Vector3D&) const;

	// Display vector
	void display() const;

private:
	double elements[3];		// Class attribute - an array containing the elements of the vector
};