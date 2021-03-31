// Interface of class Matrix3D - this class instantiates 3x3 matrices

#include "Matrix.h"
#include "Vector3D.h"

#pragma once

class Matrix3D : public Matrix {

public:
	Matrix3D();
	Matrix3D(double[3][3]);

	virtual ~Matrix3D();

	// Basic arithmetic operations with matrices
	Matrix3D operator+(const Matrix3D&) const;
	Matrix3D operator-(const Matrix3D&) const;
	Matrix3D operator*(const Matrix3D&) const;

	void display() const;

	double operator() (unsigned int, unsigned int) const;

	virtual Vector3D& transform(const Vector&);			// Matrix-vector multiplication - inherited from class Matrix

	// The following functions have a default implementation and are necessary for the transformation matrix class
	virtual string getName() const;
	virtual void setArg(double);
	virtual void setArg(vector<double>);

protected:
	double elements[3][3];		// Class attribute - an array containing the elements of the matrix
};