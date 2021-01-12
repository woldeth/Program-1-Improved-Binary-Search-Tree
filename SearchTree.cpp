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

    newNode->left = copyPrivate(copyNode->left);
    newNode->right = copyPrivate(copyNode->right);

    return newNode;
}

void SearchTree::clear(Node *&node)
{
    //cout << "you have cleared all nodes" << endl;
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
        this->makeEmpty(); // clear lhs
        this->root = copyPrivate(rhs.root);
    }

    return *this;
}

bool SearchTree::operator==(const SearchTree &rhs)
{
    bool sameTree = true;
    eePrivate(root, rhs.root, sameTree);
    return sameTree;
}

void SearchTree::eePrivate(const Node *lhsNode, const Node *rhsNode, bool &sameTree)
{
    if (lhsNode == nullptr && rhsNode != nullptr)
    {
        sameTree = false;
    }

    if (lhsNode != nullptr && rhsNode == nullptr)
    {
        sameTree = false;
    }

    if (lhsNode == nullptr || rhsNode == nullptr)
    {
        return;
    }

    //inorder traversal
    eePrivate(lhsNode->left, rhsNode->left, sameTree);

    if (lhsNode->count != rhsNode->count)
    {

        sameTree = false;
    }
    else if (*(lhsNode->item) != *(lhsNode->item))
    {

        sameTree = false;
    }

    eePrivate(lhsNode->right, rhsNode->right, sameTree);
}

bool SearchTree::operator!=(const SearchTree &rhs)
{
    return !(*this == rhs);
}

const Comparable *SearchTree::retrieve(const Comparable &c1) const
{
    bool found = false;

    Node *ptr = retrievePrivate(root, c1, found);

    if (found)
    {
        return ptr->item;
    }

    return nullptr;
}

Node *SearchTree::retrievePrivate(Node *node, const Comparable &c1, bool &found) const
{
    if (node == nullptr)
        return node;

    if (*node->item == c1)
    {
        found = true;
        return node;
    }

    if (*node->item < c1)
    {
        return retrievePrivate(node->right, c1, found);
    }

    return retrievePrivate(node->left, c1, found);
}