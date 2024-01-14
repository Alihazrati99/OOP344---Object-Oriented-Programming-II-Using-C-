#include "LineManager.h"
#include "Utilities.h"
#include <algorithm>

namespace sdds {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		safeState();
		std::string line;
		Utilities u;
		bool more;
		std::ifstream f;
		f.open(file);
		if (!f.is_open())
			throw std::string("Error!!");

		while (!f.eof()) {
			size_t pos = 0;
			std::string next, current;
			u.setDelimiter('|');
			std::getline(f, line);
			current = u.extractToken(line, pos, more);

			if (more)
				next = u.extractToken(line, pos, more);

			Workstation* tmp = returnStation(current, stations);
			m_activeLine.push_back(tmp);
			if (next != "")
				m_activeLine.back()->setNextStation(returnStation(next, stations));

			std::for_each(m_activeLine.begin(), m_activeLine.end()
				, [&](Workstation *st)
			{
				if (std::none_of(m_activeLine.begin(), m_activeLine.end(), [st](Workstation *s) {
					return s->getNextStation() == st;
				}))
				{
					m_firstStation = st;
				}
			});
		}
	}
	bool LineManager::isNext(Workstation* workstation, std::string itemName) {
		if (workstation->getItemName() == itemName)
			return true;
		if (!workstation->getNextStation())
			return false;
		return (isNext(workstation->getNextStation(), itemName));
	}
	// return station pointer with given name
	Workstation* LineManager::returnStation(std::string itemName, const std::vector<Workstation*>& stVector) {
		for (size_t i = 0; i < stVector.size(); ++i)
			if (stVector[i]->getItemName() == itemName)
				return stVector[i];

		return nullptr;
	}
	void LineManager::reorderStations() {
		std::sort(m_activeLine.begin(), m_activeLine.end()
			, [&](Workstation* st1, Workstation* st2) {
			return isNext(st1, st2->getItemName());
		});
		
	}
	bool LineManager::run(std::ostream& os) {
		static size_t c = 1;
		os << "Line Manager Iteration: "
			<< c << std::endl;
		c += 1;

		if (g_pending.size() > 0) {
			(*m_firstStation) += std::move(g_pending.front());
			g_pending.pop_front();
		}
		// fill stations
		std::for_each(m_activeLine.begin(), m_activeLine.end()
			, [&](Workstation *st)
		{
			st->fill(os); });
		// attempts to move an order down the line
		std::for_each(m_activeLine.begin(), m_activeLine.end()
			, [&](Workstation *st)
		{
			st->attemptToMoveOrder(); });

		bool result = std::all_of(m_activeLine.begin(), m_activeLine.end(), [&](Workstation *st) {
			return st->orderIsZero(); 
		});

		return (result);
	}

	void LineManager::safeState() {
		m_firstStation = nullptr;
	}
	void LineManager::display(std::ostream& os) const {
		std::for_each(m_activeLine.begin(), m_activeLine.end()
			, [&](Workstation* st) {
			st->display(os); });
	}
	LineManager::~LineManager()
	{
	}

}