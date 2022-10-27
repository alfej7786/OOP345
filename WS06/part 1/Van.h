#ifndef SDDS_VAN_H
#define SDDS_VAN_H

#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Car.h"

namespace sdds {
    class Van : public Vehicle
    {
    private:
        /* data */
        std::string m_maker{};
        enum Type { Pickup, Minibus, Camper };
        enum Condition { New, Used, Broken };
        enum Purpose { Delivery, Passenger, Camping };
        Type m_type{};
        Condition m_condition{};
        Purpose m_purpose{};
        double m_speed{};
    public:
        Van(/* args */);
        Van(std::istream& is);
        std::string condition() const;
        double topSpeed() const;
        std::string type() const;
        std::string usage() const;
        void display(std::ostream& out) const;
    };
    
}

#endif // !SDDS_VAN_H