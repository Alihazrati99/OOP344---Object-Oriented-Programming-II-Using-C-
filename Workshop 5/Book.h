#pragma once

#include <iostream>
#include <string>

namespace sdds
{
    class Book{
        std::string m_bookAuther; 
		std::string m_bookCountry;
		size_t m_bookYear;
		double m_bookPrice;
        std::string m_bookTitle;
        std::string m_bookDescription;
		std::string removeSpaces(std::string);

    public:
        Book();//default constructor
		~Book(); // destructor
        Book(const std::string &strBook);
		friend std::ostream &operator<<(std::ostream &out, const Book &book);
        const size_t &year() const;
        double &price(); const std::string &title() const;
		const std::string &country() const;
        
        template <class T>
        void fixSpelling(T &spellChecker){
            spellChecker(m_bookDescription);
        }
       
    };

    std::ostream &operator<<(std::ostream &, const Book &);
}
