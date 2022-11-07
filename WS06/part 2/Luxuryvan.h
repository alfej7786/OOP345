/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 06/11/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_LUXURYVAN_H
#define SDDS_LUXURYVAN_H

#include "Van.h"
#include "Car.h"

namespace sdds {
    class Luxuryvan : public Van
    {
        std::string m_consumption{};

    public:
        Luxuryvan(std::istream &in);
        void display(std::ostream &out) const;
        std::string consumption() const;
    };
} // namespace sdds

#endif //! SDDS_LUXURYVAN_H