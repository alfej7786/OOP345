#include "LineManager.h"

using namespace std;
namespace sdds
{
    LineManager::LineManager(const std::string &file, const std::vector<Workstation *> &stations) {
        ifstream is(file);
        string line;
        string nmaeOfItem;
        string start;
        string stop;
        size_t pos = 0;
        bool more = true;

        Utilities ut;
        
        ut.setDelimiter('|');
        vector<Workstation *> remainfirst;
        while (!is.eof())
        {
            getline(is, line);
            pos = 0;
            more = true;
            nmaeOfItem = ut.extractToken(line, pos, more);
            Workstation *wp;
            wp = *(find_if(stations.begin(), stations.end(), [&](Workstation *sp) { 
                return sp->getItemName() == nmaeOfItem; 
            }));
            m_activeLine.push_back(wp);
            remainfirst.push_back(wp);
        }
        is.seekg(ios::beg);
        while (!is.eof())
        {
            getline(is, line);
            pos = 0;
            more = true;
            start = ut.extractToken(line, pos, more);
            if (more)
            {
                Workstation *fromWp, *toWp;
                stop = ut.extractToken(line, pos, more);
                toWp = *(find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation *wp) { 
                    return wp->getItemName() == stop; 
                }));

                remainfirst.erase(remove(remainfirst.begin(), remainfirst.end(), toWp), remainfirst.end());
                fromWp = *(find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation *wp) { 
                    return wp->getItemName() == start; 
                }));
                fromWp->setNextStation(toWp);
            }
        }
        m_cntCustomerOrder = g_pending.size();
        m_firstStation = remainfirst.front();
    }

    void LineManager::reorderStations() {
		std::vector<Workstation*> tempLine;
		Workstation* tp;
		tempLine.push_back(m_firstStation);
		while ((tp = tempLine.back()->getNextStation())) tempLine.push_back(tp);
		m_activeLine.clear();
		m_activeLine = tempLine;
	}

	bool LineManager::run(std::ostream& os) {
		static size_t count;
		count++;
		os << "Line Manager Iteration: " << count << endl;
		if (!g_pending.empty()) 
        {
			*m_firstStation += move(g_pending.front());
			g_pending.pop_front();
		}

		for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) 
        {
			ws->fill(os);
		});
		for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) 
        {
			ws->attemptToMoveOrder();
		});

		return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;
	}

	void LineManager::display(std::ostream& os) const {
		for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) 
        {
			ws->display(os);
		});
	}
}