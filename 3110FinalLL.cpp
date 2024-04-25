#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Student 
{
    int id;
    string name;
    string dob;
    string street;
    string city;
    string state;
    string zip;
    Student* next;
}; //Student Structure

class StudentList 
{
private:
    Student* head;

public:
    StudentList() : head(nullptr) {}

    ~StudentList() 
    {
        Student* current = head;
        while (current) 
        {
            Student* temp = current;
            current = current->next;
            delete temp;
        }
    } //Destructor

    void addStudent(int id, const string& name, const string& dob, const string& street, const string& city, const string& state, const string& zip) 
    {
        Student* newStudent = new Student;
        newStudent->id = id;
        newStudent->name = name;
        newStudent->dob = dob;
        newStudent->street = street;
        newStudent->city = city;
        newStudent->state = state;
        newStudent->zip = zip;
        newStudent->next = nullptr;
        // Fills values for new student object
        
        if (!head) 
        {
            head = newStudent;
        } //Assigns student to front of list if there are no other students
        else 
        {
            Student* current = head;
            while (current->next) 
            {
                current = current->next;
            } //Loops until finding end of list
            current->next = newStudent;
        } 
    } //Function to add an additional student

    void deleteStudent(int id) 
    {
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
        } //Deletes student at front of list if they are the only one in the list

        Student* prev = nullptr;
        Student* current = head;
        while (current && current->id != id) 
        {
            prev = current;
            current = current->next;
        } //Searches through list until finding the specified ID or end of list

        if (!current) 
        {
            cout << "Student with ID " << id << " not found." << endl;
            return;
        } //Notice if the student ID is not found within the list

        prev->next = current->next;
        delete current;
        cout << "Student with ID " << id << " deleted." << endl;
        //If the ID is found, deletes the matching student
    } //Deletes a student object from a supplied ID number

    Student* searchById(int id) 
    {
        Student* current = head;
        while (current) 
        {
            if (current->id == id) 
            {
                return current;
            } //If the ID is found, returns the student that matches it
            current = current->next;
        } //Loops through list until the student is found or the list ends
        return nullptr;
    } //Searches for a student object by ID number

    Student* searchByName(const string& name) 
    {
        Student* current = head;
        while (current)
        {
            if (current->name == name) 
            {
                return current;
            } //If the name is found, returns the student object
            current = current->next;
        } //Loops through list until the student is found or the list ends
        return nullptr;
    } //Searches for a student object from a supplied name

    void updateStudent(int id, const string& newName, const string& newDob, const string& newStreet, const string& newCity, const string& newState, const string& newZip) 
    {
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
        } //Updates student value with all specified values if the ID is found
        else 
        {
            cout << "Student with ID " << id << " not found." << endl;
        }
    } //Function to update existing student information

    void printStudents() 
    {
        if (!head) 
        {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Student List:" << endl;
        Student* current = head;
        while (current) 
        {
            cout << "ID: " << current->id << ", Name: " << current->name << ", DOB: " << current->dob << ", Address: " << current->street << ", " << current->city << ", " << current->state << ", " << current->zip << endl;
            current = current->next;
        } //Loops through list and prints each student's information
    } //Function to print all student object information

    void readFromCSV(const string& filename) 
    {
        ifstream file(filename);
        if (!file.is_open()) 
    {
        cout << "Error: Unable to open file " << filename << endl;
        return;
    } //Notice for if the file cannot be found

    string line;
    int lineNumber = 0;
    while (getline(file, line)) 
    {
        lineNumber++;
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ',')) 
        {
            tokens.push_back(token);
        } //Adds value to vector of current student information

        if (tokens.size() == 7) 
        {
            int id;
            try 
            {
                id = stoi(tokens[0]);
            } //Converts the first token to an integer and assigns it to the ID value
            catch (const std::invalid_argument& e) 
            {
                continue;
            }

            string name = tokens[1];
            string dob = tokens[2];
            string street = tokens[3];
            string city = tokens[4];
            string state = tokens[5];
            string zip = tokens[6];
            addStudent(id, name, dob, street, city, state, zip);
        } //Once the vector has all values, creates a student variable with all supplied information
        else 
        {
            cout << "Error: Invalid data format on line " << lineNumber << ": " << line << endl;
        }
    } //Loops through each line of file to retrieve student data for each student

    file.close();
} //Function to take data from csv file and convert it into student objects
    
}; //End of student list class

void displayMenu() 
{
    cout << "Menu" << endl;
    cout << "1. Add a student" << endl;
    cout << "2. Delete a student by ID" << endl;
    cout << "3. Search for a student by ID" << endl;
    cout << "4. Search for a student by name" << endl;
    cout << "5. Update student records by ID" << endl;
    cout << "6. Exit" << endl;
}

int main() 
{
    StudentList studentList;

    studentList.readFromCSV("students.csv");

    int choice;
    do 
    {
        displayMenu();

        cout << "Enter your the number corresponding to your desired command: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: 
            {
                int id;
                string name, dob, street, city, state, zip;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter date of birth (YYYY-MM-DD): ";
                getline(cin, dob);
                cout << "Enter street: ";
                getline(cin, street);
                cout << "Enter city: ";
                getline(cin, city);
                cout << "Enter state: ";
                getline(cin, state);
                cout << "Enter ZIP code: ";
                getline(cin, zip);
                studentList.addStudent(id, name, dob, street, city, state, zip);
                break;
            } //Switch case to input information for adding a student
            case 2: 
            {
                int id;
                cout << "Enter ID to delete: ";
                cin >> id;
                studentList.deleteStudent(id);
                break;
            } //Switch case for searching an ID to delete a student
            case 3: 
            {
                int id;
                cout << "Enter student ID to search: ";
                cin >> id;
                Student* student = studentList.searchById(id);
                if (student) 
                {
                    cout << "Student found: " << student->name << endl;
                } 
                else 
                {
                    cout << "Student not found." << endl;
                }
                break;
            } //Switch case for searching for a student ID value
            case 4: 
            {
                string name;
                cout << "Enter student name to search: ";
                cin.ignore(); 
                getline(cin, name);
                Student* student = studentList.searchByName(name);
                if (student) 
                {
                    cout << "Student found: ID: " << student->id << endl;
                } 
                else 
                {
                    cout << "Student not found." << endl;
                }
                break;
            } //Switch case for searching for a student by name
            case 5: 
            {
                int id;
                string newName, newDob, newStreet, newCity, newState, newZip;
                cout << "Enter ID to update: ";
                cin >> id;
                cout << "Enter new name: ";
                cin.ignore(); 
                getline(cin, newName);
                cout << "Enter new date of birth (YYYY-MM-DD): ";
                getline(cin, newDob);
                cout << "Enter new street: ";
                getline(cin, newStreet);
                cout << "Enter new city: ";
                getline(cin, newCity);
                cout << "Enter new state: ";
                getline(cin, newState);
                cout << "Enter new ZIP code: ";
                getline(cin, newZip);
                studentList.updateStudent(id, newName, newDob, newStreet, newCity, newState, newZip);
                break;
            } //Switch case for updating a student's information
            case 6: 
            {
                break;
            } //Switch case to exit program
            default: 
            {
                break;
            }
        }
    } while (choice != 6); //Repeats through menu after a decision is made until program is exited manually

    return 0;
} //Main function
