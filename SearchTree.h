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
    Node *left;
    Node *right;

};

class SearchTree
{

private:
  Node *root;

public:
  SearchTree();
  ~SearchTree();  
  void clear(Node *&node); 
            
};