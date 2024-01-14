#include "CustomerOrder.h"

namespace sdds {

	size_t CustomerOrder::m_widthField;

	CustomerOrder::CustomerOrder() {
		safeState();
	}

	CustomerOrder::CustomerOrder(const std::string &order) {
		safeState();
		Utilities utilities;
		bool more = true;
		size_t nextPos = 0;

		//extract name
		m_name = utilities.extractToken(order, nextPos, more);
		// extract product
		m_product = utilities.extractToken(order, nextPos, more);

		while (more) {
			std::string str = utilities.extractToken(order, nextPos, more);
			Item *item = new Item(str);
			*this += item;// add new item
		}

		if (utilities.getFieldWidth() > m_widthField)
			m_widthField = utilities.getFieldWidth();
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& order) {
		throw "";
	}

	CustomerOrder::CustomerOrder(CustomerOrder &&order)
		noexcept {
		safeState();
		*this = std::move(order);
	}

	CustomerOrder& CustomerOrder::operator =(CustomerOrder &&order) noexcept {
		if (&order != this) {
			if (m_lstItem != nullptr) {
				for (size_t i = 0; i < m_cntItem; i++)
					delete m_lstItem[i];
				delete[]m_lstItem;
			}
			m_name = order.m_name;
			m_cntItem = order.m_cntItem;
			m_lstItem = order.m_lstItem;
			order.m_lstItem = nullptr;
			m_product = order.m_product;
		}
		return *this;
	}
	// destructor
	CustomerOrder::~CustomerOrder() {
		if (m_lstItem != nullptr)
		{
			for (size_t i = 0; i < m_cntItem; i++)
				delete m_lstItem[i];
			delete[]m_lstItem;
		}
	}

	void CustomerOrder::operator+=(Item *newItem) {
		Item **array = new Item*[m_cntItem + 1];
		for (size_t i = 0; i < m_cntItem; i++)
			array[i] = m_lstItem[i];
		if (m_lstItem != nullptr)
			delete[]m_lstItem;

		array[m_cntItem++] = newItem;
		m_lstItem = array;
	}

	bool CustomerOrder::isOrderFilled() const {
		for (size_t i = 0; i < m_cntItem; i++)
			if (!m_lstItem[i]->m_isFilled)
				return false;
		return true;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == itemName)
				if (!m_lstItem[i]->m_isFilled)
					return false;
		}
		return true;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		if (m_cntItem == 0)
			return;
		for (size_t i = 0; i < m_cntItem; i++) {
			if (station.getItemName() == m_lstItem[i]->m_itemName)
				if (station.getQuantity() > 0) {
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					station.updateQuantity();
					os << "    Filled " << m_name
						<< ", " << m_product
						<< " [" << station.getItemName()
						<< "]\n";
					break;
				}
		}
	}

	void CustomerOrder::display(std::ostream& os) const {
		os << m_name
			<< " - " << m_product
			<< "\n";

		for (size_t i = 0; i < m_cntItem; i++) {
			os << "[" << std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber << "] ";
			os << std::setfill(' ') << std::left << std::setw(m_widthField) << m_lstItem[i]->m_itemName << "   - ";
			if (m_lstItem[i]->m_isFilled)
				os << "FILLED\n";
			else
				os << "TO BE FILLED\n";
		}
	}
	void CustomerOrder::safeState() {
		m_cntItem = 0;
		m_lstItem = nullptr;
	}
}