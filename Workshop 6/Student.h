#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Person.h"

namespace sdds {
	class Student : public Person
	{
		std::string m_name;
		std::string m_age;
		std::string m_id;
		std::string *m_courses;
		size_t m_count;
		std::string removeSpaces(std::string input);
		bool isNumber(const std::string& s);
	public:
		Student(std::istream &);
		~Student();

		std::string status() const { return "Student"; }
		std::string name() const { return m_name; }
		std::string id() const { return m_id; }
		std::string age() const { return m_age; }
		void display(std::ostream& out) const;
	};

}
#endif // STUDENT_H