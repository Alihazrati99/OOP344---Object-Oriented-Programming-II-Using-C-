#include "FoodOrder.h"
#include <string>

double g_taxrate, g_dailydiscount;

namespace sdds {

	FoodOrder::FoodOrder(){
		init();
	}


	FoodOrder::~FoodOrder(){
		delete[]m_description;
	}

	// safe state
	void FoodOrder::init() {
		m_name[0] = 0;
		m_description = nullptr;
		m_price = 0;
		m_dailySpecial = false;
	}

	void FoodOrder::read(std::istream &input) {
		if (input.good()) {
			//<Customer Name>,<Order Description>,<Price>,<Daily Special Status>[newline]
			input.getline(m_name, 10, ',');
			// get description
			std::string tmp;
			getline(input, tmp, ',');
			delete []m_description;
			m_description = new char[tmp.length() + 1];
			memcpy(m_description, tmp.c_str(), tmp.length());
			m_description[tmp.length()] = '\0';

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

	// copy constructor
	FoodOrder::FoodOrder(const FoodOrder& input) {
		init();
		// use copy assignment operator
		(*this) = input;
	}

	FoodOrder& FoodOrder::operator=(const FoodOrder &input) {
		if (this != &input) {
			// delete previus memory
			delete []m_description;
			init();
			memcpy(m_name, input.m_name,strlen(input.m_name));
			m_name[strlen(input.m_name)] = '\0';

			m_description = new char[strlen(input.m_description) + 1];
			memcpy(m_description, input.m_description, strlen(input.m_description));
			m_description[strlen(input.m_description)] = '\0';

			m_price = input.m_price;
			m_dailySpecial = input.m_dailySpecial;
		}

		return *this;
	}
}