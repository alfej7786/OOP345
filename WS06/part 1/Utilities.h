#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

// #include <iostream>
// #include <string>
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Van.h"
#include "Luxuryvan.h"
#include "Racecar.h"

namespace sdds {
    Vehicle* createInstance(std::istream& in);
}
#endif //!SDDS_UTILITIES_H