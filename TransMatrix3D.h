// Interface of class TransMatrix3D - this class instantiates 4x4 linear transformations to be applied on 3-dimensional vectors
/// Transformation matrices for 3-dimensional vectors are usually either 3x3 or 4x4 matrices. However, they can all be applied as 4x4
/// matrices on 2-dimensional vectors by converting the vectors' Cartesian coordinates (a, b, c) into homogeneous coordinates (a, b, c, 1).
/// 3x3 matrices can be converted to 4x4 ones by setting appropriate default values for the fourth row and column.
/// Transformation matrices also have names, e.g. Rotation, Scaling, etc.
#include<queue>

#include "Matrix4D.h"
#include "Vector3D.h"

#pragma once

class TransMatrix3D : public Matrix4D {

public:
	TransMatrix3D(string, int, queue<string>);

	void setArg(double);
	void setArg(vector<double>);

	string getName() const;					// Method to get the name of the transformation

	double operator() (unsigned int, unsigned int) const;

	Vector4D& transform(const Vector&);		// Function that acts on a vector with a transformation
											// matrix; result is in homogeneous coordinates

	Vector3D static localize(Vector&);		// Method to convert result back to Cartesian coordinates

private:
	string name;			// Class attribute - name of linear transformation
	string pattern[3][3];	// Class attribute - transformation pattern
	int pat_dim;			// Class attribute - dimension of the transformation pattern
};
