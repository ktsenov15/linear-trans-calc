// Interface of abstract class Vector

#pragma once

class Vector {

public:
	virtual ~Vector();

	int getDim() const;			// Method to get the dimension of a vector

	virtual double& operator[] (unsigned int) = 0;		// Polymorphic operator to access any element of a vector
	virtual double operator[] (unsigned int) const = 0;

protected:
	int dim;		// Class attribute - dimension of the vector
};