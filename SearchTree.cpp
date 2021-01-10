// ------------------------------------------------------------------------//
// Name: Tomas H Woldemichael
// Date: Jan 9, 2021
// File Name: SearchTree.cpp
// Title: PROGRAM 4
// Description:
// ------------------------------------------------------------------------//

#include "SearchTree.h"
#include <iostream>

SearchTree::SearchTree() : root(nullptr)
{
}

//STOPPED AT COPY CONSTRUCTOR!
SearchTree::SearchTree(const SearchTree &org){
    if (org.root == nullptr){
        root = nullptr;
    }else{

        root->count = org.root->count;

    }
}

SearchTree::~SearchTree()
{
    clear(root);
}

void SearchTree::clear(Node *&node)
{
    cout << "you have cleared all nodes" << endl;
}

bool SearchTree::insert(Comparable *ptr)
{
    insertPrivate(ptr, root);

    return true;
}

void SearchTree::insertPrivate(Comparable *ptr, Node *&node)
{

    // Comparable obj1 = *ptr;
    // Comparable obj2 = *(node->item);

    // Tree is empty
    if (node == nullptr)
    {
        Node *newNode = new Node(ptr);
        node = newNode;
        return;
    }
    else if (*ptr == *(node->item)) // char is already in tree
    {
        node->count = node->count + 1;
    }
    else if (*ptr < *(node->item))
    {
        insertPrivate(ptr, node->left);
    }
    else if (*ptr > *(node->item))
    {
        insertPrivate(ptr, node->right);
    }
}

void SearchTree::inOrderPrivate(const Node *const &node) const
{

    if (node == nullptr)
    {
        return;
    }

    //inorder traversal
    inOrderPrivate(node->left);
    node->item->itemDisplay();
    cout << " " << node->count << endl;
    inOrderPrivate(node->right);
}

ostream &operator<<(ostream &output, const SearchTree &I)
{
    I.inOrderPrivate(I.root);

    return output;
}
