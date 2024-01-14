#pragma once

#include <iostream>
#include <string>
#include "Toy.h"

namespace sdds {
	class Child
	{
		std::string m_name;
		size_t m_age;
		const sdds::Toy** m_toysArray;
		size_t m_counter;

		void init();
	public:
                Child(); //default constructor
                ~Child(); // destructor
		Child(std::string name, int age, const Toy* toys[], size_t count);
                size_t size() const; //return m_counter
                Child(const Child&); // copy constructor
		Child& operator=(const Child&);
		Child(Child &&);
		Child& operator=(Child&&);

		friend std::ostream& operator<<(std::ostream&, const Child&);
	};

}
