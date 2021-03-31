// Interface of class Matrix2D - this class instantiates 2x2 matrices

#include "Matrix.h"
#include "Vector2D.h"

#pragma once

class Matrix2D : public Matrix {

public:
	Matrix2D();
	Matrix2D(double[2][2]);

	virtual ~Matrix2D();

	// Basic arithmetic operations with matrices
	Matrix2D operator+(const Matrix2D&) const;
	Matrix2D operator-(const Matrix2D&) const;
	Matrix2D operator*(const Matrix2D&) const;

	void display() const;

	double operator() (unsigned int, unsigned int) const;

	virtual Vector2D& transform(const Vector&);			// Matrix-vector multiplication - inherited from class Matrix

	// The following functions have a default implementation and are necessary for the transformation matrix class
	virtual string getName() const;
	virtual void setArg(double);
	virtual void setArg(vector<double>);

protected:
	double elements[2][2];		// Class attribute - an array containing the elements of the matrix
};