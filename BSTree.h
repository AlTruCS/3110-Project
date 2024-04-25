#ifndef BSTree_H
#define BSTree_H

#include "BSTNode.h"

class BSTree
{
    private:
    BSTNode* root;

    public:
    BSTree();
    // ~BSTree();
    int BSTHeight(BSTNode* root);
    void BSTInsert(BSTNode* newNode);
    void BSTDelete(long long int ID);
    BSTNode* BSTSearchByID(long long int ID);
    void BSTSearchByName(std::string name);
    void BSTUpdate(BSTNode* Node);

    //Setters
    void setRoot(BSTNode* newRoot);

    //Getters
    BSTNode* getRoot();
};

#endif