// ------------------------------------------------------------------------//
// Name: Tomas H Woldemichael
// Date: January 9, 2021
// File Name: SearchTree.cpp
// Title: PROGRAM 1
// Description:
//
//
// ------------------------------------------------------------------------//
#pragma once

#include <iostream>
#include "Comparable.h"

using namespace std;

struct Node
{
  int count;
  Comparable *item;
  Node *left;
  Node *right;
};

class SearchTree
{

private:
  Node *root;

public:
  //Constructors and destructor
  SearchTree();                      // Constructor creates a BST new root
  // SearchTree(const SearchTree &org); // Copy constuctor that makes a deep copy of object
  ~SearchTree();                     // Destructor
  void clear(Node *&node);           // Destroy tree for destuctor

  //Overloaded operators
  // SearchTree &operator=(const SearchTree &rhs);               //Assignment of one tree to another (Deep copy)
  // bool operator==(const SearchTree &rhs);                     //Bool to see if object have all the same node values
  // bool operator!=(const SearchTree &rhs);                     //Bool to see if object do not equal each other
  // friend ostream &operator<<(ostream &output, SearchTree &I); // print out the Nodes item and frequency

  //Mutators
  bool insert(Comparable *c);       // inserts a Comparable into the tree or increments
  // bool remove(const Comparable &c); //removes one occurrence of a Comparable from the tree
  // void makeEmpty();                 // removes and deallocates all of the data from the tree (Tree still there)

  //Accessors
  // const Comparable *retrieve(const Comparable &) const;
  // int depth(const Comparable &) const;
  // int descendants(const Comparable &) const;
};