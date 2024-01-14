#ifndef COLLEGE_H
#define COLLEGE_H

#include <iostream>
#include <vector>
#include <list>
#include "Person.h"

namespace sdds{
class College
{
    std::vector<Person*> m_persons;
public:
    ~College();
	College();

    College(const College&) = delete;
    College& operator=(const College&) = delete;

    College& operator +=(Person* thePerson);
    void display(std::ostream& out) const;

	template <typename T>
	void select(const T& test, std::list<const Person*>& persons) {
		for (auto i : m_persons) {
			if (test(i) && i->name() != "")
				persons.push_back(i);
		}
	}
};

}
#endif // COLLEGE_H
