#include "Workstation.h"

namespace sdds {
	std::deque<CustomerOrder> g_incomplete;
	std::deque<CustomerOrder> g_completed;
	std::deque<CustomerOrder> g_pending;

	Workstation::Workstation(std::string str) : Station(str) {
		safeState();
	}

	bool Workstation::attemptToMoveOrder() {
		if (m_orders.empty())
			return false;

		if ((getQuantity() <= 0) || 
			(m_orders.front().isItemFilled(getItemName()))) {
			if (m_pNextStation != nullptr) {
				*m_pNextStation += std::move(m_orders.front());m_orders.pop_front();
			}else {
				if (m_orders.front().isOrderFilled()) {
					g_completed.push_back(std::move(m_orders.front()));
					m_orders.pop_front();
				}
				else {
					g_incomplete.push_back(std::move(m_orders.front()));
					m_orders.pop_front();
				}
			}
			return true;
		}
		return false;
	}
	void Workstation::fill(std::ostream& os) {
		if (m_orders.size() > 0)  // check m_orders it's not empty
			m_orders.front().fillItem(*this, os);
	}
	bool Workstation::orderIsZero() {
		if (m_orders.size() == 0)
			return true;
		return false;
	}
	void Workstation::setNextStation(Workstation* station) {
		m_pNextStation = station;
	}
	Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}
	// operator +=
	Workstation&  Workstation::operator+=(CustomerOrder&& newOrder) {
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
	void Workstation::display(std::ostream& os) const {
		os << getItemName() << " --> ";
		if (!m_pNextStation)
			os << "End of Line" << std::endl;
		else
			os << m_pNextStation->getItemName() << std::endl;
	}

	void Workstation::safeState() {
		m_pNextStation = nullptr;
	}
	Workstation::~Workstation(){
		m_pNextStation = nullptr;
	}

}