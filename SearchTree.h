// ------------------------------------------------------------------------//
// Name: Tomas H Woldemichael
// Date: January 13, 2021
// File Name: SearchTree.h
// Title: PROGRAM 1
// Description: This file is the SearchTree header file. Users will be able
// to create a Binary Search tree and input different Comparablie items into
// the SearchTree. The Search true has additional features to identify
// key characteristics of the SearchTree such as depth, descendants and more.
// ------------------------------------------------------------------------//
#pragma once

#include <iostream>
#include "Comparable.h"

using namespace std;

struct Node
{

  Comparable *item;                                                         // Pointer to comparable obj
  int count;                                                                // Holds count of number of times comparable in BinarySearchTree
  Node *left;                                                               // Pointer to left child
  Node *right;                                                              // Pointer to right child
  Node(Comparable *i) : item(i), count(1), left(nullptr), right(nullptr) {} // Constructor to initialize node
};

class SearchTree
{

private:
  Node *root; // Root Node of SearchTree

  void insertPrivate(Comparable *ptr, Node *&node, bool &flag);               // Helper function for insertion of new node - inorder traverals
  void inOrderPrivate(const Node *const &node) const;                         // Helper function for Ostream << - preorder taversal
  Node *copyPrivate(const Node *copyNode);                                    // Helper function for copy constuctor - Deep copy
  void makeEmptyPrivate(Node *&node);                                         // Helper function to clear SearchTree - post order traversal
  void eePrivate(const Node *lhsNode, const Node *rhsNode, bool &sameTree);   // Helper function to determine if two SearchTree are equeal
  Node *retrievePrivate(Node *node, const Comparable &c1, bool &found) const; // Helper function to retrieve a comparable from a node
  void depthPrivate(Node *node, const Comparable &c1, int &depth) const;      // Helper function to get the depth of a node
  void descendantsPrivate(Node *node, const Comparable &c1, int &num) const;  // Helper function to determine the amount of children nodes
  void removePrivate(Node *nodeP, const Comparable &c1, bool &removed);       // Helper function to remove a node in the SearchTree or deincrement count
  void removeRootPrivate();                                                   // Helper function to remove the root node
  Comparable *smallestSubTreePrivate(Node *node);                             // Helper function to iteratate left from given node
  void removeChildNodePrivate(Node *nodeP, Node *node, bool left);            // Helper function to remove node that is not a root

public:
  //Constructors and destructor
  SearchTree();                      // Constructor creates a BST new root
  SearchTree(const SearchTree &org); // Copy constuctor that makes a deep copy of object
  ~SearchTree();                     // Destructor

  //Overloaded operators
  SearchTree &operator=(const SearchTree &rhs);                     // Assignment of one tree to another (Deep copy)
  bool operator==(const SearchTree &rhs);                           // Bool to see if object have all the same node values
  bool operator!=(const SearchTree &rhs);                           // Bool to see if object do not equal each other
  friend ostream &operator<<(ostream &output, const SearchTree &I); // Print out the Nodes item and frequency

  //Mutators
  bool insert(Comparable *ptr);      // Inserts a Comparable into the tree or increments
  bool remove(const Comparable &c1); // Removes one occurrence of a Comparable from the tree
  void makeEmpty();                  // Removes and deallocates all of the data from the tree (Tree still there)

  //Accessors
  const Comparable *retrieve(const Comparable &c1) const; // Returns the comparabale in within the SearchTree if found
  int depth(const Comparable &c1) const;                  // Returns the depth of the a node within a SearchTree
  int descendants(const Comparable &c1) const;            // Returns the amount of child nodes a for a particular node
  Comparable *smallestSubTree();                          // Returns the a potiner to the smallest subtree
};