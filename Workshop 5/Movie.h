#pragma once

#include <string>
#include <iomanip>
#include <fstream>

namespace sdds{
    class Movie{
        std::string m_movieTitle;
        size_t m_movieYear;
        std::string m_movieDes;
        std::string removeSpaces(const std::string str);

    public:
        Movie();//default constroctor
		~Movie();//destructor
        const std::string &title() const;
        Movie(const std::string &strMovie);

        template <class T>
        void fixSpelling(T &spellChecker){
            spellChecker(m_movieTitle);
            spellChecker(m_movieDes);
        }
        friend std::ostream &operator<<(std::ostream &out, const Movie &movie);

    };

    std::ostream &operator<<(std::ostream &out, const Movie &movie);

}
