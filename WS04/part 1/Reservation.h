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
        unsigned char m_day{};
        unsigned char m_hour{};
        unsigned count{}; // counter
    public:
        Reservation(/* args */);
        void update(int day, int time);
        Reservation(const std::string& res);
        friend std::ostream& operator<<(std::ostream& os, const Reservation& Res);
    };

}


#endif // !SDDS_RESERVATION_H