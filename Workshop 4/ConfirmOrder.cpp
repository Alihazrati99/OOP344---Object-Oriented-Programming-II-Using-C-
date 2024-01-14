#include "ConfirmOrder.h"

namespace sdds {

	ConfirmOrder::ConfirmOrder()
	{
		m_toysArray = nullptr;
		m_counter = 0;
	}


	ConfirmOrder::~ConfirmOrder()
	{
        if(m_toysArray != nullptr)
            delete []m_toysArray;// delete m_toysArray if it's not null
	}

	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
                for (size_t i = 0; i < m_counter; i++) // check toy already exist
			if (m_toysArray[i] == &toy)
				return *this;

        Toy **tmpArray = new Toy*[m_counter + 1]; // allocate new space for array
                for (size_t i = 0; i < m_counter; i++)// copy old values
            tmpArray[i] = const_cast<Toy*>(m_toysArray[i]);

        tmpArray[m_counter] = const_cast<Toy*>(&toy);// add new member
		m_counter++;

        if (m_toysArray != nullptr)
            delete[]m_toysArray;

        m_toysArray = (const Toy**)tmpArray;

		return *this;
	}

        ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) { // remove toy from array
		for (size_t i = 0; i < m_counter; i++)
			if (m_toysArray[i] == &toy) {
				m_toysArray[i] = nullptr;
			}

		return *this;
	}

	std::ostream& operator<<(std::ostream& out, const ConfirmOrder& confirm) {
		
		out << "--------------------------\n";
		out << "Confirmations to Send\n";
		out << "--------------------------\n";

		if (confirm.m_counter == 0) {
			out << "There are no confirmations to send!\n";
		}
		else {
			for (size_t i = 0; i < confirm.m_counter; i++)
				if (confirm.m_toysArray[i] != nullptr)
					out << *confirm.m_toysArray[i];
		}

		out << "--------------------------\n";
		return out;
	}

    ConfirmOrder::ConfirmOrder(const ConfirmOrder& input){
        m_toysArray = nullptr;
        m_counter = 0;
        // using copy assignment operator
        *this = input;
    }

    //copy assignment operator
    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& input){
        if(this != &input){
            if(m_toysArray != nullptr)
                delete []m_toysArray; // delete old array

            m_counter = input.m_counter;
            Toy **tmpArray = new Toy*[input.m_counter]; // allocate space for new array
            for (size_t i = 0; i < m_counter; i++)
                tmpArray[i] = const_cast<Toy*>(input.m_toysArray[i]); // copy array

            m_toysArray = (const Toy**)tmpArray;
        }

        return *this;
    }

    ConfirmOrder::ConfirmOrder(ConfirmOrder&& input){// move constructor
        m_toysArray = nullptr;
        m_counter = 0;
        // using move assignmnet oprator
        *this = std::move(input);
    }
    ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& input){
        if(this != &input){
            if(m_toysArray != nullptr)
                delete []m_toysArray;

            m_counter = input.m_counter;
            m_toysArray = input.m_toysArray;

            input.m_counter = 0;
            input.m_toysArray = nullptr;
        }

        return *this;
    }
}
