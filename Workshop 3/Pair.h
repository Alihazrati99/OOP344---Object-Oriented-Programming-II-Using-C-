#pragma once

#include <string>
#include <iostream>

namespace sdds {
	
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey() { return m_key; }
		const std::string& getValue() { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};
		Pair() : m_key(""), m_value("") {};

		// TODO: Add here the missing prototypes for the members
		//           that are necessary if this class is to be used
		//           with the template classes described below.
		//       Implement them in the Pair.cpp file.
		bool operator==(const Pair& input);
		
	};

	std::ostream& operator<<(std::ostream& stream, Pair &pair);
}