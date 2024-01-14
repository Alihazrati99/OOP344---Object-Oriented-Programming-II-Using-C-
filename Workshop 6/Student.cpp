#include "Student.h"
#include <iomanip>
#include <cctype>
namespace sdds {

	Student::Student(std::istream &stream) {
		m_courses = nullptr;
		m_count = 0;

		//NAME, AGE, STUDENT ID, NUMBER_OF_COURSES, LIST_OF_COURSES
		std::getline(stream, m_name, ',');
		m_name = removeSpaces(m_name);
		std::getline(stream, m_age, ',');
		m_age = removeSpaces(m_age);
		if(!isNumber(m_age)){
			std::cout << m_name << "++Invalid record!\n";
			m_name = m_age = m_id = "";
			return;
		}
		char c;
		stream.get(c);
		while (true) {
			if (c == '\n') {
				m_id = removeSpaces(m_id);
				return;
			}
			else if (c == ',')
				break;
			m_id += c;
			stream.get(c);
		}

		m_id = removeSpaces(m_id);
		if (m_id[0] != 'S') {
			std::cout << m_name << "++Invalid record!\n";
			m_name = m_age = m_id = "";
			return;
		}

		std::string tmp;
		std::getline(stream, tmp, ',');
		m_count = stoi(tmp);

		m_courses = new std::string[m_count];
		for (size_t i = 0; i < m_count - 1; i++) {
			std::getline(stream, m_courses[i], ',');
			m_courses[i] = removeSpaces(m_courses[i]);
		}
		std::getline(stream, m_courses[m_count - 1]);
		m_courses[m_count - 1] = removeSpaces(m_courses[m_count - 1]);
	}

	bool Student::isNumber(const std::string& s)
	{
		for (char const &ch : s) {
			if (std::isdigit(ch) == 0)
				return false;
		}
		return true;
	}

	std::string Student::removeSpaces(std::string input) {
		// clean extra spaces from start
		while (input[0] == ' ')
			input = input.substr(1, input.length() - 1);

		// clean extra spaces from end
		while (input[input.length() - 1] == ' ')
			input = input.substr(0, input.length() - 1);

		return input;
	}

	void Student::display(std::ostream& out) const {
		out << "| " << std::left << std::setw(10) << "Student";
		out << "| " << std::left << std::setw(10) << m_id;
		out << "| " << std::left << std::setw(20) << m_name;
		out << " | " << std::left << std::setw(3) << m_age << " |";
		for (size_t i = 0; i < m_count; i++) {
			if (i)
				out << ", ";
			out << m_courses[i];
		}
	}

	Student::~Student()
	{
		if (m_courses != nullptr)
			delete[]m_courses;
	}
}