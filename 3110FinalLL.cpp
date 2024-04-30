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
};

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
    }

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
    }

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
        }

        Student* prev = nullptr;
        Student* current = head;
        while (current && current->id != id) 
        {
            prev = current;
            current = current->next;
        }

        if (!current) 
        {
            cout << "Student with ID " << id << " not found." << endl;
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Student with ID " << id << " deleted." << endl;
    }

    Student* searchById(int id) 
    {
        Student* current = head;
        while (current) 
        {
            if (current->id == id) 
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    Student* searchByName(const string& name) 
    {
        Student* current = head;
        while (current)
        {
            if (current->name == name) 
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

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
        } 
        else 
        {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

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
        }
    }

    void readFromCSV(const string& filename) 
    {
        ifstream file(filename);
        if (!file.is_open()) 
    {
        cout << "Error: Unable to open file " << filename << endl;
        return;
    }

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
        }

        if (tokens.size() == 7) 
        {
            int id;
            try 
            {
                id = stoi(tokens[0]);
            } 
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
        } 
        else 
        {
            cout << "Error: Invalid data format on line " << lineNumber << ": " << line << endl;
        }
    }

    file.close();
    }
    
};

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
            }
            case 2: 
            {
                int id;
                cout << "Enter ID to delete: ";
                cin >> id;
                studentList.deleteStudent(id);
                break;
            }
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
            }
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
            }
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
            }
            case 6: 
            {
                break;
            }
            default: 
            {
                break;
            }
        }
    } while (choice != 6);

    return 0;
}