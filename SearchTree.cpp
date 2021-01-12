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
    makeEmptyPrivate(root);
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

    delete node->item;
    node->item = nullptr;

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
    {
        return node;
    }

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

int SearchTree::depth(const Comparable &c1) const
{
    int depth = 0;
    depthPrivate(root, c1, depth);
    return depth;
}

void SearchTree::depthPrivate(Node *node, const Comparable &c1, int &depth) const
{
    if (node == nullptr)
    {
        depth = -1;
        return;
    }

    if (*node->item == c1)
    {
        return;
    }

    if (*node->item < c1)
    {
        depth = depth + 1;
        return depthPrivate(node->right, c1, depth);
    }

    depth = depth + 1;
    return depthPrivate(node->left, c1, depth);
}

int SearchTree::descendants(const Comparable &c1) const
{
    int num = 0;
    descendantsPrivate(root, c1, num);
    return num;
}

void SearchTree::descendantsPrivate(Node *node, const Comparable &c1, int &num) const
{
    if (node == nullptr)
    {
        num = -1;
        return;
    }

    if (*node->item == c1)
    {
        if (node->left && node->right)
        {
            num = 2;
        }
        else if (node->left || node->right)
        {
            num = 1;
        }
        else
        {
            num = 0;
        }

        return;
    }

    if (*node->item < c1)
    {
        return descendantsPrivate(node->right, c1, num);
    }

    return descendantsPrivate(node->left, c1, num);
}

bool SearchTree::remove(const Comparable &c1)
{

    bool removed = false;
    removePrivate(root, c1, removed);
    return removed;
}

void SearchTree::removePrivate(Node *nodeP, const Comparable &c1, bool &removed)
{
    if (root != nullptr)
    {
        if (*root->item == c1)
        {
            removeRootPrivate();
            removed = true;
            return;
        }

        if (c1 < *nodeP->item && nodeP->left != nullptr)
        {
            //code1
            if (*nodeP->left->item == c1)
            {
                removeChildNodePrivate(nodeP, nodeP->left, true);  
                removed = true;
            }
            else
            { // code2
                removePrivate(nodeP->left, c1, removed);
            }
        }
        else if (c1 > *nodeP->item && nodeP->right != nullptr)
        {
            //code1
            if (*nodeP->right->item == c1)
            {
                removeChildNodePrivate(nodeP, nodeP->right, false); 
            }
            else
            { // code2
                removePrivate(nodeP->right, c1, removed);
            }
        }

        //return removePrivate(nodeP->left, c1, removed);
    }
}

void SearchTree::removeRootPrivate()
{
    bool removed = false;

    if (root->count >= 1)
    {
        root->count = root->count - 1;
        return;
    }
    else
    {
        Node *ptr = root;
        Comparable *item = root->item;

        if (root->left == nullptr && root->right == nullptr)
        {
            //root = nullptr;

            delete ptr->item;
            ptr->item = nullptr;

            delete ptr;
            root = nullptr;
        }
        else if (root->left == nullptr && root->right != nullptr)
        {
            root = root->right;
            delete ptr;
            ptr = nullptr;
        }
        else if (root->left != nullptr && root->right == nullptr)
        {
            root = root->left;
            delete ptr;
            ptr = nullptr;
        }
        else if (root->left != nullptr && root->right != nullptr)
        {
            Comparable *smallRT = smallestSubTreePrivate(root->right);
            removePrivate(root, *smallRT, removed);
            root->item = smallRT;
        }
    }
}

Comparable *SearchTree::smallestSubTree()
{
    return smallestSubTreePrivate(root);
}

Comparable *SearchTree::smallestSubTreePrivate(Node *node)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (node->left != nullptr)
        {
            return smallestSubTreePrivate(node->left);
        }
        else
        {
            return node->item;
        }
    }
}

void SearchTree::removeChildNodePrivate(Node *nodeP, Node *node, bool left)
{
    bool removed = false;
    Node *ptr;
    Comparable *smallRT;
    Comparable *item = node->item;

    if (node->left == nullptr && node->right == nullptr)
    {
        ptr = node;
        if (left == true)
        {
            nodeP->left = nullptr;
        }
        else
        {
            nodeP->right = nullptr;
        }

        delete ptr->item;
        ptr->item = nullptr;

        delete ptr;
        ptr = nullptr;
    }
    else if (node->left == nullptr && node->right != nullptr)
    {
        if (left)
        {
            nodeP->left = node->right;
        }
        else
        {
            nodeP->right = node->right;
        }

        node->right = nullptr;
        ptr = node;

        delete ptr->item;
        ptr->item = nullptr;

        delete ptr;
        ptr = nullptr;
    }
    else if (node->left != nullptr && node->right == nullptr)
    {
        if (left)
        {
            nodeP->left = node->left;
        }
        else
        {
            nodeP->right = node->left;
        }

        node->left = nullptr;
        ptr = node;

        delete ptr->item;
        ptr->item = nullptr;

        delete ptr;
        ptr = nullptr;
    }
    else if (node->left != nullptr && node->right != nullptr)
    {
        Comparable *smallRT = smallestSubTreePrivate(node->right);
        removePrivate(node, *smallRT, removed);
        node->item = smallRT;
    }
}

//Node *nodeP, const Comparable &c1, bool &removed