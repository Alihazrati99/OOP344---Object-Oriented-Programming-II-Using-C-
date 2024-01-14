#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

namespace sdds {
	struct Item {
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };
		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {
	private:
		std::string m_name;
		std::string m_product;
		size_t m_cntItem;
		Item** m_lstItem;
		static size_t m_widthField;
		void operator+=(Item *item);
	public:
		CustomerOrder();
		~CustomerOrder();
		CustomerOrder(const std::string &);
		CustomerOrder(CustomerOrder &&) noexcept;
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(const CustomerOrder&);
		CustomerOrder& operator =(CustomerOrder &&) noexcept;
		bool isItemFilled(const std::string &itemName) const;
		bool isOrderFilled() const;
		void fillItem(Station &station, std::ostream &os);
		void display(std::ostream &os) const;
		void safeState();
	};

}
#endif // CUSTOMERORDER_H
