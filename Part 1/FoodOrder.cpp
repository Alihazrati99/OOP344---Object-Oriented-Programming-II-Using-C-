#include "FoodOrder.h"

double g_taxrate, g_dailydiscount;

namespace sdds {

	FoodOrder::FoodOrder(){
		init();
	}


	FoodOrder::~FoodOrder(){
	}

	// safe state
	void FoodOrder::init() {
		m_name[0] = 0;
		m_description[0] = 0;
		m_price = 0;
		m_dailySpecial = false;
	}

	void FoodOrder::read(std::istream &input) {
		if (input.good()) {
			//<Customer Name>,<Order Description>,<Price>,<Daily Special Status>[newline]
			input.getline(m_name, 10, ',');
			// get description
			input.getline(m_description, 25, ',');
			input >> m_price;
			input.ignore(1024, ',');
			// get daily special
			char daily;
			daily = input.get();
			if (daily == 'Y')
				m_dailySpecial = true;
			else
				m_dailySpecial = false;
			input.ignore(1024, '\n');
		}
	}

	void FoodOrder::display() {
		static int counter = 1;
		// print counter
		std::cout << std::left << std::setw(2) << counter++ << ". ";
		if (m_name[0] != 0) {
			// print name
			std::cout << std::left << std::setw(10) << m_name << "|";
			// print description
			std::cout << std::left << std::setw(25) << m_description << "|";
			// print price
			std::cout << std::fixed << std::setprecision(2) << std::left << std::setw(12);
			std::cout << m_price + m_price * g_taxrate << "|";
			// print daily special price
			if (m_dailySpecial) {
				std::cout <<std::right<<std::setw(13)<< m_price + m_price * g_taxrate - g_dailydiscount;
			}
		}
		else
			std::cout << "No Order";
		std::cout << "\n";
	}
}