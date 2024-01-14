#pragma once

#include <iostream>
#include <string>

namespace sdds {
	class Utilities{
		static char m_delimiter;
		size_t m_widthField;

	public:
		Utilities();
		void safeState();
		void setFieldWidth(size_t);
		size_t getFieldWidth() const;
		static char getDelimiter();
		static void setDelimiter(char);
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		// clean extra spaces from start and end of string
		std::string cleanSpaces(std::string);
	};

}