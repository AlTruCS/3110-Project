#include "BSTree.h"
#include <iostream>

//Constructor
BSTree::BSTree()
{
    root = nullptr;    
}

void BSTree::BSTInsert(BSTNode* newNode)
{
    BSTNode* curr = getRoot();
    //Sets the root of tree to the current value if tree is currently empty
    if(curr == nullptr)
    {
        setRoot(newNode);
    }
    else
    {
        while(curr != nullptr)
        {
            if(newNode->getID() < curr->getID())
            {
                // If the left child of the tree is empty, newNode is now left node
                if(curr->getLeft() == nullptr)
                {
                    curr->setLeft(newNode);
                    return;
                }
                // Else move to left node
                else
                {
                    curr = curr->getLeft();
                }
            }
            else
            {   
                // If the lright child of the tree is empty, newNode is now right node
                if(curr->getRight() == nullptr)
                {
                    curr->setRight(newNode);
                    return;
                }
                // Else move to right node
                else
                {
                    curr = curr->getRight();
                }
            }
        }
    }
}
// void BSTree::BSTDelete(int ID);
BSTNode* BSTree::BSTSearchByID(long long int ID)
{
    BSTNode* curr = getRoot();
    while(curr != nullptr)
    {
        std::cout << "Student: " << curr->getName() << "\n";
        std::cout << "Found student ID: " << curr->getID() << "\n";
        //If value is equal to current node, return the node
        if(curr->getID() == ID)
        {
            // std::cout << "Found student ID: " << curr->getID() << "\n";
            return curr;
        }
        //If value is smaller than current node, move to left subtree
        else if(curr->getID() < ID)
        {
            curr = curr->getRight();
        }
        //If value is larger than current node, move to right subtree
        else if(curr->getID() > ID)
        {
            curr = curr->getLeft();
        }
    }
    // If curr node is nullptr return it so we can see that there is no student with that ID in the tree.
    return curr;
}
// void BSTree::BSTSearchByName(std::string name);
// void BSTree::BSTUpdate(BSTNode* Node);

//Setters
void BSTree::setRoot(BSTNode* newRoot)
{
    root = newRoot;
}

//Getters
BSTNode* BSTree::getRoot()
{
    return root;
}

int BSTree::BSTHeight(BSTNode* root)
{
    if(root == nullptr)
    {
        return -1;
    }
    return 1 + std::max(BSTHeight(root->getLeft()),BSTHeight(root->getRight()));
}