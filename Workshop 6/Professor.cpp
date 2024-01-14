#include "Professor.h"
#include <iomanip>

namespace sdds {

	Professor::Professor(std::istream& in) : Employee(in)
	{
		std::getline(in, m_department);
		m_department = removeSpaces(m_department);
	}

	void Professor::display(std::ostream& out) const {
		Employee::display(out);
		out << m_department << "| Professor";
	}

	Professor::~Professor()
	{
	}

}