// Interface of class Matrix4D - this class instantiates 4x4 matrices
/// This class is only meant for creating transformation matrices for 3-dimensional vectors, therefore no arithmetic 
/// functionality is necessary.

#include "Matrix.h"
#include "Vector4D.h"

#pragma once

class Matrix4D : public Matrix {

public:
	Matrix4D();
	Matrix4D(double[4][4]);

	virtual ~Matrix4D();

	double operator() (unsigned int, unsigned int) const;

	virtual Vector4D& transform(const Vector&);		// Matrix-vector multiplication - inherited from class Matrix

	// The following functions have a default implementation and are necessary for the transformation matrix class
	virtual string getName() const;
	virtual void setArg(double);
	virtual void setArg(vector<double>);

protected:
	double elements[4][4];		// Class attribute - an array containing the elements of the matrix
};
