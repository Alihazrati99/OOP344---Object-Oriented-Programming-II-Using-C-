#pragma once

#include <iostream>
#include <string>

namespace sdds
{
    class SpellChecker{
		std::string m_goodWords[6];
        std::string m_badWords[6];
        int missCounter[6];

    public:
        SpellChecker(const char *filename);
        void operator()(std::string &text);
        void showStatistics(std::ostream &out) const;
    };

}
