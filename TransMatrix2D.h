// Interface of class TransMatrix2D - this class instantiates 3x3 linear transformations to be applied on 2-dimensional vectors
/// Transformation matrices for 2-dimensional vectors are usually either 2x2 or 3x3 matrices. However, they can all be applied as 3x3
/// matrices on 2-dimensional vectors by converting the vectors' Cartesian coordinates (a, b) into homogeneous coordinates (a, b, 1).
/// 2x2 matrices can be converted to 3x3 ones by setting appropriate default values for the third row and column.
/// Transformation matrices also have names, e.g. Rotation, Scaling, etc.
#include <queue>

#include "Matrix3D.h"
#include "Vector2D.h"

#pragma once

class TransMatrix2D : public Matrix3D {

public:
	TransMatrix2D(string, int, queue<string>);

	void setArg(double);
	void setArg(vector<double>);

	string getName() const;					// Method to get the name of the transformation

	double operator() (unsigned int, unsigned int) const;
	
	Vector3D& transform(const Vector&);		// Function that acts on a vector with a transformation
											// matrix; result is in homogeneous coordinates

	Vector2D static localize(Vector&);		// Method to convert result back to Cartesian coordinates

private:
	string name;			// Class attribute - name of linear transformation
	string pattern[3][3];	// Class attribute - transformation pattern
	int pat_dim;			// Class attribute - dimension of the transformation pattern
};