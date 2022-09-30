/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 25/09/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Timer.h"

namespace sdds{
// TIMER
    void Timer::start() { m_start = std::chrono::system_clock::now(); }


    long long Timer::stop() {
    auto end = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - m_start);
    return duration.count();
    }
}