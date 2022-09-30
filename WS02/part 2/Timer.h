/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 25/09/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <chrono>

namespace sdds {
// Timer Class
class Timer {
    std::chrono::time_point<std::chrono::system_clock> m_start;
    public:
    void start();     
    long long stop(); 
    };
}
#endif // !SDDS_TIMER_H