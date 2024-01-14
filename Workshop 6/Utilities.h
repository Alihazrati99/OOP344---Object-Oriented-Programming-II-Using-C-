#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include "Person.h"
#include "Employee.h"
#include "Professor.h"
#include "Student.h"

namespace  sdds {


	std::string removeSpaces(std::string input);

	Person* buildInstance(std::istream& in);


}
#endif // UTILITIES_H
