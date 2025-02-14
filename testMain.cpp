#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include "BSTree.h"



int main()
{
    std::cout << "Welcome to CSCE3110 Group Project BST Example...\n";
    std::ifstream inputFile;
    std::string tempData;
    long long int id;
    std::string name;
    std::string dob;
    std::string street;
    std::string city;
    std::string state;
    std::string zip;
    std::string tempString;
    BSTree BST;
    BSTNode* student;

    inputFile.open("students.csv");
    while(getline(inputFile, tempData))
    {
        // std::cout << "tempData: " << tempData << "\n";
        std::stringstream inputString(tempData);

        std::getline(inputString, tempString, ',');
        id = atoi(tempString.c_str());
        std::getline(inputString, name, ',');
        std::getline(inputString, dob, ',');
        std::getline(inputString, street, ',');
        std::getline(inputString, city, ',');
        std::getline(inputString, state, ',');
        std::getline(inputString, zip, ',');
        std::getline(inputString, tempString, '\n'); // Just to get passed the break
        BST.BSTInsert(new BSTNode(name, street, city, state, zip, id));
    } //Loops through file to insert student data into BST
    

    std::cout << "COMPLETE!\n";
    student = BST.BSTSearchByID(964024);
    if(student == nullptr)
    {
        std::cout << "SEARCH BY ID: FAILED\n"; 
    }
    else
    {
        std::cout << "SEARCH BY ID: " << student->getName() << "\nStudent ID: " << student->getID() << "\n";
    }
    // BST.BSTDelete(964024);
    // std::cout << "SEARCH BY ID: " << student->getID() << " Name: " << student->getName() <<  "\n";
    BST.BSTUpdate(BST.BSTSearchByID(964024), "TEST", "TEST", "TEST", "TEST", "TEST");
    BST.BSTSearchByName(BST.getRoot(), "TEST");
    sleep(1);


    return 0;
}
