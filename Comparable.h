// ------------------------------------------------------------------------//
// Name: Tomas H Woldemichael
// Date: January 13, 2021
// File Name: Comparable.h
// Title: PROGRAM 1
// Description: This file is the header file for the Comparable class. Users
// Will be able to inherit this class and replace the item with a private
// primative type of their chose. The comparable class will handles basic operators
// such as but not limited to does not equal, less than, greater than and more.
// ------------------------------------------------------------------------//
#pragma once

#include <iostream>

using namespace std;

class Comparable
{
private:
	char c;

public:
	bool operator==(const Comparable &rhs) const; // Checks if lhs comparable is equal to rhs
	bool operator!=(const Comparable &rhs) const; // Checks if lhs comparable is not equal to rhs
	bool operator<(const Comparable &rhs) const;  // Checks if lhs comparable is less than rhs
	bool operator>(const Comparable &rhs) const;  // Checks if lhs comparable is greater than rhs

	friend ostream &operator<<(ostream &output, Comparable &I); // Displays private member variable to ostream
	friend istream &operator>>(istream &input, Comparable &I);	// Assigns inputted variable through istream to private member variable
};