#include "Book.h"
#include <iomanip>

namespace sdds
{
	// default constructor
    Book::Book() : m_bookAuther(""), m_bookYear(0), m_bookCountry(""), m_bookTitle(""),
                    m_bookPrice(0.0), m_bookDescription(""){
	}
	Book::~Book()
	{
	}

	std::string Book::removeSpaces(std::string input) {
		// clean extra spaces from start
		while (input[0] == ' ')
			input = input.substr(1, input.length() - 1);

		// clean extra spaces from end
		while (input[input.length() - 1] == ' ')
			input = input.substr(0, input.length() - 1);

		return input;
	}

    Book::Book(const std::string &strBook)
    {
		//AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
        char c = ',';int s = 0;
        int e = strBook.find(c, s);
		m_bookAuther = strBook.substr(s, (e - s));
        s = e + 1;e = strBook.find(c, s);
        m_bookTitle = removeSpaces(strBook.substr(s, (e - s)));

        s = e + 1;e = strBook.find(c, s);
        m_bookCountry = removeSpaces(strBook.substr(s, (e - s)));
        s = e + 1;e = strBook.find(c, s);
        m_bookPrice = std::stod(strBook.substr(s, (e - s)));

        s = e + 1;e = strBook.find(c, s);
        m_bookYear = std::stoi(strBook.substr(s, (e - s)));

        s = e + 1;e = strBook.size();
        m_bookDescription = removeSpaces(strBook.substr(s, (e - s)));
    }

   
    const std::string &Book::country() const { 
		return m_bookCountry; 
	}
	const std::string &Book::title() const {
		return m_bookTitle;
	}

	double &Book::price() { 
		return m_bookPrice; 
	}

    const size_t &Book::year() const { 
		return m_bookYear; 
	}

	std::ostream &operator<<(std::ostream &stream, const Book &b){
        stream << std::setw(20) << std::right  << b.m_bookAuther << " | ";
        stream << std::setw(22) << std::right  << b.m_bookTitle << " | ";
        stream << std::setw(5) << std::right << b.m_bookCountry << " | ";
        stream << std::setw(4) << b.m_bookYear << " | ";
        stream << std::setw(6) << std::right << std::setprecision(2) << std::fixed  << ((b.m_bookPrice * 100.0)) / 100.0 << " | ";
        stream << b.m_bookDescription << std::endl;
        return stream;
    }

}
