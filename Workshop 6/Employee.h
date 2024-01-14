#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "Person.h"

namespace sdds {

class Employee : public Person
{
    std::string m_name;
    std::string m_age;
    std::string m_id;

    
public:
	std::string removeSpaces(std::string input);
    Employee(std::istream &);

    std::string status() const{return "Employee";}
    std::string name() const { return m_name;}
    std::string id() const { return m_id;}
    std::string age() const { return m_age;}
    void display(std::ostream& out) const;
};

}
#endif // EMPLOYEE_H
