#include "BSTree.h"
#include <iostream>

BSTree::BSTree()
{
    root = nullptr;    
}

void BSTree::BSTInsert(BSTNode* newNode)
{
    BSTNode* curr = getRoot();
    if(curr == nullptr)
    {
        setRoot(newNode);
    }
    else
    {
        while(newNode->getID() < curr->getID())
        {
            if(curr->getLeft() != nullptr)
            {
                curr = curr->getLeft();
            }
            else
            {
                curr->setLeft(newNode);
            }
        }
        while(newNode->getID() > curr->getID())
        {
            if(curr->getRight() != nullptr)
            {
                curr = curr->getRight();
            }
            else
            {
                curr->setRight(newNode);
            }
        }
    }
}
// void BSTree::BSTDelete(int ID);
BSTNode* BSTree::BSTSearchByID(int ID)
{
    BSTNode* curr = getRoot();
    while(curr != nullptr)
    {
        std::cout << "Student: " << curr->getName() << "\n";
        if(curr->getID() == ID)
        {
            std::cout << "Found student\n";
            return curr;
        }
        else if(ID < curr->getID())
        {
            curr = curr->getLeft();
        }
        else
        {
            curr = curr->getRight();
        }
    }
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