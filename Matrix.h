// Interface of abstract class Matrix
#include <string>
#include <vector>

#include "Vector.h"

using namespace std;

#pragma once

class Matrix {

public:
	virtual ~Matrix();

	int getDim() const;		// Method to get the dimension of a matrix

	virtual double operator() (unsigned int, unsigned int) const = 0;

	virtual Vector& transform(const Vector&) = 0;	// Polymorphic function to act with a matrix on a vector

	virtual void setArg(double) = 0;
	virtual void setArg(vector<double>) = 0;
	virtual string getName() const = 0;					// Polymorphic function to get the name of a transformation matrix

protected:
	int dim;				// Class attribute - dimension of the matrix
};