#include "BSTree.h"
#include <iostream>

//Constructor
BSTree::BSTree()
{
    root = nullptr;    
}

BSTree::~BSTree()
{

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

BSTNode* BSTree::deleteHelper(BSTNode* node, long long int ID)
{
    if(node == nullptr)
    {
        return nullptr;
    }
    if(ID < node->getID())
    {
        node->setLeft(deleteHelper(node->getLeft(), ID));
    }
    else if(ID > node->getID())
    {
        node->setRight(deleteHelper(node->getRight(), ID));
    }
    else
    {
        std::cout << "Student found: \n" << "Student Name: " << node->getName() << "\nStudent ID: " << node->getID() << "\n Deleteing...\n";
        if(node->getLeft() == nullptr)
        {
            BSTNode* temp = node->getRight();
            delete node;
            return temp;
        }
        else if (node->getRight() == nullptr) 
        {
        BSTNode* temp = node->getLeft();
        delete node;
        return temp;
        }

        BSTNode* temp = node->getRight();
        while(temp->getLeft() != nullptr)
        {
            temp = temp->getLeft();
        }

        node->setID(temp->getID());
        node->setName(temp->getName());
        node->setStreet(temp->getStreet());
        node->setCity(temp->getCity());
        node->setZipCode(temp->getZipCode());
        node->setState(temp->getState()); 

        node->setRight(deleteHelper(node->getRight(), temp->getID()));
    }
    return node;
}

void BSTree::BSTDelete(long long int ID)
{
    deleteHelper(getRoot(), ID);
}

BSTNode* BSTree::BSTSearchByID(long long int ID)
{
    BSTNode* curr = getRoot();
    while(curr != nullptr)
    {
        // std::cout << "Student: " << curr->getName() << "\n";
        // std::cout << "Found student ID: " << curr->getID() << "\n";
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

void BSTree::BSTSearchByName(BSTNode* node, std::string name)
{
    if(node->getName() == name)
    {
        std::cout << "Student Name Found\nStudent ID:" << node->getID() << "\n";
    }
    if(node->getRight() != nullptr)
    {
        BSTSearchByName(node->getRight(), name);
    }
    if(node->getLeft() != nullptr)
    {
        BSTSearchByName(node->getLeft(), name);
    }
}

void BSTree::BSTUpdate(BSTNode* node, std::string newName, std::string newStreet, std::string newCity, std::string newState, std::string newZipCode)
{
    node->setName(newName);
    node->setStreet(newStreet);
    node->setCity(newCity);
    node->setState(newState);
    node->setZipCode(newZipCode);
}

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