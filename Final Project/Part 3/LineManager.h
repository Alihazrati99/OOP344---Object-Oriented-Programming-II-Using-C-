#pragma once

#include "Workstation.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

namespace sdds {
	extern std::deque<CustomerOrder> g_incomplete;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_pending;

	class LineManager{
	private:
		size_t m_cntCustomerOrder;
		std::vector<Workstation*> m_activeLine;
		Workstation* m_firstStation;
		void safeState();
		Workstation* returnStation(std::string,const std::vector<Workstation*>&);
		bool isNext(Workstation*, std::string);
	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		~LineManager();
		//performs one iteration of operations on all of the workstations
		bool run(std::ostream& os);
		void display(std::ostream& os) const;//displays all active stations
		//reorders the workstations
		void reorderStations();
	};


}