#include "ProteinDatabase.h"

namespace sdds {

	ProteinDatabase::ProteinDatabase()
    {
        init();// safe state
	}


    ProteinDatabase::~ProteinDatabase()// destructor
    {
        if (m_array)
            delete[]m_array;
    }

    void ProteinDatabase::init(){
        m_array_counter = 0;
        m_array = nullptr;
    }

    ProteinDatabase::ProteinDatabase(std::string file) {
        init();
        std::ifstream File(file);

        std::string a;

        while (File) // count number of proteins
        {
            File >> a;
            if (a[0] == '>')
                m_array_counter += 1;
        }

        File.close();
        File.open(file);


        m_array = new std::string[m_array_counter];

        int index = 0;

        getline(File, a);

        while (File)
        {
            std::string line = "";
            std::string str = " ";

            while (str[0] != '>' && !File.eof())
            {
                getline(File, str);
                if (str[0] != '>')
                    line += str;
            }
            m_array[index] = line;
            index += 1;
        }
	}

    ProteinDatabase::ProteinDatabase(const ProteinDatabase& protein)
    {
        init();
        *this = protein;
	}

    ProteinDatabase::ProteinDatabase(ProteinDatabase&& protein)
    {
        init();
        *this = std::move(protein);
    }

    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& protein)
    {
        if (this != &protein)
        {
            if (m_array)
                delete []m_array; // delete array

            m_array_counter = protein.m_array_counter;
            m_array = new std::string[m_array_counter];
            for (size_t i = 0; i < protein.m_array_counter; i++)
                m_array[i] = const_cast<ProteinDatabase&>(protein)[i];// copy array elements

		}

		return *this;
	}

    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& protein) {
        if (this != &protein)
        {
            if (m_array)
                delete[]m_array;

            m_array_counter = protein.m_array_counter;
            m_array = protein.m_array; // move
            protein.m_array_counter = 0;
            protein.m_array = nullptr;
		}
		return *this;
	}

    std::string ProteinDatabase::operator[](size_t index)
    {
        if (index >= m_array_counter || index < 0)
            return "";

        return m_array[index];
    }

	size_t ProteinDatabase::size() {
        return m_array_counter;//return array elements counter
	}
}
