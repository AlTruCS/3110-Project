import csv
import random
from faker import Faker  # type: ignore

def generate_students(num_students):
    fake = Faker()
    students = []
    for i in range(num_students):
        student = {
            'id': random.randint(1, 1000000),
            'name': fake.name(),
            'dob': fake.date_of_birth().isoformat(),
            'street': fake.street_address(),
            'city': fake.city(),
            'state': fake.state_abbr(),
            'zip': fake.zipcode(),
        } #Generates values for each variable in student object
        students.append(student) #Adds value to end of current list
    return students
    #Function to generate list of student values based upon the requested number of students

def write_to_csv(data, filename):
    fieldnames = ['id', 'name', 'dob', 'street', 'city', 'state', 'zip']
    with open(filename, 'w', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(data)
        #Function to write values to CSV

if __name__ == '__main__':
    num_students = 100000
    students = generate_students(num_students)
    write_to_csv(students, 'students.csv')
