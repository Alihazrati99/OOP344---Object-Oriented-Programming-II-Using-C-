#pragma once

#include <iostream>
#include "Pair.h"

namespace sdds {
	// Collection template class
	template <typename T, size_t CAPACITY>
	class Collection {
		T m_elements[CAPACITY]; // array of elements
		size_t m_counter; 
		T m_dummy; // dummy object

		void init() {
			m_counter = 0;
		}

	public:
		Collection() :m_dummy{ } { init(); };
		// operator overload []
		T operator[](unsigned i) {
			if (i < CAPACITY && i < m_counter)// validate input
				return m_elements[i];
			else
				return m_dummy; // dummy object
		}

		size_t size() const {
			return m_counter;
		}

		// display query
		std::ostream& display(std::ostream& stream = std::cout) {
			stream << "----------------------\n";
			stream << "| Collection Content |\n";
			stream << "----------------------\n";
			
			for(size_t i = 0; i < m_counter; i++) {
				stream << m_elements[i]<<std::endl;
			}
			stream << "----------------------\n";
			return stream;
		}

		// add function
		virtual bool add(const T& item) {
			if (m_counter < CAPACITY) { // check capacity
				m_elements[m_counter++] = item;
				return true;
			}
			else
				return false;
		}

		virtual ~Collection() {};

	};

	// specialize Collection
	template <>
	class Collection<Pair, 100> {
		Pair m_elements[100];
		size_t m_counter;
		Pair m_dummy;

		void init() {
			m_counter = 0;
			m_dummy = Pair("No Key", "No Value"); // dummy object default value it's deferent
		}
	public:
		Collection() :m_dummy{ } { init(); };
		Pair operator[](unsigned i) {
			if (i < 100 && i < m_counter)
				return m_elements[i];
			else
				return m_dummy; // dummy object
		}

		size_t size() const {
			return m_counter;
		}

		std::ostream& display(std::ostream& stream = std::cout) {
			stream << "----------------------\n";
			stream << "| Collection Content |\n";
			stream << "----------------------\n";

			for (size_t i = 0; i < m_counter; i++) {
				stream << m_elements[i] << std::endl;
			}
			stream << "----------------------\n";
			return stream;
		}

		virtual bool add(const Pair& item) {
			if (m_counter < 100) {
				m_elements[m_counter++] = item;
				return true;
			}
			else
				return false;
		}

		virtual ~Collection() {};

	};
}