# 3110-Project
This program allows for the manipulation of student data from a given repository system, using both a Linked List and Binary Search Tree to organize and locate data.

# Functions
At their cores, the Linked List and Binary Search Tree function very similarly in regards to functionality: both structures will use a loop to iterate through themselves, checking each node until one valid for performing the operation has been met. However, the primary difference lies in how the correct node is determined.


## Adding a student to the database

### Linked List
To add a student to the database, the Linked List will create a student object using the data provided by the user and place it at the end of the list - if the list is empty, it will assign this value to be the head of the list. By default, it adds all students from the CSV file to the list.

### Binary Search Tree
The Binary Search Tree will instead place the provided existing student object to the right of all values it is larger than, and to the left of all values it is smaller than, with the value coming from inputs in the main function.

| Duration | Linked List | BST |
| :------: |:-----------:|:---:|
| Test #1 | 0:00.00 | 0:00.00 |
| Test #2 | 0:00.00 | 0:00.00 |
| Test #3 | 0:00.00 | 0:00.00 |

## Deleting a student from the database based upon their ID number

### Linked List
Before starting the loop, the delete function will check to see if the list is either empty or the head is the target for deletion. In the case of the former, it will immediately end the function; in the case of the latter, it will store the current head into a temp node, change the head pointer to the following node, and then delete the original node.

If neither of these ended the function, it will then iterate through the list with a loop, checking each node's ID value to see if it matches the one supplied by the function; this loop will only end when the ID value is found or the end of the list is reached.

If the ID number is found, the nodes both before and after it are linked together, with the node being deleted immediately after and the function ending. If the ID number is not found by the end of the function, then the function will terminate on its own.

### Binary Search Tree
This system starts with a preliminary function, passing the root node to the primary delete function alongside the ID to search for. 

After this, it will continue calling itself recursively, choosing the left node whenever the ID supplied is smaller than the current node's ID value and the right node whenever it is larger. 

The function ends whenever the node is found or it reaches a point where there are no valid nodes left to search; in the case of the former, it returns a null pointer. Otherwise, it will start from the left to check for any valid nodes under it, copy them to a temp node, put the data into the position of the original node, and then delete the temp node.

## Searching for a student from their ID number

### Linked List
This is handled very simply; a loop will iterate through the list, starting from the head. If the ID number of the node matches the one supplied to the function, it will return a pointer to the current node and end the list; otherwise, it will move to the next. If it is not found by the end of the list, then it will return a null pointer instead.

### Binary Search Tree
Overall, the Binary Search Tree is handled very similarly; however, it will instead check to see if the supplied ID number is equal to, greater than, or lesser than the ID number of the current node. If it is equal, it returns the current node, while moving to the left or right node if it is less or greater than the current node's ID number respectively.

This will continue until the node has been found or there are no valid nodes to search. The current node will be returned if the node has been found, otherwise it will return a null pointer.

## Searching for a student from their name

### Linked List
This function is handled identically to searching based on ID number; the only change made is the type of variable being supplied and searched for.

### Binary Search Tree
Similar in a sense to the ID search, this function checks the name within the head node to see if it matches the name supplied to the function. It will then check to see if the left and right nodes are null, and perform the same function on them if so, starting from the right. 

This will eventually iterate through the entire list from right to left; if the name is found, the ID number contained within the same node will be displayed. Otherwise, the function will end after all nodes have been visited.

## Updating and Displaying student records

### Linked List
Updating a student node requires supplying all information relevant to create a student node, starting with the ID number of an existing student. The function will use the search by ID function to find the relevant student object, and then replace all data relating to it with the new data supplied by the function if the ID search was successful.

If the function did not find the ID value in the Linked List, the function ends.

### Binary Search Tree
In the case of the Binary Search Tree, the node is directly supplied to the function for modification in the same way done in the Linked List function. The node is supplied using the Search by ID function.
