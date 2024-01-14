#include "Pair.h"

#include <iomanip>

namespace sdds {

	bool Pair::operator==(const Pair& input) {
		// two Pair objects are equal if their key is same
		return (input.m_key == m_key);
	}

	std::ostream& operator<<(std::ostream& stream, Pair &pair) {
		stream << std::right << std::setw(20) << pair.getKey() << ": ";
		stream << pair.getValue() ;

		return stream;
	}

}