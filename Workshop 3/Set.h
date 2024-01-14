#pragma once

#include "Collection.h"
#include <cmath>

namespace sdds {

	// Set template class with capacity 100
	template <typename T, size_t CAPACITY = 100>
	class Set : public Collection<T, 100>
	{
	public:
		Set() {};// default constructor
		~Set() {};

		bool add(const T& item) {
			for (size_t i = 0; i < this->size(); i++) {
				if ((*this)[i] == item) // check if item already exist
					return false;
			}

			// use base class
			return Collection<T, 100>::add(item);
		}
	};

	// specialize Set class
	template<>
	class Set<double, 100> : public Collection<double, 100>
	{
	public:
		Set() :Collection() {}; //default constructor
		~Set() {};

		bool add(const double& item) {//specialize add function for double
			for (size_t i = 0; i < size(); i++) {
				if (abs(abs((*this)[i]) - abs(item)) < 0.01)
					return false;
			}

			return Collection<double, 100>::add(item);
		}
	};

}