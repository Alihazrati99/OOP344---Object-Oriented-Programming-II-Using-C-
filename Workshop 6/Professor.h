#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include <string>
#include "Employee.h"

namespace sdds {
	class Professor : public Employee
	{
		std::string m_department;
	public:
		Professor(std::istream& in);
		void display(std::ostream& out) const;
		std::string status() const { return "Professor"; }
		std::string department() const { return m_department; }

		~Professor();
	};

}
#endif // PROFESSOR_H
