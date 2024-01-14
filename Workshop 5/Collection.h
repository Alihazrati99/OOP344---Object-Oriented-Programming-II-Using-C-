#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

namespace sdds{
	// template class
    template <class T>
    class Collection{
        std::string collectionName;
        size_t m_counter;
		T *arrayOfElements; //dynamic array
        void (*functionPointer)(const Collection<T> &, const T &);

    public:
		//constructor
        Collection(const std::string &name) : collectionName(name){
			functionPointer = nullptr;
			arrayOfElements = nullptr;
			m_counter = 0;
        } 
		// destructor
		~Collection()
		{
			if (arrayOfElements != nullptr) {
				delete[] arrayOfElements;
				arrayOfElements = nullptr;
			}
			functionPointer = nullptr;
		}

		void setObserver(void(*observer)(const Collection<T> &, const T &)) {
			functionPointer = observer;
		}
		size_t size() const {
			return m_counter;
		}
        const std::string &name() const { 
			return collectionName; 
		}
		// operator overload +=
        Collection<T> &operator+=(const T &item){
            // check for existing element
            for (size_t i = 0; i < m_counter; i++)
                if (arrayOfElements[i].title() == item.title())
                    return *this;

            T *tmpArray = new T[m_counter + 1];
            for (size_t i = 0; i < m_counter; i++)
				tmpArray[i] = arrayOfElements[i];
			tmpArray[m_counter] = item;

			if (arrayOfElements != nullptr) {
				delete[] arrayOfElements;// delete prev array
				arrayOfElements = nullptr;
			}
			arrayOfElements = tmpArray;
			m_counter++;

            if (functionPointer != nullptr)
                functionPointer(*this, item);

            return *this;
        }
        T *operator[](const std::string &title) const{
            for (size_t i = 0; i < m_counter; i++)
                if (arrayOfElements[i].title() == title)
                    return &arrayOfElements[i];

            return nullptr;
        }
		// oeprator oveload []
		T &operator[](size_t idx) const {
			if (idx < 0 || idx >= m_counter) {
				std::string error = "Bad index [" + std::to_string(idx) +
					"]. Collection has [" + std::to_string(m_counter) + "] items.";
				throw std::out_of_range(error);
			}
			return arrayOfElements[idx];
		}

        friend std::ostream &operator<<(std::ostream &stream, const Collection &coll){
            for (size_t i = 0; i < coll.m_counter; i++)
				stream << coll.arrayOfElements[i];

            return stream;
        }

      
    };

} 
