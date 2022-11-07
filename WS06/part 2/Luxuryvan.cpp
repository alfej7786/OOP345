/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 06/11/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Luxuryvan.h"

namespace sdds
{
    Luxuryvan::Luxuryvan(std::istream &in) : Van(in)
    {
        char value = '\0';
        in >> value;
        if (value == 'e')
        {

            m_consumption = "electric van ";
        }
        else
        {
            throw std::string("Invalid record!");
        }
        in.ignore(1000, '\n');
    }

    void Luxuryvan::display(std::ostream &out) const
    {
        Van::display(out);
        out << (m_consumption[0] == 'e' ? " electric van  *" : "");
    }

    std::string Luxuryvan::consumption() const
    {
        return m_consumption;
    }
}