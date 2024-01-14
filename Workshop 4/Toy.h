#pragma once

#include <iostream>
#include <string>

namespace sdds {
	class Toy
	{
		size_t m_orderID;
		std::string m_name;
		size_t m_numberOfItems;
		double m_price;
		double m_HST;

                void init(); // empty state
                std::string removeSpaces(std::string); // remove unneeded spaces
	public:
                Toy();// constructor
		~Toy();

                void update(int numItems);// update number of items
		Toy(const std::string& toy);

		friend std::ostream& operator<<(std::ostream&, const Toy&);
	};

}
