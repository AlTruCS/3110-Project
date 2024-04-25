#ifndef BSTNode_H
#define BSTNode_H

#include <string>

class BSTNode
{
    private:
    std::string name;
    std::string street;
    std::string city;
    std::string state;
    std::string zipCode;
    int ID;
    BSTNode* left;
    BSTNode* right;

    public:
    BSTNode(std::string newName, std::string newStreet, std::string newCity, std::string newState,  std::string newZipCode, long long int newID, BSTNode* newLeft = nullptr, BSTNode* newRight = nullptr);
    ~BSTNode();

    // Getters
    std::string getName();
    std::string getStreet();
    std::string getCity();
    std::string getState();
    std::string getZipCode();
    long long int getID();
    BSTNode* getLeft();
    BSTNode* getRight();

    //Setters
    void setName(std::string newName);
    void setStreet(std::string newStreet);
    void setCity(std::string newCity);
    void setState(std::string newState);
    void setZipCode(std::string newZipCode);
    void setID(long long int newID);
    void setLeft(BSTNode* newLeft);
    void setRight(BSTNode* newRight);
};

#endif