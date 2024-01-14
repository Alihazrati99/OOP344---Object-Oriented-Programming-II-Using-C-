#include "College.h"
#include <iomanip>

namespace sdds {
	College::~College()
	{
		for (auto p : m_persons) {
			delete p;
		}
	}
	College::College()
	{
	}

	College& College::operator +=(Person* thePerson) {
		m_persons.push_back(thePerson);

		return *this;
	}

	void College::display(std::ostream& out) const {
		out << "------------------------------------------------------------------------------------------------------------------------\n";
		out << "|                                        Test #1 Persons in the college!                                               |\n";
		out << "------------------------------------------------------------------------------------------------------------------------\n";
		for (auto p : m_persons) {
			if (p->name() != "") {
				p->display(out);
				out << std::endl;
			}
		}
	    out << "------------------------------------------------------------------------------------------------------------------------\n";
		out << "|                                        Test #2 Persons in the college!                                               |\n";
		out << "------------------------------------------------------------------------------------------------------------------------\n";
		for (auto p : m_persons) {
			if (p->id() == "")
				continue;
			out << "| " << std::left << std::setw(10) << p->status();
			out << "| " << std::left << std::setw(10) << p->id();
			out << "| " << std::left << std::setw(20) << p->name();
			out << " | " << std::left << std::setw(3) << p->age() << " |\n";
		}
		out << "------------------------------------------------------------------------------------------------------------------------\n";
	}

}
