#pragma once

#include <iostream>
#include <iomanip>

namespace sdds {
	class FoodOrder
	{
		char m_name[10];
		char *m_description;
		double m_price;
		bool m_dailySpecial;

		void init();
	public:
		//default constructor
		FoodOrder();

		//destructor
		~FoodOrder();

		// read function
		void read(std::istream &input);

		void display();

		FoodOrder(const FoodOrder& input);

		FoodOrder& operator=(const FoodOrder &input);
	};

}