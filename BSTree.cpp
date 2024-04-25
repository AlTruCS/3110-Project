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
        while(curr != nullptr)
        {
            if(newNode->getID() < curr->getID())
            {
                if(curr->getLeft() == nullptr)
                {
                    curr->setLeft(newNode);
                    return;
                }
                else
                {
                    curr = curr->getLeft();
                }
            }
            else
            {   
                if(curr->getRight() == nullptr)
                {
                    curr->setRight(newNode);
                    return;
                }
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
        if(curr->getID() == ID)
        {
            std::cout << "Found student ID: " << curr->getID() << "\n";
            return curr;
        }
        else if(curr->getID() < ID)
        {
            curr = curr->getRight();
        }
        else if(curr->getID() > ID)
        {
            curr = curr->getLeft();
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
