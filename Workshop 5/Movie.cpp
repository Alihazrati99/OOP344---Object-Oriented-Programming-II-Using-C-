#include "Movie.h"


namespace sdds
{
    Movie::Movie() :m_movieYear(0) { // default constructor
        m_movieTitle = "";
        m_movieDes = "";
    }

	Movie::~Movie()
	{
	}
    Movie::Movie(const std::string &strMovie)
    {
		std::string tmp = strMovie;
		//TITLE,YEAR,DESCRIPTION

		m_movieTitle = tmp.substr(0, tmp.find(','));
		m_movieTitle = removeSpaces(m_movieTitle);
		tmp = tmp.erase(0, tmp.find(',') + 1);

		m_movieYear = std::stoi(removeSpaces(tmp.substr(0, tmp.find(','))));
		tmp = tmp.erase(0, tmp.find(',') + 1);

		m_movieDes = tmp;
		m_movieDes = removeSpaces(m_movieDes);
    }

	const std::string &Movie::title() const {
		return m_movieTitle;
	}
	std::string Movie::removeSpaces(std::string input) {
		// clean extra spaces from start
		while (input[0] == ' ')
			input = input.substr(1, input.length() - 1);

		// clean extra spaces from end
		while (input[input.length() - 1] == ' ')
			input = input.substr(0, input.length() - 1);

		return input;
	}
   
    std::ostream &operator<<(std::ostream &stream, const Movie &m){
        stream << std::setw(40) << std::right  << m.m_movieTitle << " | ";
        stream << std::setw(4) << m.m_movieYear << " | ";
        stream << m.m_movieDes << std::endl;
        return stream;
    }
}
