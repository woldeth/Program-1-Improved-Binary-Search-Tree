// ------------------------------------------------------------------------//
// Name: Tomas H Woldemichael
// Date: Jan 13, 2021
// File Name: Comparable.cpp
// Title: PROGRAM 4
// Description: This the implementation file for the Comparable class. This 
// class is class that can be inherited to have an item c replaced with any
// primative type. This class will handle most operators and istream and ostream
// ------------------------------------------------------------------------//

#include "Comparable.h"
#include <iostream>


/** operator==(const Comparable &rhs)
 * @brief   Determines if two comparables are equal to each other
 * @pre     The two comparables are unknow if they are equal to each other
 * @post    Returns a true if the comparables are equal to each other 
*/
bool Comparable::operator==(const Comparable &rhs) const
{
    return c == rhs.c;
}

/** operator!=(const Comparable &rhs)
 * @brief   Determines if two comparables are not equal to each other
 * @pre     The two comparables are unknown if they are not equal to each other
 * @post    Returns a true if the comparables are not equal to each other 
*/
bool Comparable::operator!=(const Comparable &rhs) const
{
    return c != rhs.c;
}


/** operator<(const Comparable &rhs)
 * @brief   Determines if comparable on lhs is less than rhs
 * @pre     Unknown if lhs is less than rhs
 * @post    Returns a true if the comparables on lhs is less
*/
bool Comparable::operator<(const Comparable &rhs) const
{
    return c < rhs.c;
}

/** operator>(const Comparable &rhs)
 * @brief   Determines if comparable on lhs is greater than rhs
 * @pre     Unknown if lhs is greater than rhs
 * @post    Returns a true if the comparables on lhs is less
*/
bool Comparable::operator>(const Comparable &rhs) const
{
    return c > rhs.c;
}

/** operator<<(ostream &output, Comparable &I)
 * @brief   Gives defintion for when a comparable is passed through ostream
 * @post    Returns ostream to print out the item in comparable
*/
ostream &operator<<(ostream &output, Comparable &I)
{
    cout << I.c;
    return output;
}


/** ooperator>>(istream &input, Comparable &I)
 * @brief   Gives defintion for when a comparable is passed through istream
 * @post    Returns istream and updates comparable private varible c
*/
istream &operator>>(istream &input, Comparable &I)
{
    input >> I.c;
    return input;
}


