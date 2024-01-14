#pragma once
#include "CustomerOrder.h"
#include <iostream>
#include <deque>
#include <string>
#include "Station.h"

namespace sdds {
	extern std::deque<CustomerOrder> g_incomplete;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_pending;

	class Workstation : public Station {
	private:
		void safeState();
		std::deque<CustomerOrder> m_orders;
		Workstation *m_pNextStation;
	public:
		Workstation(std::string);
		// object cannot be copied or moved
		Workstation(const Workstation&) = delete;
		void operator=(const Workstation&) = delete;
		Workstation(const Workstation&&) = delete;
		void operator=(const Workstation&&) = delete;
		~Workstation();//destructor
		// fills the order at the front of the queue
		void fill(std::ostream& os);
		// attempts to move the order
		bool attemptToMoveOrder();
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		// return true if order is empty
		bool orderIsZero();
	};
}