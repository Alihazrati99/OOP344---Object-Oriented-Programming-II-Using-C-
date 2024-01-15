# Workshop 9 - Multi-Threading, Thread Class


## Introduction

This workshop focuses on multi-threading in C++ using the `std::thread` class. The `ProcessData` class is designed to perform computations on data using multiple threads, calculating average and variance factors. The workshop includes the implementation of functions for computing average (`computeAvgFactor`) and variance (`computeVarFactor`), as well as the main class `ProcessData` with multi-threading capabilities.

## Files

### process_data.cpp

- **process_data.cpp:** Implementation file containing the definitions of functions for computing average and variance, as well as the `ProcessData` class.

### process_data.h

- **process_data.h:** Header file containing declarations for functions and the `ProcessData` class.

### w9_p2.cpp

- **w9_p2.cpp:** Main program file demonstrating the usage of the `ProcessData` class.

## Compilation and Execution

Compile the program using a C++ compiler:

```bash
g++ process_data.cpp w9_p2.cpp -o "Workshop 9"
