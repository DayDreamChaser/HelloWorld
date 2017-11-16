import csv
from student import Student

# Space for students
students = []

# Prompt for students' names and dorms
for i in range(3):
    name = input("name: ")
    dorm = input("dorm: ")
    s = (Student(name, dorm))
    students.append(s)
"""
with open("students.csv", "w") as file:
    writer = csv.writer(file)
    for student in students:
        writer.writerow((student.name, student.dorm))
"""
for student in students:
    print("{0} in {1}".format(student.name, student.dorm))
    
def name