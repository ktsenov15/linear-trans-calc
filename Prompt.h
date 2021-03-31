// Interface of class Prompt
/// Class Prompt is a class of static void functions whose purpose is to separate the prompts and repetative operations in a separate file
/// for better clarity of the code in the driver program

#pragma once

class Prompt {

public:

	static void SelectOperationType();
	static void GetValidInput(char&, int);
	static void GetValidDimension(int&);
	static void SelectMatrixOperation();
	static void SelectVectorOperation();
	static void SelectTransformationType();
};