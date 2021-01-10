// ------------------------------------------------------------------------//
// Name: Tomas H Woldemichael
// Date: Jan 9, 2021
// File Name: SearchTree.cpp
// Title: PROGRAM 4
// Description:
// ------------------------------------------------------------------------//

#include "Comparable.h"
#include <iostream>


bool operator==(const Comparable& lhs, const Comparable& rhs){
    return lhs.c == rhs.c;
}

bool operator!=(const Comparable& lhs, const Comparable& rhs){
    return lhs.c != rhs.c;
}

bool operator<(const Comparable& lhs, const Comparable& rhs){
    return lhs.c < rhs.c;
}
bool operator>(const Comparable& lhs, const Comparable& rhs){
    return lhs.c > rhs.c;
}

ostream &operator<<(ostream &output, Comparable &I){
    cout << I.c;
    return output;
}

istream &operator>>(istream &input, Comparable &I){
    input >> I.c;
    return input;
}

const void Comparable::itemDisplay() const{
    cout << c;
}

char Comparable::getItem() {
    return c;
}

const bool Comparable::setItem(const char newC) {
    c = newC;
    return true;
}

