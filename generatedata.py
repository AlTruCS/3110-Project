import csv
from faker import Faker # type: ignore

def generate_students(num_students):
    fake = Faker()
    students = []
    for i in range(1, num_students):
        student = {
            'id': i,
            'name': fake.name(),
            'dob': fake.date_of_birth().isoformat(),
            'street': fake.street_address(),
            'city': fake.city(),
            'state': fake.state_abbr(),
            'zip': fake.zipcode(),
        }
        students.append(student)
    return students

def write_to_csv(data, filename):
    fieldnames = ['id', 'name', 'dob', 'street', 'city', 'state', 'zip']
    with open(filename, 'w', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(data)

if __name__ == '__main__':
    num_students = 100000
    students = generate_students(num_students)
    write_to_csv(students, 'students.csv')
