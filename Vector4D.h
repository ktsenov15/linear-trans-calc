// Interface of class Vector4D - this class instantiates 4-dimensional vectors
/// 4-dimensional vectors will only be used in the implementation of the linear transformation function, therefore no arithmetic
/// functionality is necessary

#include "Vector.h"

#pragma once

class Vector4D : public Vector {

public:
	Vector4D();
	Vector4D(double, double, double, double);

	double& operator[] (unsigned int);	// Operator to access an element of a vector; inherited from class Vector
	double operator[] (unsigned int) const;

private:
	double elements[4];		// Class attribute - an array containing the elements of the vector
};
