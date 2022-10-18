/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 08/10/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

const int RES_ID_SIZE{10};

namespace sdds {
    class Reservation
    {
    private:
        /* data */
        char reservationID[RES_ID_SIZE + 1] {};
        std::string reservationName{};
        std::string reservationEmail{};
        unsigned int numOfPeople{};
        unsigned int m_day{};
        unsigned int m_hour{};
        unsigned count{}; // counter
    public:
        Reservation(/* args */);
        void update(int day, int time);
        Reservation(const std::string& res);
        friend std::ostream& operator<<(std::ostream& os, const Reservation& Res);
    };

}


#endif // !SDDS_RESERVATION_H