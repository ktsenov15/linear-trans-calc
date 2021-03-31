// The following program performs various vector-matrix calculations for the user. It first initializes a collection of 2D and 3D
// transformation matrices using as input a text file. Then, it prompts the user for desired operations, vectors and matrices to be
// involved in the calculations, etc. and outputs the results. The transformation matrix collection comes to use if the user would like 
// to apply a linear transformation to a vector. A menu of options is then displayed containing different transformations according to the
// dimension of the vector. A Knuth-Morris-Pratt pattern matching algorithm is implemented on the transformation names in order to decide 
// what type of argument should be provided by the user (an angle degree value or a set of coefficients). The program executes as long as
// the user wants it to.

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <stdlib.h> 

#include "Matrix2D.h"
#include "TransMatrix2D.h"
#include "TransMatrix3D.h"
#include "Prompt.h"
#include "KMP.h"

using namespace std;

int main(void) {

	// Get transformation matrices as input from text file
	ifstream ins;
	ins.open("TransMatrixInput.txt");

	// Check whether the file was found
	if (ins.fail()) {
		cout << "Error opening file!" << endl;
		return -1;
	}

	int pat_dim;
	string _dim, name, element;
	queue<string> pattern;

	// Create a collection of pointers to both 2D and 3D transformation matrices
	vector<Matrix*> transformations;

	// Initialize transformations and push them into the vector
	while (!ins.eof()) {

		ins >> _dim >> pat_dim;
		ins.ignore(10, '\n');
		getline(ins, name);

		for (int i = 0; i < pow(pat_dim, 2); i++) {

			ins >> element;
			pattern.push(element);
		}

		if (_dim == "2D")
			transformations.push_back(new TransMatrix2D(name, pat_dim, pattern));
		else
			transformations.push_back(new TransMatrix3D(name, pat_dim, pattern));

		while (!pattern.empty())
			pattern.pop();
	}

	ins.close();

	char ch = '\n';
	int n;

	while(ch != 'X') {

		system("CLS");

		cin >> skipws;

		// Prompt user to select type of operation
		Prompt::SelectOperationType();
		Prompt::GetValidInput(ch, 3);

		if (ch == 'X')
			continue;

		system("CLS");

		switch (ch) {

		// Matrix operations
		case '1':
			cout << "Enter matrix dimension: ";
			Prompt::GetValidDimension(n);

			double matrix2d_1[2][2], matrix2d_2[2][2],
				matrix3d_1[3][3], matrix3d_2[3][3];

			// Read matrices from input
			cout << "First matrix:" << endl;
			if (n == 2) {

				for (int i = 0; i < 2; i++)
					for (int j = 0; j < 2; j++)
						cin >> matrix2d_1[i][j];

				cout << "Second matrix:" << endl;
				for (int i = 0; i < 2; i++)
					for (int j = 0; j < 2; j++)
						cin >> matrix2d_2[i][j];
			}
			else {

				for (int i = 0; i < 3; i++)
					for (int j = 0; j < 3; j++)
						cin >> matrix3d_1[i][j];

				cout << "Second matrix:" << endl;
				for (int i = 0; i < 3; i++)
					for (int j = 0; j < 3; j++)
						cin >> matrix3d_2[i][j];
			}

			cout << endl;

			// Prompt user to select operation
			Prompt::SelectMatrixOperation();
			Prompt::GetValidInput(ch, 3);

			if (ch == 'R')
				continue;

			switch (ch) {

			case '1': ch = '+'; break;			// addition
			case '2': ch = '-'; break;			// subtraction
			case '3': ch = '*'; break;			// multiplication
			}

			system("CLS");

			// Display input
			cout << "Input: " << endl << endl;

			if (n == 2) {

				for (int i = 0; i < 2; i++) {

					for (int j = 0; j < 2; j++)
						cout << right << setw(4) << matrix2d_1[i][j] << " ";

					if (i == 0)
						cout << "  " << ch << "   ";
					else
						cout << "      ";

					for (int j = 0; j < 2; j++)
						cout << left << setw(4) << matrix2d_2[i][j] << " ";

					cout << endl;
				}

				// Display result
				cout << endl << "Result: " << endl << endl;

				switch (ch) {

				case '+': (Matrix2D(matrix2d_1) + Matrix2D(matrix2d_2)).display(); break;
				case '-': (Matrix2D(matrix2d_1) - Matrix2D(matrix2d_2)).display(); break;
				case '*': (Matrix2D(matrix2d_1) * Matrix2D(matrix2d_2)).display(); break;
				}
			}

			else {

				for (int i = 0; i < 3; i++) {

					for (int j = 0; j < 3; j++)
						cout << right << setw(4) << matrix3d_1[i][j] << " ";

					if (i == 1)
						cout << "  " << ch << "   ";
					else
						cout << "      ";

					for (int j = 0; j < 3; j++)
						cout << left << setw(4) << matrix3d_2[i][j] << " ";

					cout << endl;
				}

				// Display result
				cout << endl << "Result: " << endl;

				switch (ch) {

				case '+': (Matrix3D(matrix3d_1) + Matrix3D(matrix3d_2)).display(); break;
				case '-': (Matrix3D(matrix3d_1) - Matrix3D(matrix3d_2)).display(); break;
				case '*': (Matrix3D(matrix3d_1) * Matrix3D(matrix3d_2)).display(); break;
				}
			}

			break;

		// Vector operations
		case '2':
			cout << "Enter vector dimension: ";
			Prompt::GetValidDimension(n);

			double a1, b1, c1,
				a2, b2, c2;

			// Read vectors from input
			cout << "First vector:" << endl;
			if (n == 2) {

				cin >> a1 >> b1;

				cout << "Second vector:" << endl;
				cin >> a2 >> b2;
			}
			else {

				cin >> a1 >> b1 >> c1;

				cout << "Second vector:" << endl;
				cin >> a2 >> b2 >> c2;
			}

			cout << endl;

			// Prompt user to select operation
			Prompt::SelectVectorOperation();
			Prompt::GetValidInput(ch, 4);

			if (ch == 'R')
				continue;

			switch (ch) {

			case '1': ch = '+'; break;			// addition
			case '2': ch = '-'; break;			// subtraction
			case '3': ch = '.'; break;			// dot product
			case '4': ch = 'x'; break;			// cross product
			}

			system("CLS");

			// Display input
			cout << "Input: " << endl << endl;

			if (n == 2) {

				cout << right << setw(4) << a1 << "   " << ch << "   " << left << setw(4) << a2 << endl;
				cout << right << setw(4) << b1 << "       " << left << setw(4) << b2 << endl;

				cout << endl << endl;

				// Display result
				cout << "Result: " << endl << endl;

				switch (ch) {

				case '+': (Vector2D(a1, b1) + Vector2D(a2, b2)).display(); break;
				case '-': (Vector2D(a1, b1) - Vector2D(a2, b2)).display(); break;
				case '.': cout << Vector2D(a1, b1).dot(Vector2D(a2, b2)) << endl; break;
				case 'x': cout << Vector2D(a1, b1).cross(Vector2D(a2, b2)) << endl; break;
				}
			}

			else {

				cout << right << setw(4) << a1 << "       " << left << setw(4) << a2 << endl;
				cout << right << setw(4) << b1 << "   " << ch << "   " << left << setw(4) << b2 << endl;
				cout << right << setw(4) << c1 << "       " << left << setw(4) << c2 << endl;

				cout << endl << endl;

				// Display result
				cout << "Result: " << endl << endl;

				switch (ch) {

				case '+': (Vector3D(a1, b1, c1) + Vector3D(a2, b2, c2)).display(); break;
				case '-': (Vector3D(a1, b1, c1) - Vector3D(a2, b2, c2)).display(); break;
				case '.': cout << Vector3D(a1, b1, c1).dot(Vector3D(a2, b2, c2)) << endl; break;
				case 'x': (Vector3D(a1, b1, c1).cross(Vector3D(a2, b2, c2))).display(); break;
				}
			}

			break;

		// Vector-matrix multiplication
		case '3':
			cout << "Enter vector dimension: ";
			Prompt::GetValidDimension(n);

			double a, b, c;

			// Read vector from input
			cout << "Vector:" << endl;
			if (n == 2)
				cin >> a >> b;
			else
				cin >> a >> b >> c;

			cout << endl;

			// Prompt user to select an operation
			Prompt::SelectTransformationType();
			Prompt::GetValidInput(ch, 2);

			if (ch == 'R')
				continue;

			switch (ch) {

			// Standard vector-matrix multiplication
			case '1':

				double matrix2d[2][2], matrix3d[3][3];

				// Read matrix from input
				if (n == 2) {

					cout << "Enter a 2D matrix:" << endl;

					for (int i = 0; i < 2; i++)
						for (int j = 0; j < 2; j++)
							cin >> matrix2d[i][j];
				}
				else {

					cout << "Enter a 3D matrix:" << endl;

					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++)
							cin >> matrix3d[i][j];
				}

				system("CLS");

				// Display input
				cout << "Input: " << endl << endl;

				if (n == 2) {

					Vector2D vec(a, b);

					for (int i = 0; i < 2; i++) {

						for (int j = 0; j < 2; j++)
							cout << right << setw(4) << matrix2d[i][j] << " ";

						if (i == 0)
							cout << "  *   ";
						else
							cout << "      ";

						cout << left << setw(4) << vec[i];

						cout << endl;
					}

					// Display result
					cout << endl << "Result: " << endl << endl;

					(Matrix2D(matrix2d).transform(vec)).display();
				}

				else {

					Vector3D vec(a, b, c);

					for (int i = 0; i < 3; i++) {

						for (int j = 0; j < 3; j++)
							cout << right << setw(4) << matrix3d[i][j] << " ";

						if (i == 1)
							cout << "  *   ";
						else
							cout << "      ";

						cout << left << setw(4) << vec[i];

						cout << endl;
					}

					// Display result
					cout << endl << "Result: " << endl << endl;

					(Matrix3D(matrix3d).transform(vec)).display();
				}

				break;

			// Linear transformations
			case '2':

				cout << "Select a linear transformation: " << endl << endl;

				vector<int> options;
				int count = 0;

				// Display a list of linear transformations
				for (int i = 0; i < transformations.size(); i++) {

					if (transformations[i]->getDim() == n + 1) {

						count++;
						cout << "    " << count << ") " << transformations[i]->getName() << endl;
						options.push_back(i);
					}
				}

				cout << endl;
				Prompt::GetValidInput(ch, count);

				int num = options[int(ch - '0') - 1];
				KMP isRotation("otation", transformations[num]->getName());

				double angle;
				vector<double> args;
				// Check whether the matrix is a rotation matrix using KMP pattern matching
				if (++isRotation) {

					cout << "Enter angle in degrees: ";
					cin >> angle;

					transformations[num]->setArg(angle);
				}
				else {

					double x, y, z;
					if (n == 2) {

						cout << "Enter arguments for x- and y-axis: ";
						cin >> x >> y;

						args = { x, y };
					}
					else {

						cout << "Enter arguments for x-, y-, and z-axis: ";
						cin >> x >> y >> z;

						args = { x, y, z };
					}

					transformations[num]->setArg(args);
				}

				system("CLS");

				// Display input
				cout << "Input: " << endl << endl;

				if (n == 2) {

					Vector2D vec(a, b);

					for (int i = 0; i < 3; i++) {

						for (int j = 0; j < 3; j++)
							cout << right << setw(6) << round((transformations[num]->operator()(i, j)) * 1000) / 1000 << " ";

						if (i == 1)
							cout << "  *   ";
						else
							cout << "      ";

						if (i < 2)
							cout << left << setw(6) << vec[i];
						else
							cout << left << setw(6) << 1;

						cout << endl;
					}

					// Display result
					cout << endl << "Result: " << endl << endl;

					TransMatrix2D::localize(transformations[num]->transform(vec)).display();
				}

				else {

					Vector3D vec(a, b, c);

					for (int i = 0; i < 4; i++) {

						for (int j = 0; j < 4; j++)
							cout << right << setw(6) << round((transformations[num]->operator()(i, j)) * 1000) / 1000 << " ";

						if (i == 1)
							cout << "  *   ";
						else
							cout << "      ";

						if (i < 3)
							cout << left << setw(6) << vec[i];
						else
							cout << left << setw(6) << 1;

						cout << endl;
					}

					// Display result
					cout << endl << "Result: " << endl << endl;

					TransMatrix3D::localize(transformations[num]->transform(vec)).display();
				}

				break;
			}

			break;
		}
		
		cout << endl << endl << "Enter X to exit.\nPress \"Enter\" to continue." << endl;
		cin >> noskipws >> ch >> ch;
	}

	system("CLS");

	cout << "See you next time!" << endl << endl;
}