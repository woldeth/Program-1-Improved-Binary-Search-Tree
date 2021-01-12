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

  Comparable *item;
  int count;
  Node *left;
  Node *right;
  Node(Comparable *i) : item(i), count(1), left(nullptr), right(nullptr) {}
};

class SearchTree
{

private:
  Node *root;
  void insertPrivate(Comparable *ptr, Node *&node, bool &flag);
  void inOrderPrivate(const Node *const &node) const; // inorder traverals
  Node *copyPrivate(const Node *copyNode);            // preorder taversal
  void makeEmptyPrivate(Node *&node);                 // post order traversal
  void eePrivate(const Node *lhsNode, const Node *rhsNode, bool &sameTree);
  Node *retrievePrivate(Node *node, const Comparable &c1, bool &found) const;
  void depthPrivate(Node *node, const Comparable & c1, int &depth) const;
  void descendantsPrivate(Node *node, const Comparable &c1, int &num) const;
  void removePrivate(Node *nodeP, const Comparable &c1, bool &removed);
  void removeRootPrivate();
  Comparable *smallestSubTreePrivate(Node *node);
  void removeChildNodePrivate(Node *nodeP, Node *node, bool left);

public:
  //Constructors and destructor
  SearchTree();                      // Constructor creates a BST new root
  SearchTree(const SearchTree &org); // Copy constuctor that makes a deep copy of object
  ~SearchTree();                     // Destructor
  void clear(Node *&node);           // Destroy tree for destuctor

  //Overloaded operators
  SearchTree &operator=(const SearchTree &rhs); //Assignment of one tree to another (Deep copy)
  bool operator==(const SearchTree &rhs);                     //Bool to see if object have all the same node values
  bool operator!=(const SearchTree &rhs);                     //Bool to see if object do not equal each other
  friend ostream &operator<<(ostream &output, const SearchTree &I); // print out the Nodes item and frequency

  //Mutators
  bool insert(Comparable *ptr); // inserts a Comparable into the tree or increments

  bool remove(const Comparable &c1); //removes one occurrence of a Comparable from the tree
  void makeEmpty(); // removes and deallocates all of the data from the tree (Tree still there)

  //Accessors
  const Comparable *retrieve(const Comparable & c1) const;
  int depth(const Comparable & c1) const;
  int descendants(const Comparable & c1) const;
  Comparable* smallestSubTree();
};