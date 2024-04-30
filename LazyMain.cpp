//#include <BST.h>
//#include <List.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    string input;
    cout << "Welcome to the method selection menu. Please select an option, or type 'exit' to exit." << endl;
    
    while (input != "exit") {
        cout << "1. Linked List" << endl;
        cout << "2. Binary Search Tree" << endl;
        cin >> input;
        
        if (input == "1" || input == "Linked List") {
            cout << "Entering Linked List Program..." << endl;
            //Call to Linked List main here
            cout << "Linked List process complete. Would you like to make another query?" << endl <<
            "If so, please select an option, or type 'exit' to exit." << endl;
        }
        
        if (input == "2" || input == "Binary Search Tree") {
            cout << "Entering Binary Search Tree Program..." << endl;
            //Call to Binary Search Tree main here
            cout << "Binary Search Tree process complete.  Would you like to make another query?" << endl <<
            "If so, please select an option, or type 'exit' to exit." << endl;
        }
        
        if (input == "exit") {
            cout << "Exiting Program..." << endl;
        }
        
        cin.clear();
        }
    }
}
