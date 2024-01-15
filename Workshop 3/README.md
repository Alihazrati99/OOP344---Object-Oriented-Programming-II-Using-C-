# Workshop 3 - Templates and Specializations

## Introduction

This workshop explores the use of templates and specializations in C++. It introduces the `Collection`, `Pair`, and `Set` classes, which demonstrate template usage and specialization.

## Files

### Collection

- **Collection.h:** Template class for managing a collection of elements.
- **Pair.h:** Template class representing a pair of key and value.
- **Pair.cpp:** Implementation file for the `Pair` class.

### Set

- **Set.h:** Template class that specializes the `Collection` for managing a set of elements.
- **main.cpp:** Main file demonstrating the use of templates and specializations.

## Compilation and Execution

Compile the program using a C++ compiler:

```bash
g++ Pair.cpp Collection.cpp Set.cpp main.cpp -o "Workshop 3"
