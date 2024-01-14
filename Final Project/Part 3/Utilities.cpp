#include "Utilities.h"

namespace sdds {

	char Utilities::m_delimiter;

	Utilities::Utilities()
	{
		safeState();
	}

	
	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}
	void Utilities::safeState() {
		m_widthField = 1;
	}


	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		
		size_t delimitenPos = str.find(m_delimiter, next_pos);

		if (delimitenPos == next_pos) {
			more = false;
			throw "";
		}

		std::string result = (str.substr(next_pos, delimitenPos - next_pos));

		result = cleanSpaces(result);
		
		next_pos = delimitenPos + 1;

		more = (delimitenPos == std::string::npos) ? false : true;
		
		if (m_widthField < result.length())
			m_widthField = result.length();

		return result;
	}
	char Utilities::getDelimiter() {
		return m_delimiter;
	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}


	// remove extra spaces
	std::string Utilities::cleanSpaces(std::string input) {
		if (input == "")
			return "";

		// clean extra spaces from start
		while (input[0] == ' ')
			input = input.substr(1, input.length() - 1);

		if (input == "")
			return "";
		// clean extra spaces from end
		while (input[input.length() - 1] == ' ')
			input = input.substr(0, input.length() - 1);

		return input;
	}
}