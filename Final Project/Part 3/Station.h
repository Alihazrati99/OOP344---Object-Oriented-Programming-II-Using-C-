#pragma once

#include <iomanip>
#include <string>
#include <iostream>
#include "Utilities.h"

namespace sdds {

	class Station
	{
		int m_stationId;
		std::string m_itemName;
		std::string m_stationDescription;
		size_t m_nextSerial;
		size_t m_numberOfItems;

		static size_t m_widthField;
		static size_t id_generator;
		
	public:
		Station(const std::string input);
		void safeState();

		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};

}