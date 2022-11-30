
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include <string>
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"

namespace sdds {
    extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete;

    class Workstation : public Station
    {
    private:
        /* data */
        std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation=nullptr;
    public:
        // Workstation(/* args */);
        Workstation(const std::string& str);
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);


		Workstation(const Workstation& str) = delete;
		Workstation(Workstation&& str) = delete;
		Workstation& operator=(const Workstation& other) = delete;
		Workstation& operator=(Workstation& other) = delete;
		~Workstation();
    };
}

#endif // !SDDS_WORKSTATION_H