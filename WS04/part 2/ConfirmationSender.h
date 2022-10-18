/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 08/10/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"
namespace sdds {
    class ConfirmationSender {
    private:
        /* data */
        const Reservation** m_reservation{};
        size_t m_count{};

    public:
        ConfirmationSender(/* args */);
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs);

        // The Rule of 5:
        ConfirmationSender(const ConfirmationSender& cs);
        ConfirmationSender(ConfirmationSender&& cs);
        ConfirmationSender& operator=(const ConfirmationSender& cs);
        ConfirmationSender& operator=(ConfirmationSender&& cs);
        ~ConfirmationSender();
};
}

#endif // !SDDS_CONFIRMATIONSENDER_H
