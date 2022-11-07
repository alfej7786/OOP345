/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 06/11/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <string>
#include <sstream>
#include "Racecar.h"

using namespace std;

namespace sdds
{

    Racecar::Racecar() : m_booster(0) {}

    Racecar::Racecar(istream &in) : Car(in)
    {
        string ss;
        getline(in, ss);
        string booster = ss.substr(ss.find_last_of(",") + 1); // extract booster end of string
        stringstream str(booster);
        str >> m_booster; // string to double through stringstream
    }

    void Racecar::display(std::ostream &out) const
    {
        Car::display(out);
        out << "*";
    }

    double Racecar::topSpeed() const
    {
        return (Car::topSpeed() * (m_booster + 1.0));
    }

    Racecar::~Racecar() {}
}