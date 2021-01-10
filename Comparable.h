// ------------------------------------------------------------------------//
// Name: Tomas H Woldemichael
// Date: January 9, 2021
// File Name: Comparable.cpp
// Title: PROGRAM 1
// Description:
//
//
// ------------------------------------------------------------------------//
#pragma once

#include <iostream>

using namespace std;

class Comparable
{
private:
    char c;

public:
    //friend bool operator==(const Comparable& lhs, const Comparable& rhs);
    bool operator==(const Comparable& rhs) const;

    //friend bool operator!=(const Comparable& lhs, const Comparable& rhs);
    bool operator!=(const Comparable& rhs) const;

    //friend bool operator<(const Comparable& lhs, const Comparable& rhs);
    bool operator<(const Comparable& rhs);

    //friend bool operator>(const Comparable& lhs, const Comparable& rhs);
    bool operator>(const Comparable& rhs);

    friend ostream &operator<<(ostream &output, Comparable &I);
    friend istream &operator>>(istream &input, Comparable &I);
    const void itemDisplay() const;
    char getItem();
    const bool setItem(const char newC);
};