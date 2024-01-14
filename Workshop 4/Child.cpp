#include "Child.h"


namespace sdds {

	Child::Child()
	{
                init(); //empty state
	}

	void Child::init() {
		m_toysArray = nullptr;
		m_counter = 0;
	}

        Child::~Child(){ //destructor
		if (m_toysArray != nullptr) {
                        for (size_t i = 0; i < m_counter; i++) // delete members one by one
				delete m_toysArray[i];
			delete[]m_toysArray;
		}
	}

	Child::Child(std::string name, int age, const Toy* toys[], size_t count) {
		m_name = name;
		m_age = age;
		m_counter = count;
        Toy **tmpArray = new Toy*[count]; // allocate space for new array
		for (size_t i = 0; i < count; i++) {
			
			tmpArray[i] = new Toy(*toys[i]);
		}

		m_toysArray = (const Toy**)tmpArray;
	}

	size_t Child::size() const {
		return m_counter;
	}


	std::ostream& operator<<(std::ostream& out, const Child& child) {
		static size_t CALL_CNT = 1;
		out << "--------------------------\n";
		out << "Child " << CALL_CNT++ << ": " << child.m_name << " " << child.m_age << " years old:\n";
		out << "--------------------------\n";
		
		if (child.size() == 0) {
			out << "This child has no toys!\n";
		}
		else {
			for (size_t i = 0; i < child.size(); i++)
				out << *child.m_toysArray[i];
		}

		out << "--------------------------\n";
		return out;
	}

        Child::Child(const Child& input) { // copy constructor
		init();
		*this = input;
	}

	Child& Child::operator=(const Child& input) {
		if (this != &input) {
			m_age = input.m_age;
			m_name = input.m_name;

            if (m_toysArray != nullptr) { // delete old array and of members
                for (size_t i = 0; i < m_counter; i++)
                    delete m_toysArray[i];
                delete[]m_toysArray;
            }

            m_counter = input.m_counter;
			Toy **tmpArray = new Toy*[m_counter];
			for (size_t i = 0; i < m_counter; i++) {
				tmpArray[i] = new Toy(*input.m_toysArray[i]);
			}

			m_toysArray = (const Toy**)tmpArray;
		}

		return *this;
	}
        Child::Child(Child &&input) { // move constructor
		init();
		*this = std::move(input);
	}

        Child& Child::operator=(Child&& input) { // move assignment
		if (this != &input) {
			m_age = input.m_age;
			m_name = input.m_name;


            if (m_toysArray != nullptr) {
                for (size_t i = 0; i < m_counter; i++)
                    delete m_toysArray[i];
                delete[]m_toysArray;
            }
            m_counter = input.m_counter;
			m_toysArray = input.m_toysArray;
			input.m_toysArray = nullptr;
			input.m_counter = 0;
			input.m_age = 0;
			input.m_name = "";
		}

		return *this;
	}
}
