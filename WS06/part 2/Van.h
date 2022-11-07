/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 06/11/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
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
		std::string m_type;
		std::string m_condition;
		std::string m_purpose;
		double m_topSpeed;
    public:
        Van(std::istream& in);
		std::string usage() const;
		std::string condition()const;
		std::string type() const;
		double topSpeed()const;
		void display(std::ostream& out) const;
    };
    
}

#endif // !SDDS_VAN_H