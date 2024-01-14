#pragma once

#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>

namespace sdds {
	class ProteinDatabase
    {
    private:
        void init();
        std::string *m_array;
        size_t m_array_counter;

	public:
        ProteinDatabase();// constructor
        ~ProteinDatabase();// destructor
        ProteinDatabase(ProteinDatabase&& );
        ProteinDatabase& operator=(ProteinDatabase&& );
        ProteinDatabase(const ProteinDatabase& protein);
        ProteinDatabase& operator=(const ProteinDatabase& );
        ProteinDatabase(std::string);
		std::string operator[](size_t);
        size_t size();
	};

}
