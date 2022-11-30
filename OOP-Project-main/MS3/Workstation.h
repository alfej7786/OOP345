
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
// Name: Alfej Savaya
// Seneca Student ID: 118823210
// Seneca email: aasavaya@myseneca.ca
// Date of completion: 30-Nov-2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

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