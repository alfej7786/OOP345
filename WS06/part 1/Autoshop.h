#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Vehicle.h"
#include "Luxuryvan.h"

namespace sdds
{
    class Autoshop
    {
    private:
        /* data */
        std::vector<Vehicle *> m_vehicles{};
        std::vector<Luxuryvan *> m_lvehicles{};

    public:
        // Autoshop(/* args */);
        Autoshop &operator+=(Vehicle *theVehicle);
        void display(std::ostream &out) const;

        template <typename T>
        void select(T test, std::list<const Vehicle *> &vehicles)
        {
            for (auto v = m_vehicles.cbegin(); v != m_vehicles.cend(); ++v)
            {
                if (test(*v))
                {
                    vehicles.push_back(*v);
                }
            }
        }
        template <typename T>
        void typev(T test, std::list < const Luxuryvan * > &lv)
        {
            for (auto v = m_lvehicles.cbegin(); v != m_lvehicles.cend(); ++v)
            {
                if (test(*v))
                {
                    lv.push_back(*v);
                }
            }
        }
        ~Autoshop();
    };
}
#endif //! SDDS_AUTOSHOP_H