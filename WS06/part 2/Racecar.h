/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 06/11/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include <iostream>
#include <string>
#include "Car.h"

namespace sdds {
    class Racecar : public Car
    {
        double m_booster{};

    public:
        Racecar();
        Racecar(std::istream &in);
        void display(std::ostream &out) const;
        double topSpeed() const;
        ~Racecar();
    };
}
#endif // !SDDS_RACECAR_H