#include "Toy.h"

#include <algorithm>
#include <iomanip>

namespace sdds {

	Toy::Toy()
	{
                init();// empty state
	}


	Toy::~Toy()
	{
	}

	void Toy::init() 
	{
		m_orderID = 0;
		m_name = "";
		m_numberOfItems = 0;
		m_price = 0;
		m_HST = 13;
	}

	void Toy::update(int numItems) {
		m_numberOfItems = numItems;
	}

	Toy::Toy(const std::string& toy) {
		init();
		//ID:NAME:NUM:PRICE
		std::string tmp = toy;
		int pos = tmp.find(':');
                m_orderID = std::stoi(removeSpaces(tmp.substr(0,pos))); //read order ID
		tmp = tmp.substr(pos + 1);

		pos = tmp.find(':');
                m_name = removeSpaces(tmp.substr(0, pos)); // read name
		tmp = tmp.substr(pos + 1);

		pos = tmp.find(':');
                m_numberOfItems = std::stoi(removeSpaces(tmp.substr(0, pos))); // read number if items
		tmp = tmp.substr(pos + 1);

                m_price = std::stod(removeSpaces(tmp)); // read price
	}

	std::string Toy::removeSpaces(std::string input) {
                // remove extra spaces from start
		while (input[0] == ' ')
			input = input.substr(1, input.length() - 1);

                // remove extra spaces from end
		while (input[input.length() - 1] == ' ')
			input = input.substr(0, input.length() - 1);

		return input;
	}

	std::ostream& operator<<(std::ostream& out, const Toy& toy) {
		
		out << "Toy";
		out << std::setw(8) << toy.m_orderID<<":";
		out << std::right << std::setw(18) << toy.m_name;
		out << std::setw(3) << toy.m_numberOfItems;
		out << " items" << std::fixed << std::setprecision(2)<<std::setw(8) << toy.m_price << "/item  subtotal:";
		out << std::setw(7) << toy.m_price* toy.m_numberOfItems;
		double tax = (toy.m_HST*toy.m_price* toy.m_numberOfItems / 100);
		out << " tax:" << std::setw(6) << tax;
		out << " total:" << std::setw(7) << toy.m_price* toy.m_numberOfItems + tax<<std::endl;


		return out;
	}
}
