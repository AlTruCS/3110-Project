#include "BSTree.h"
#include <iostream>

BSTree::BSTree()
{
    root = nullptr;    
} //Constructor

void BSTree::BSTInsert(BSTNode* newNode)
{
    BSTNode* curr = getRoot();
    if(curr == nullptr)
    {
        setRoot(newNode);
    } //Sets the root of tree to the current value if tree is currently empty
    else
    {
        while(newNode->getID() < curr->getID())
        {
            if(curr->getLeft() != nullptr)
            {
                curr = curr->getLeft();
            } //If the left child of the tree is not empty, move to left subtree
            else
            {
                curr->setLeft(newNode);
            } //Sets node to the left subtree of existing node
        } //If the new node is smaller than the existing node, put it to the left
        while(newNode->getID() > curr->getID())
        {
            if(curr->getRight() != nullptr)
            {
                curr = curr->getRight();
            } //If the right child of the tree is not empty, move to right subtree
            else
            {
                curr->setRight(newNode);
            } //Sets node to the right subtree of existing node
        } //If the new node is larger than the existing node, put it to the right
    } //Function to locate necessary position within tree 
} //Function to insert node into BST Tree
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
        } //If value is equal to current node, return the node
        else if(ID < curr->getID())
        {
            curr = curr->getLeft();
        } //If value is smaller than current node, move to left subtree
        else
        {
            curr = curr->getRight();
        } //If value is larger than current node, move to right subtree
    } //Loops through tree until node is found
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
    } //If tree is empty, return null value
    return 1 + std::max(BSTHeight(root->getLeft()),BSTHeight(root->getRight()));
}
