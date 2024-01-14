#include "SpellChecker.h"
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;
namespace sdds
{
	// constructor
    SpellChecker::SpellChecker(const char *filename)
    {
        fstream file(filename);
        if (!file){
            throw "Bad file name!";
        }

		size_t i = 0;
		while (file && i < 6)
		{
			file >> m_badWords[i];
			file >> m_goodWords[i++];
			file.ignore(100, '\n');
		}
        for (unsigned int i = 0; i < 6; i++)
            missCounter[i] = 0;
    }
	// operator overload ()
    void SpellChecker::operator()(std::string &text)
    {
		for (int i = 0; i < 6; i++) {
			while (text.find(m_badWords[i]) != std::string::npos) {
				text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
				missCounter[i]++;
			}
		}
    }

    void SpellChecker::showStatistics(std::ostream &out) const{
        out << "Spellchecker Statistics\n";
        for (unsigned int i = 0; i < 6; i++)
            out << std::setw(15) << std::right << m_badWords[i] << ": " << missCounter[i] << " replacements\n";
    }
}
