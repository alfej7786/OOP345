/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 06/11/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
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
        std::string m_maker = "";
		std::string m_condition = "";
		double m_speed = 0;
    public:
        Car(/* args */);
        Car(std::istream& is);
        std::string condition() const;
        double topSpeed() const;
        void display(std::ostream& out) const;
    };
}
#endif // !SDDS_CAR_H