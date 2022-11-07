/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 06/11/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

// #include <iostream>
// #include <string>
#include <sstream>
#include <iostream>
#include "Utilities.h"
#include "Car.h"
#include "Van.h"
#include "Luxuryvan.h"
#include "Racecar.h"

namespace sdds {
    Vehicle* createInstance(std::istream& in);
}
#endif //!SDDS_UTILITIES_H