#ifndef BSTree_H
#define BSTree_H

#include "BSTNode.h"

class BSTree
{
    private:
    BSTNode* root;

    public:
    BSTree();
    ~BSTree();
    int BSTHeight(BSTNode* root);
    void BSTInsert(BSTNode* newNode);
    BSTNode* deleteHelper(BSTNode* node, long long int ID);
    void BSTDelete(long long int ID);
    BSTNode* BSTSearchByID(long long int ID);
    void BSTSearchByName(BSTNode* root, std::string name);
    void BSTUpdate(BSTNode* node, std::string newName, std::string newStreet, std::string newCity, std::string newState, std::string newZipCode);

    //Setters
    void setRoot(BSTNode* newRoot);

    //Getters
    BSTNode* getRoot();
};

#endif