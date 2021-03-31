// Declaration of class KMP
// Objects of this class are initialized with a string and a pattern to be found in the string
// Its main method performs a Knuth-Morris-Pratt pattern matching algorithm

#include <string>

using namespace std;

#pragma once

class KMP
{
public:
	KMP(string, string);

	void position(int p);
	bool operator++();						// KMP pattern matching operator

private:
	string text;
	int pos;
	unsigned int patlen;
	string pattern;
	int* prefix;

};