#include "Station.h"


namespace sdds {
	size_t Station::m_widthField;
	size_t Station::id_generator;

	Station::Station(const std::string input){
		// safe state
		safeState();

		static size_t stationID = 1;
		Utilities utilities;
		bool more = true;
		size_t nextPos = 0;
		// get itemName
		m_itemName = utilities.extractToken(input, nextPos, more);
		// get nextSerial
		m_nextSerial = std::stoi(utilities.extractToken(input, nextPos, more));
		// get number of items
		m_numberOfItems = std::stoi(utilities.extractToken(input, nextPos, more));

		if (utilities.getFieldWidth() > m_widthField)
			m_widthField = utilities.getFieldWidth();

		m_stationDescription = utilities.extractToken(input, nextPos, more);

		m_stationId = stationID;
		stationID++;
	}

	const std::string& Station::getItemName() const {
		return m_itemName;
	}

	void Station::updateQuantity() {
		if (m_numberOfItems > 0)
			m_numberOfItems--;
	}
	

	size_t Station::getQuantity() const {
		return m_numberOfItems;
	}

	size_t Station::getNextSerialNumber() {
		m_nextSerial++;
		return m_nextSerial;
	}

	void Station::display(std::ostream& os, bool full) const {
		os << std::setw(3) << std::setfill('0') << std::right << m_stationId << " | ";
		os << std::setw(m_widthField) << std::setfill(' ') << std::left << m_itemName << "  | ";
		os << std::setw(6) << std::setfill('0') << std::right  << m_nextSerial<<" | ";

		if (full) {
			os << std::setw(4) << std::setfill(' ') << std::right<<  m_numberOfItems << " | ";
			os <<  m_stationDescription;
		}
		os << std::endl;
	}


	void Station::safeState() {
		m_nextSerial = m_numberOfItems = 0;
	}
}