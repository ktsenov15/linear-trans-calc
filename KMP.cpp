// Definition of class KMP

#include "KMP.h"

KMP::KMP(string p, string t) :text(t), pos(0), pattern(p)
{
	patlen = p.length();
	prefix = new int[patlen];
	prefix[0] = 0;

	// Fill in the prefix table
	for (int i = 1; i < patlen; i++) {
		int k = prefix[i - 1];

		while ((pattern[i] != pattern[k]) && (k != 0))
			k = prefix[k - 1];

		if (pattern[i] == pattern[k])
			prefix[i] = k + 1;
		else
			prefix[i] = 0;
	}
}

void KMP::position(int p) {						// Method to modify current position; used in KMP algorithm

	pos = p;
}

bool KMP::operator++()							// KMP pattern matching algorithm
{												// Returns true for a found match
	int maxpos = text.length();
	int curpos = pos + 1;
	int patpos = 0;							    // Position in the pattern

	for (; curpos < maxpos; curpos++) {
		while ((patpos > 0) && (pattern[patpos] != text[curpos]))
			patpos = prefix[patpos - 1];

		if (pattern[patpos] == text[curpos]) {
			patpos++;
			if (patpos == patlen) {			    // A match is found
				position(1 + curpos - patlen);
				return 1;
			}
		}
	}

	position(-1);
	return 0;
}