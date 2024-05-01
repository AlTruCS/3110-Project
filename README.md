# 3110-Project
This program allows for the manipulation of student data from a given repository system, using both a Linked List and Binary Search Tree to organize and locate data.

# Responsibilities
* Alex: Documentation and Time Complexity calculation
* Jason: Linked List
* Michael: Binary Search Tree

#Compilation
This project is set up into two programs that share a CSV file. The Linked List program is entirely contained within `3110FinalLL.cpp`, while the main file for the Binary Search Tree is `testMain.cpp`. To separate the programs, move `3110FinalLL.cpp` into a separate folder, and use your compiler of choice (g++ shown as an example) with the following:

##Linked List
`g++ main.cpp`

##Binary Search Tree
`g++ main.cpp BSTree.cpp BSTNode.cpp`

When running the programs, make sure that they are in separate folders from each other, and have a copy of `students.csv` in the folder of the program being run.

# Functions
At their cores, the Linked List and Binary Search Tree function very similarly in regards to functionality: both structures will use a loop to iterate through themselves, checking each node until one valid for performing the operation has been met. 

However, the primary difference lies in how the correct node is determined. For a linked list, the process is entirely linear, going down the list one at a time until the desired item is found; meanwhile, a Binary Search Tree makes an additional comparison at each layer, cutting the possible remaining nodes to search for in half. Even though the Linked Lists are easier to manage and have more versatility due to not requiring sorting, Linked Lists more than make up for it with their difference in speed.

## Adding a student to the database

### Linked List
To add a student to the database, the Linked List will create a student object using the data provided by the user and place it at the end of the list - if the list is empty, it will assign this value to be the head of the list. By default, it adds all students from the CSV file to the list.

       if (!head) 
        {
            head = newStudent;
        } 
        else 
        {
            Student* current = head;
            while (current->next) 
            {
                current = current->next;
            }
            current->next = newStudent;
        }


### Binary Search Tree
The Binary Search Tree will instead place the provided existing student object to the right of all values it is larger than, and to the left of all values it is smaller than, with the value coming from inputs in the main function.

        if(curr->getRight() == nullptr)
        {
            curr->setRight(newNode);
            return;
        }
            else
            {
                curr = curr->getRight();
            }

### Time Complexities
#### All 100,000 items inserted into list
| Duration | Linked List | BST |
| :------: |:-----------:|:---:|
| Test #1 | 76.7568 | 0.21040 |
| Test #2 | 74.7443 | 0.22488 |
| Test #3 | 72.3781 | 0.22417 |

| O(?)        | Average     | Worst-Case | 
| :---------: |:-----------:|:----------:|
| Linked List | O(N) | O(N) |
| BST | O(log n) | O(N) |

## Deleting a student from the database based upon their ID number

### Linked List
Before starting the loop, the delete function will check to see if the list is either empty or the head is the target for deletion. In the case of the former, it will immediately end the function; in the case of the latter, it will store the current head into a temp node, change the head pointer to the following node, and then delete the original node.

    if (!head) 
        {
            cout << "List is empty." << endl;
            return;
        }

        if (head->id == id) 
        {
            Student* temp = head;
            head = head->next;
            delete temp;
            cout << "Student with ID " << id << " deleted." << endl;
            return;
        }

If neither of these ended the function, it will then iterate through the list with a loop, checking each node's ID value to see if it matches the one supplied by the function; this loop will only end when the ID value is found or the end of the list is reached.

    while (current && current->id != id) 
        {
            prev = current;
            current = current->next;
        }

If the ID number is found, the nodes both before and after it are linked together, with the node being deleted immediately after and the function ending. If the ID number is not found by the end of the function, then the function will terminate on its own.

    if (!current) 
        {
            cout << "Student with ID " << id << " not found." << endl;
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Student with ID " << id << " deleted." << endl;
  
### Binary Search Tree
This system starts with a preliminary function, passing the root node to the primary delete function alongside the ID to search for. 

    void BSTree::BSTDelete(long long int ID)
    {
      deleteHelper(getRoot(), ID);
    }
  
After this, it will continue calling itself recursively, choosing the left node whenever the ID supplied is smaller than the current node's ID value and the right node whenever it is larger. 

    if(ID < node->getID())
    {
        node->setLeft(deleteHelper(node->getLeft(), ID));
    }
    else if(ID > node->getID())
    {
        node->setRight(deleteHelper(node->getRight(), ID));
    }

The function ends whenever the node is found or it reaches a point where there are no valid nodes left to search; in the case of the former, it returns a null pointer. Otherwise, it will start from the left to check for any valid nodes under it, copy them to a temp node, put the data into the position of the original node, and then delete the temp node.

    if(node == nullptr)
    {
        return nullptr;
    }

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

### Time Complexities

#### Deletion of one item
| Duration | Linked List | BST |
| :------: |:-----------:|:---:|
| Test #1 | 0.005922 | 0.000000793 |
| Test #2 | 0.006020 | 0.000001126 |
| Test #3 | 0.003843 | 0.000000980 |

| O(?)        | Average     | Worst-Case | 
| :---------: |:-----------:|:----------:|
| Linked List | O(N) | O(N) |
| BST | O(log N) | O(N) |

## Searching for a student from their ID number

### Linked List
This is handled very simply; a loop will iterate through the list, starting from the head. If the ID number of the node matches the one supplied to the function, it will return a pointer to the current node and end the list; otherwise, it will move to the next. If it is not found by the end of the list, then it will return a null pointer instead.

    while (current) 
        {
            if (current->id == id) 
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;

### Binary Search Tree
Overall, the Binary Search Tree is handled very similarly; however, it will instead check to see if the supplied ID number is equal to, greater than, or lesser than the ID number of the current node. If it is equal, it returns the current node, while moving to the left or right node if it is less or greater than the current node's ID number respectively.
    
    while(curr != nullptr)
    {
        if(curr->getID() == ID)
        {
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

This will continue until the node has been found or there are no valid nodes to search. The current node will be returned if the node has been found, otherwise it will return a null pointer.

### Time Complexities

#### Search for one item
| Duration | Linked List | BST |
| :------: |:-----------:|:---:|
| Test #1 | 0.00589 | 0.000000876 |
| Test #2 | 0.00376 | 0.000000825 |
| Test #3 | 0.00594 | 0.000000793 |

| O(?)        | Average     | Worst-Case | 
| :---------: |:-----------:|:----------:|
| Linked List | O(N) | O(N) |
| BST | O(log N) | O(N) |

## Searching for a student from their name

### Linked List
This function is handled identically to searching based on ID number; the only change made is the type of variable being supplied and searched for.

    while (current)
        {
            if (current->name == name) 
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;

### Binary Search Tree
Similar in a sense to the ID search, this function checks the name within the head node to see if it matches the name supplied to the function. It will then check to see if the left and right nodes are null, and perform the same function on them if so, starting from the right. 

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

This will eventually iterate through the entire list from right to left; if the name is found, the ID number contained within the same node will be displayed. Otherwise, the function will end after all nodes have been visited.

### Time Complexities####

#### Search for one item
| Duration | Linked List | BST |
| :------: |:-----------:|:---:|
| Test #1 | 0.00585 | 0.00859 |
| Test #2 | 0.00621 | 0.00934 |
| Test #3 | 0.00609 | 0.00869 |

| O(?)        | Average     | Worst-Case | 
| :---------: |:-----------:|:----------:|
| Linked List | O(N) | O(N) |
| BST | O(log N) | O(N) |

## Updating and Displaying student records

### Linked List
Updating a student node requires supplying all information relevant to create a student node, starting with the ID number of an existing student. The function will use the search by ID function to find the relevant student object, and then replace all data relating to it with the new data supplied by the function if the ID search was successful.

    Student* student = searchById(id);
        if (student) 
        {
            student->name = newName;
            student->dob = newDob;
            student->street = newStreet;
            student->city = newCity;
            student->state = newState;
            student->zip = newZip;
            cout << "Student with ID " << id << " updated." << endl;
        } 

If the function did not find the ID value in the Linked List, the function ends.

### Binary Search Tree
In the case of the Binary Search Tree, the node is directly supplied to the function for modification in the same way done in the Linked List function. The node is supplied using the Search by ID function.

    void BSTree::BSTUpdate(BSTNode* node, std::string newName, std::string newStreet, std::string newCity,           std::string newState, std::string newZipCode)
    {
      node->setName(newName);
      node->setStreet(newStreet);
      node->setCity(newCity);
      node->setState(newState);
      node->setZipCode(newZipCode);
    }

### Time Complexities

#### Updating one node
| Duration | Linked List | BST |
| :------: |:-----------:|:---:|
| Test #1 | 0.00610 | 0.24084 |
| Test #2 | 0.00602 | 0.21649 |
| Test #3 | 0.00604 | 0.21324 |

| O(?)        | Average     | Worst-Case | 
| :---------: |:-----------:|:----------:|
| Linked List | O(N) | O(N) |
| BST | O(log N) | O(N) |
