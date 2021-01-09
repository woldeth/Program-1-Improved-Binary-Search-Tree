//---------------------------------------------------------------------------
// HW1.CPP
// Driver code for testing SearchTree class.
// Authors:  Clark Olson and Carol Zander
//---------------------------------------------------------------------------
// This code tests all of the basic functionality of the SearchTree class
// for CSS 502 HW 1.  It is not meant to exhaustively test the class.
//
// Assumptions:
//   -- a text file named "HW1.txt" exists in the same directory as the code
//---------------------------------------------------------------------------

#include <fstream>
#include <string>
#include <sstream>
#include "SearchTree.cpp"
using namespace std;



// //-------------------------- buildTree --------------------------------------
// // Builds a SearchTree of Comparables by reading them from a file stream
// // Preconditions:   infile has been successfully initialized
// // Postconditions:  T stores the Comparables (and number of occurrences)
// //                   of the unprocessed Comparables remaining in infile, 
// //                   (in addition to whatever was previously stored in T)

// void buildTree(ifstream &infile, SearchTree &T) {

// 	// Loop until end of file
// 	while (!infile.eof()) {

// 		// Get next Comparable using operator>>
// 		Comparable* ptr = new Comparable;
// 		infile >> *ptr;
// 		if (infile.eof()) {
// 			delete ptr;
// 			return;
// 		}

// 		bool success = T.insert(ptr);
// 		if (!success) {						// must be a repeated item, so it was not inserted
// 			delete ptr;						// deallocate if not inserted 
// 		}
// 		ptr = nullptr;
// 	}
// }



// //-------------------------- main -------------------------------------------
// // Tests the SearchTree class by reading data from "HW1.txt" and playing with it
// // Preconditions:   None (although it won't test anything if "HW1.txt"
// //					 doesn't exist.)
// // Postconditions:  All of the basic operations of the SearchTree class are used. 
// //                  Should compile, run to completion, and output correct 
// //                  answers if SearchTree and Comparable are implemented correctly.

int main() {

	cout << "This is working" << endl;

	// open file 
	ifstream infile("HW1.txt");
	if (!infile) {
		cerr << "File could not be opened." << endl;
		return 1;
	}

	
	// test copy constructor, operator=, self-assignment for compilation
//	SearchTree T, T2, duplicate;
//	buildTree(infile, T);

// 	SearchTree first(T);
// 	duplicate = duplicate = T;
// 	duplicate.makeEmpty();

// 	// test operator<<
// 	cout << "Frequency table:  " << endl;
// 	cout << T;
// 	cout << endl;

// 	// create some Comparables to retrieve
// 	// the syntax is a bit strange here, since the only ways to create new
// 	// Comparables are using operator>> (and constructors supplied by the compiler)

// 	string char1 = "f";
// 	Comparable in1;
// 	stringstream s1(char1);
// 	s1 >> in1;

// 	string char2 = "x";
// 	Comparable in2;
// 	stringstream s2(char2);
// 	s2 >> in2;

// 	// test retrieve, depth, descendants
// 	const Comparable *out1 = T.retrieve(in1);
// 	cout << "Retrieve - " << char1 << ":          " << (out1 != nullptr ? "found" : "not found")
// 		<< endl;
// 	const Comparable *out2 = T.retrieve(in2);
// 	cout << "Retrieve - " << char2 << ":          " << (out2 != nullptr ? "found" : "not found")
// 		<< endl;
// 	cout << "Depth of - " << char1 << ":          " << T.depth(in1) << endl;
// 	cout << "Depth of - " << char2 << ":          " << T.depth(in2) << endl;
// 	cout << "Descendants of - " << char1 << ":    " << T.descendants(in1) << endl;
// 	cout << "Descendants of - " << char2 << ":    " << T.descendants(in2) << endl;

// 	// test operator==, operator!=
// 	T2 = T;
// 	cout << "T == T2?               " << (T == T2 ? "equal" : "not equal") << endl;
// 	cout << "T != T2?               " << (T != T2 ? "not equal" : "equal") << endl;
// 	SearchTree T3 = T2;                        // test copy constructor, too
// 	cout << "T3 == T2?              " << (T == T2 ? "equal" : "not equal") << endl;
// 	cout << "T3 != T2?              " << (T != T2 ? "not equal" : "equal") << endl;
// 	T2.makeEmpty();

// 	Comparable *in3 = new Comparable;
// 	stringstream s3(char1);
// 	s3 >> *in3;

// 	// test insert and operators
// 	bool success = T3.insert(in3);
// 	if (!success) delete in3;
// 	in3 = nullptr;
// 	cout << "T == T3?               " << (T == T3 ? "equal" : "not equal") << endl;
// 	cout << "T != T3?               " << (T != T3 ? "not equal" : "equal") << endl;

// 	// test remove
// 	if (!T.remove(in1))
// 		cout << char1 << " - not found." << endl;
// 	else
// 		cout << char1 << " - removed (one instance)." << endl;
	
// 	if (!T.remove(in2))
// 		cout << char2 << " - not found." << endl;
// 	else
// 		cout << char2 << " - removed (one instance)." << endl;

	return 0;
}