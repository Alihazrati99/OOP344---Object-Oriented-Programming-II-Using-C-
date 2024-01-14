#include "Utilities.h"

namespace sdds {
	std::string removeSpaces(std::string input) {
		if (input == "")
			return "";
		// clean extra spaces from start
		while (input[0] == ' ')
			input = input.substr(1, input.length() - 1);

		// clean extra spaces from end
		while (input[input.length() - 1] == ' ')
			input = input.substr(0, input.length() - 1);

		return input;
	}

	Person* buildInstance(std::istream& in) {
		std::string type;
		std::getline(in, type, ',');
		type = removeSpaces(type);

		if (type[0] == 'e' || type[0] == 'E') {
			Person *p = new Employee(in);
			return p;
		}
		else if (type[0] == 'p' || type[0] == 'P') {
			Person *p = new Professor(in);
			return p;
		}
		else if (type[0] == 's' || type[0] == 'S') {
			Person *p = new Student(in);
			return p;
		}
		else {
			in.ignore(256, '\n');
		}

		return nullptr;
	}
}