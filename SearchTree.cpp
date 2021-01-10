// ------------------------------------------------------------------------//
// Name: Tomas H Woldemichael
// Date: Jan 9, 2021
// File Name: SearchTree.cpp
// Title: PROGRAM 4
// Description:
//
// ------------------------------------------------------------------------//

#include "SearchTree.h"
#include <iostream>

SearchTree::SearchTree() : root(nullptr)
{
}

//STOPPED AT COPY CONSTRUCTOR!
SearchTree::SearchTree(const SearchTree &org)
{
    root = copyPrivate(org.root);
}

SearchTree::~SearchTree()
{
    clear(root);
}

Node *SearchTree::copyPrivate(const Node *copyNode)
{
    // if node is empty return
    if (copyNode == nullptr)
    {
        return nullptr;
    }

    Comparable *newItem = new Comparable;
    newItem->setItem(copyNode->item->getItem());
    Node *newNode = new Node(newItem);

    newNode->count = copyNode->count; // copy primative data types

    newNode->left = copyPrivate(copyNode->left); //
    newNode->right = copyPrivate(copyNode->right);

    return newNode;
}

void SearchTree::clear(Node *&node)
{
    cout << "you have cleared all nodes" << endl;
}

void SearchTree::makeEmpty()
{
    makeEmptyPrivate(root);
}

void SearchTree::makeEmptyPrivate(Node *&node)
{
    if (node == nullptr)
    {
        return;
    }

    makeEmptyPrivate(node->left);
    makeEmptyPrivate(node->right);

    delete node;
    node = nullptr;
}

bool SearchTree::insert(Comparable *ptr)
{
    bool flag = false;
    insertPrivate(ptr, root, flag);

    return flag;
}

void SearchTree::insertPrivate(Comparable *ptr, Node *&node, bool &flag)
{
    
    // Comparable obj1 = *ptr;
    // Comparable obj2 = *(node->item);

    // Tree is empty
    if (node == nullptr)
    {
        Node *newNode = new Node(ptr);
        node = newNode;
        flag = true;
        return;
    }
    else if (*ptr == *(node->item)) // char is already in tree
    {
        node->count = node->count + 1;
        
    }
    else if (*ptr < *(node->item))
    {
        insertPrivate(ptr, node->left, flag);
    }
    else if (*ptr > *(node->item))
    {
        insertPrivate(ptr, node->right, flag);
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
    cout << node->item->getItem() << " " << node->count << endl;
    inOrderPrivate(node->right);
}

ostream &operator<<(ostream &output, const SearchTree &I)
{
    I.inOrderPrivate(I.root);

    return output;
}

SearchTree &SearchTree::operator=(const SearchTree &rhs)
{
    if (this != &rhs)
    {                
        this->makeEmpty();
        this->root = copyPrivate(rhs.root);
    }

    return *this;

}

