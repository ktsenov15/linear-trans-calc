// Interface of class Vector2D - this class instantiates 2-dimensional vectors

#include "Vector.h"

#pragma once

class Vector2D : public Vector {

public:
	Vector2D();
	Vector2D(double, double);

	double& operator[] (unsigned int);	// Operator to access an element of a vector; inherited from class Vector
	double operator[] (unsigned int) const;

	// Basic arithmetic operations with vectors
	Vector2D operator+(const Vector2D&) const;
	Vector2D operator-(const Vector2D&) const;
	
	// Dot and cross product of vectors
	double dot(const Vector2D&) const;
	double cross(const Vector2D&) const;

	// Display vector
	void display() const;

private:
	double elements[2];		// Class attribute - an array containing the elements of the vector
};