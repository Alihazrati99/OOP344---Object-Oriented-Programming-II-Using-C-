## Workshop 6 - College Management System


### Introduction

This workshop focuses on creating a College Management System in C++. The system manages information about persons in a college, including employees, professors, and students. The code includes classes such as `College`, `Person`, `Employee`, `Professor`, and `Student`, each representing different roles within the college. The program reads data from a file, dynamically creates instances of the corresponding classes, and displays information about the persons.

### Files

#### College

- **College.h:** Header file containing the declaration of the `College` class.
- **College.cpp:** Implementation file containing the definition of the `College` class methods.

#### Person

- **Person.h:** Abstract base class representing a person in the college.

#### Employee

- **Employee.h:** Header file containing the declaration of the `Employee` class.
- **Employee.cpp:** Implementation file containing the definition of the `Employee` class methods.

#### Professor

- **Professor.h:** Header file containing the declaration of the `Professor` class.
- **Professor.cpp:** Implementation file containing the definition of the `Professor` class methods.

#### Student

- **Student.h:** Header file containing the declaration of the `Student` class.
- **Student.cpp:** Implementation file containing the definition of the `Student` class methods.

#### Utilities

- **Utilities.h:** Header file containing utility functions used in the program.
- **Utilities.cpp:** Implementation file containing the definition of utility functions.

#### w6_p2.cpp

- Main program file that loads data from a file into the `College` class, displays information about persons, and filters students and professors.

#### college.txt

- Sample data file for persons in the college.

### Compilation and Execution

Compile the program using a C++ compiler:

```bash
g++ College.cpp Person.cpp Employee.cpp Professor.cpp Student.cpp Utilities.cpp w6_p2.cpp -o "Workshop 6"
