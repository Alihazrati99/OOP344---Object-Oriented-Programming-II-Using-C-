#pragma once

#include "Toy.h"

namespace sdds {

	class ConfirmOrder
	{
                const sdds::Toy** m_toysArray; // array of pointers
                size_t m_counter;
	public:
                ConfirmOrder(); //default constructor
                ~ConfirmOrder(); // destructor

                // operator overload +=
		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);

		friend std::ostream& operator<<(std::ostream&, const ConfirmOrder&);
        // copy constructor
        ConfirmOrder(const ConfirmOrder& input);
        ConfirmOrder& operator=(const ConfirmOrder& input);// copy assignment operator
        ConfirmOrder(ConfirmOrder&& input);// move constructor
        ConfirmOrder& operator=(ConfirmOrder&& input);
	};

}
