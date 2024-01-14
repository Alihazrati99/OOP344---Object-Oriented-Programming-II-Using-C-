#include "Employee.h"

#include <iomanip>

namespace sdds {
	Employee::Employee(std::istream &stream) {
		std::string tmp;

		std::getline(stream, m_name,',');
		m_name = removeSpaces(m_name);
		std::getline(stream, m_age, ',');
		m_age = removeSpaces(m_age);
		
		char c;
		stream.get(c);
		while (c != '\n' && c != ',') {
			m_id += c;
			stream.get(c);
		}
		m_id = removeSpaces(m_id);
		if (m_id[0] != 'E') {
			std::cout << m_name << "++Invalid record!\n";
			m_name = m_age = m_id = "";
		}
		//std::getline(stream, m_id);
	}

	std::string Employee::removeSpaces(std::string input) {
		// clean extra spaces from start
		while (input[0] == ' ')
			input = input.substr(1, input.length() - 1);

		// clean extra spaces from end
		while (input[input.length() - 1] == ' ')
			input = input.substr(0, input.length() - 1);

		return input;
	}

	void Employee::display(std::ostream& out) const {
		out << "| " << std::left << std::setw(10) << "Employee";
		out << "| " << std::left << std::setw(10) << m_id;
		out << "| " << std::left << std::setw(20) << m_name;
		out << " | " << std::left << std::setw(3) << m_age << " |";
	}
}

