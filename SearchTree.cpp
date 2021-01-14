// ------------------------------------------------------------------------//
// Name: Tomas H Woldemichael
// Date: Jan 13, 2021
// File Name: SearchTree.cpp
// Title: PROGRAM 4
// Description: This file is the implementation of the SearchTree class.
// Users will be able to create a binary search tree through the istream.
// This class allows for features such as depth, descendents of a particular
// node and more to use on the binary search tree object.
// ------------------------------------------------------------------------//

#include "SearchTree.h"
#include <iostream>

/** SearchTree() 
 * @brief   Default constructor.
 * @post    Sets root pointer to nullptr.
*/
SearchTree::SearchTree() : root(nullptr)
{
}

/** SearchTree(const SearchTree &org) 
 * @brief   Copy constuctor deep copy
 * @param   org The orginal search tree to copy
 * @post    Deep copy of search tree is created
*/
SearchTree::SearchTree(const SearchTree &org)
{
    root = copyPrivate(org.root);
}

/** ~WordTree()
 * @brief   Destructor.
 * @pre     Nodes are allocated in heap
 * @post    Clears all dynamic memory in heap.
*/
SearchTree::~SearchTree()
{
    makeEmptyPrivate(root);
}

/** copyPrivate(const Node *copyNode) 
 * @brief   Copy constuctor private helper method. Returns node pointer to root 
 * @param   copyNode The orginal search tree to copy
 * @post    Deep copy of search tree is created
*/
Node *SearchTree::copyPrivate(const Node *copyNode)
{
    // node is empty return
    if (copyNode == nullptr)
    {
        return nullptr;
    }

    Comparable *newItem = new Comparable(*copyNode->item);
    Node *newNode = new Node(newItem);

    newNode->count = copyNode->count; // copy primative data types

    newNode->left = copyPrivate(copyNode->left);
    newNode->right = copyPrivate(copyNode->right);

    return newNode;
}

/** makeEmpty()
 * @brief   Clears the binary search tree but allows for insertion to work. No returns 
 * @pre     The search tree has allocated nodes in heap
 * @post    Sets root pointer to nullptr.
*/
void SearchTree::makeEmpty()
{
    makeEmptyPrivate(root);
}

/** makeEmptyPrivate(Node *&node)
 * @brief   Private helper clears the binary search tree but allows for insertion to work. No returns
 * @param   node The node at which the recursion will start (root ususally)
 * @pre     The search tree has allocated nodes in heap
 * @post    Sets root pointer to nullptr.
*/
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

/** insert(Comparable *ptr)
 * @brief   Inserts or increments a node with the correct item. Returns bool if inserted
 * @param   ptr Pointer to the comparable to insert into SearchTree
 * @pre     There is a search tree to insert into
 * @post    The new node is inserted or increment node count
*/
bool SearchTree::insert(Comparable *ptr)
{
    bool flag = false; // flag onces inserted
    insertPrivate(ptr, root, flag);

    return flag;
}

/** insertPrivate(Comparable *ptr, Node *&node, bool &flag)
 * @brief   Inserts or increments a node with the correct item. Returns bool if inserted
 * @param   ptr Pointer to the comparable to insert into SearchTree
 * @param   node Pointer to root node to start the recursive proccess
 * @param   flag bool to identify if the node has been added to the SearchTree
 * @pre     There is a search tree to insert into
 * @post    The new node is inserted or increment node count
*/
void SearchTree::insertPrivate(Comparable *ptr, Node *&node, bool &flag)
{

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
        insertPrivate(ptr, node->left, flag); // traverse left
    }
    else if (*ptr > *(node->item))
    {
        insertPrivate(ptr, node->right, flag); // traverse right
    }
}

/** inOrderPrivate(const Node *const &node) const
 * @brief   Iterates through search tree in order. Private helper for << 
 * @param   node Pointer to root node to start the recursive proccess
 * @pre     There is a search tree to iteratate through
 * @post    Goes through each node and prints comparable and count to ostream
*/
void SearchTree::inOrderPrivate(const Node *const &node) const
{
    // node is empty
    if (node == nullptr)
    {
        return;
    }

    //inorder traversal
    inOrderPrivate(node->left);
    cout << *node->item << " " << node->count << endl; // prints out item and count
    inOrderPrivate(node->right);
}

/** operator<<(ostream &output, const SearchTree &I)
 * @brief   Prints searchtree through ostream. Returns ostream
 * @pre     There is a search tree to iteratate through
 * @post    Prints the comparable and count at each node 
*/
ostream &operator<<(ostream &output, const SearchTree &I)
{
    I.inOrderPrivate(I.root);

    return output;
}

/** operator=(const SearchTree &rhs)
 * @brief   Assigns rhs searchtree to lhs searchtree object
 * @pre     The lhs search tree is either the same or a different search tree
 * @post    Both the left and rhs search tree are the same 
*/
SearchTree &SearchTree::operator=(const SearchTree &rhs)
{
    // checks to see if lhs and rhs is the same
    if (this != &rhs)
    {
        this->makeEmpty();                  // clear lhs
        this->root = copyPrivate(rhs.root); // make a deep copy of the search tree
    }

    return *this;
}

/** operator==(const SearchTree &rhs)
 * @brief   Checks to seee if lhs and rhs search trees are the same. Returns bool
 * @param   rhs SearchTree obj that is being compared to the lhs 
 * @pre     Unknow if the lhs and rhs are equal to each other
 * @post    Determinations if lhs and rhs are the same.
*/
bool SearchTree::operator==(const SearchTree &rhs)
{
    bool sameTree = true;
    eePrivate(root, rhs.root, sameTree);
    return sameTree;
}

/** eePrivate(const Node *lhsNode, const Node *rhsNode, bool &sameTree)
 * @brief   == Private helper method to check if lhs and rhs are equal
 * @param   lhsNode Root node of lhs tree
 * @param   rhsNode Root node of rhs tree
 * @param   sameTree flag to determine if they are the same tree or not 
 * @pre     Unknown if the lhs and rhs are equal to eachother
 * @post    Determinations if lhs and rhs are the same.
*/
void SearchTree::eePrivate(const Node *lhsNode, const Node *rhsNode, bool &sameTree)
{
    // less nodes in one than the other
    if (lhsNode == nullptr && rhsNode != nullptr)
    {
        sameTree = false;
    }
    // less nodes in one than the other
    if (lhsNode != nullptr && rhsNode == nullptr)
    {
        sameTree = false;
    }
    // base case
    if (lhsNode == nullptr || rhsNode == nullptr)
    {
        return;
    }

    //inorder traversal
    eePrivate(lhsNode->left, rhsNode->left, sameTree);

    // check if count is the same
    if (lhsNode->count != rhsNode->count)
    {

        sameTree = false;
    }
    else if (*(lhsNode->item) != *(lhsNode->item)) // check if the item is the same or not
    {

        sameTree = false;
    }

    eePrivate(lhsNode->right, rhsNode->right, sameTree); // traverse
}

/** operator!=(const SearchTree &rhs)
 * @brief   Determines if lhs and rhs SearchTrees are not equal. Returns bool
 * @param   rhs SearchTree on rhs 
 * @pre     Unknow if the two searchTree are not equal to eachother
 * @post    Determination of SearchTrees are not equal
*/
bool SearchTree::operator!=(const SearchTree &rhs)
{
    return !(*this == rhs); // uses the == operater
}

/** retrieve(const Comparable &c1)
 * @brief   Gets the comparable from the the SearchTree. Returns comparable
 * @param   c1 The comparable the program will look for in search tree
 * @pre     Unknow if the comparable is in the searchtree
 * @post    Determine if comparable is in the tree
*/
const Comparable *SearchTree::retrieve(const Comparable &c1) const
{
    bool found = false;

    Node *ptr = retrievePrivate(root, c1, found);

    if (found == true)
    {
        return ptr->item;
    }

    return nullptr;
}

/** retrievePrivate(Node *node, const Comparable &c1, bool &found)
 * @brief   Private hellper, gets the comparable from the the SearchTree. Returns node pointer
 * @param   node Start of search tree toe begin iterating
 * @param   c1 The comparable the program will look for in search tree
 * @param   found The flag once the comparable is found
 * @pre     Unknow if the comparable is within the searchtree
 * @post    Determine if comparable is in the tree
*/
Node *SearchTree::retrievePrivate(Node *node, const Comparable &c1, bool &found) const
{
    //base case
    if (node == nullptr)
    {
        return node;
    }

    //checks if item is the same
    if (*node->item == c1)
    {
        found = true;
        return node;
    }

    // determine to check left or right subtree
    if (*node->item < c1)
    {
        return retrievePrivate(node->right, c1, found);
    }

    return retrievePrivate(node->left, c1, found);
}

/** depth(const Comparable &c1)
 * @brief   Returns the int depth of the node that holds the comparable
 * @param   c1 The comparable ths we would like to find in the SearchTree
 * pre      Depth of the comparable is unknown
 * @post    Determine if comparable is in the tree and returns depth
*/
int SearchTree::depth(const Comparable &c1) const
{
    int depth = 0;
    depthPrivate(root, c1, depth);
    return depth;
}

/** depthPrivate(Node *node, const Comparable &c1, int &depth) 
 * @brief   Private hellper, gets the comparable from the the SearchTree. 
 * @param   node The node at which the recursion will start
 * @param   c1 The comparable the program will look for in search tree
 * @param   depth The depth of the particular node with comparable
 * @pre     The depth of the comparable is unknown
 * @post    The depth will be found is the privare helper function
*/
void SearchTree::depthPrivate(Node *node, const Comparable &c1, int &depth) const
{
    // Node is not found
    if (node == nullptr)
    {
        depth = -1;
        return;
    }

    //base case
    if (*node->item == c1)
    {
        return;
    }

    // determines if comparable is less than for traversal
    if (*node->item < c1)
    {
        depth = depth + 1;
        return depthPrivate(node->right, c1, depth);
    }

    depth = depth + 1;
    return depthPrivate(node->left, c1, depth);
}

/** descendants(const Comparable &c1) 
 * @brief   Returns the amount of child nodes for a particular node. Returns an int 
 * @param   c1 The comparable the program will look for in search tree
 * @pre     The amount of children nodes are unknown
 * @post    The amount of descendant nodes for a particular node
*/
int SearchTree::descendants(const Comparable &c1) const
{

    bool found = false;
    Node *nodeItem = retrievePrivate(root, c1, found);
    int descendants = -1;

    if (nodeItem != nullptr)
    {
        descendants = descendantsPrivate(nodeItem) - 1;

        return descendants;
    }
    else
    {
        return -1;
    }
}

/** descendantsPrivate(Node *node, const Comparable &c1, int &num) 
 * @brief   Private helper, gets the amount of descedant nodes of a node 
 * @param   node The node at which the recursion will start
 * @pre     The amount of descendants for a node is unknown
 * @post    The amount of descendants for a node will be found.
*/

int SearchTree::descendantsPrivate(Node *node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    return 1 + descendantsPrivate(node->left) + descendantsPrivate(node->right);
}

/** remove(const Comparable &c1)
 * @brief   Removes a node from the searchtree. Returns bool if it does
 * @param   c1 The comparable the program will look for in search tree to remove
 * @pre     The node is in the search tree and it will be removed
 * @post    Removes the node or de increments the count
*/
bool SearchTree::remove(const Comparable &c1)
{

    bool removed = false;
    removePrivate(root, c1, removed);
    return removed;
}

/** removePrivate(Node *nodeP, const Comparable &c1, bool &removed)
 * @brief   Removes a node from the searchtree. Returns bool if it does
 * @param   node The node at which the recursion will start its search
 * @param   c1 The comparable the program will look for in search tree to remove
 * @param   removed Flag to later be returned once node is removed
 * @pre     The node is still in the search tree
 * @post    Removes the node or deincrements the count
*/
void SearchTree::removePrivate(Node *nodeP, const Comparable &c1, bool &removed)
{
    //check if there is a root
    if (root != nullptr)
    {
        //if item is in root
        if (*root->item == c1)
        {
            removeRootPrivate(); // private helper function to remove root
            removed = true;
            return;
        }

        // item is less then parent and left child has a node
        if (c1 < *nodeP->item && nodeP->left != nullptr)
        {
            //check to see if left child is the item
            if (*nodeP->left->item == c1)
            {
                removeChildNodePrivate(nodeP, nodeP->left, true); // private helper to remove child
                removed = true;
            }
            else
            {
                removePrivate(nodeP->left, c1, removed); // keep traversing left
            }
        } // item is greater than current parent and right node is available
        else if (c1 > *nodeP->item && nodeP->right != nullptr)
        {
            // check to see if right is the same as item
            if (*nodeP->right->item == c1)
            {
                removeChildNodePrivate(nodeP, nodeP->right, false); // private helper to remove child
                removed = true;
            }
            else
            {
                removePrivate(nodeP->right, c1, removed); // keep traversing right
            }
        }
    }
}

/** removeRootPrivate()
 * @brief   Removes the root node from the search tree
 * @pre     The node is still in the search tree
 * @post    Removes the node or deincrements the count
*/
void SearchTree::removeRootPrivate()
{
    bool removed = false;

    // deincrement if there is more than 1 instance
    if (root->count > 1)
    {
        root->count = root->count - 1;
        return;
    }
    else
    {
        Node *ptr = root;
        //Comparable *item = root->item;
        //Comparable smallRightsubTree;

        // no childern
        if (root->left == nullptr && root->right == nullptr)
        {
            root = nullptr;

            delete ptr->item;
            ptr->item = nullptr;

            delete ptr;
            ptr = nullptr;
            //root = nullptr;

        } // one child rhs
        else if (root->left == nullptr && root->right != nullptr)
        {
            root = root->right;
            ptr->right = nullptr;

            delete ptr->item;
            ptr->item = nullptr;

            delete ptr;
            ptr = nullptr;

        } //one child lhs
        else if (root->left != nullptr && root->right == nullptr)
        {
            root = root->left;
            ptr->left = nullptr;

            delete ptr->item;
            ptr->item = nullptr;

            delete ptr;
            ptr = nullptr;

        } // continue to traverse
        else if (root->left != nullptr && root->right != nullptr)
        {
            // Comparable *smallRT = smallestSubTreePrivate(root->right);
            // Comparable *newSmrt = new Comparable(*smallRT);
            // removePrivate(root, *smallRT, removed);
            // root->item = newSmrt;

            // newSmrt = nullptr;
            // delete newSmrt;

            // smallRT = nullptr;
            // delete smallRT;

            Comparable *smallRT = smallestSubTreePrivate(root->right);
            Comparable *newSmrt = new Comparable(*smallRT);
            removePrivate(root, *smallRT, removed);
            delete root->item;
            root->item = newSmrt;
        }
    }
}

/** smallestSubTreePrivate(Node *node)
 * @brief   iterates to the smallest node in subtree
 * @param   node The node at which the iteration will start
 * @pre     Smallest node comparable is unknown in tree
 * @post    Finds the smallest node and returns the comparable to that ndoe
*/
Comparable *SearchTree::smallestSubTreePrivate(Node *node)
{
    // base case
    if (root == nullptr)
    {
        return nullptr;
    }
    else
    { // continue to move to the left
        if (node->left != nullptr)
        {
            return smallestSubTreePrivate(node->left);
        }
        else
        { // return the smallest item

            return node->item;
        }
    }
}

/** removeChildNodePrivate(Node *nodeP, Node *node, bool left)
 * @brief   Removes a node in which is not a 
 * @param   nodeP The node of the parent node 
 * @param   node The node of that we will be removing from the SearchTree
 * @pre     The node is not removed
 * @post    Finds the child node and removes it from the tree
*/
void SearchTree::removeChildNodePrivate(Node *nodeP, Node *node, bool left)
{
    // deincrement the node
    if (node->count > 1)
    {
        node->count = node->count - 1;
        return;
    }

    bool removed = false;
    Node *ptr;
    Comparable *smallRT;
    //Comparable *item = node->item;

    // no children
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
    } // one child on rhs
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

    } // one child on lhs
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

    } // two children nodes
    else if (node->left != nullptr && node->right != nullptr)
    {
        // cout << "TOMAS IS THE MAN = ";                                     //<< *smallRT << endl;
        // Comparable *smallRT = smallestSubTreePrivate(node->right); // get smallest in right subtree
        // removePrivate(node, *smallRT, removed);
        // node->item = smallRT;
        Comparable *smallRT = smallestSubTreePrivate(node->right);
        Comparable *newSmrt = new Comparable(*smallRT);
        removePrivate(node, *smallRT, removed);

        delete node->item;
        node->item = newSmrt;

        newSmrt = nullptr;
        delete newSmrt;

        smallRT = nullptr;
        delete smallRT;
    }
}
