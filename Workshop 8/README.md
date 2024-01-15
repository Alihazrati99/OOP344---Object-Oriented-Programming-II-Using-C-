# Workshop 8 - Database Management System


## Introduction

This workshop introduces a Database Management System implemented in C++. The system is designed to manage a database of key-value pairs, where keys are strings and values can be either strings or long long integers. The system provides functionality to retrieve and update values, as well as encryption and decryption for security purposes.

## Files

### Database

- **Database.h:** Header file containing the declaration of the `Database` template class with specializations for `std::string` and `long long` types.
- **Database.cpp:** Empty implementation file for the `Database` class.

### w8_p2.cpp

- **w8_p2.cpp:** Main program file demonstrating the usage of the `Database` class. It includes tests for singleton behavior, content retrieval and modification for string and numeric databases, and a utility function to dump file content in hexadecimal.

### data_str.txt

- Sample data file for the string database.

### data_num.txt

- Sample data file for the numeric database.

## Compilation and Execution

Compile the program using a C++ compiler:

```bash
g++ Database.cpp w8_p2.cpp -o "Workshop 8"
