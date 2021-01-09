// ------------------------------------------------------------------------//
// Name: Tomas H Woldemichael
// Date: Jan 9, 2021
// File Name: SearchTree.cpp
// Title: PROGRAM 4
// Description:
// ------------------------------------------------------------------------//

#include "SearchTree.h"
#include <iostream>


SearchTree::SearchTree(){
    root = nullptr;

}

SearchTree::~SearchTree(){
    clear(root);

}

void SearchTree::clear(Node *&node){
    cout << "you have cleared all nodes" << endl;

}


