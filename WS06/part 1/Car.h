#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
    class Car : public Vehicle
    {
    private:
        /* data */
        std::string m_maker{};
        enum Condition { New, Used, Broken };
        Condition m_condition{};
        double m_speed{};
    public:
        Car(/* args */);
        Car(std::istream& is);
        std::string condition() const;
        double topSpeed() const;
        void display(std::ostream& out) const;
    };
    std::string& trim(std::string&);
}
#endif // !SDDS_CAR_H