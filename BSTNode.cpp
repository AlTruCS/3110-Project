#include "BSTNode.h"


BSTNode::BSTNode(std::string newName, std::string newStreet, std::string newCity, std::string newState, std::string newZipCode, long long int newID, BSTNode* newLeft, BSTNode* newRight)
{
    name = newName;
    street = newStreet;
    city = newCity;
    zipCode = newZipCode;
    state = newState;
    ID = newID;
    left = newLeft;
    right = newRight;
}

// Getters
std::string BSTNode::getName()
{
    return name;
}
std::string BSTNode::getStreet()
{
    return street;
}
std::string BSTNode::getCity()
{
    return city;
}
std::string BSTNode::getState()
{
    return state;
}
std::string BSTNode::getZipCode()
{
    return zipCode;
}
long long int BSTNode::getID()
{
    return ID;
}
BSTNode* BSTNode::getLeft()
{
    return left;
}
BSTNode* BSTNode::getRight()
{
    return right;
}

//Setters
void BSTNode::setName(std::string newName)
{
    name = newName;
}
void BSTNode::setStreet(std::string newStreet)
{
    street = newStreet;
}
void BSTNode::setCity(std::string newCity)
{
    city = newCity;
}
void BSTNode::setZipCode(std::string newZipCode)
{
    zipCode = newZipCode;
}
void BSTNode::setID(long long int newID)
{
    ID = newID;
}
void BSTNode::setLeft(BSTNode* newLeft)
{
    left = newLeft;
}
void BSTNode::setRight(BSTNode* newRight)
{
    right = newRight;
}
