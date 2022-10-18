/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 08/10/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "ConfirmationSender.h"

using namespace std;

namespace sdds {
    ConfirmationSender::ConfirmationSender(/* args */){ ; }


    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
        bool add = false;

        // if already in the array
        for (size_t i = 0; i < m_count && !add; i++)
        {
            if (m_reservation[i] == &res)
            {
                add = true;
            }
        }
        if (!add)
        {
            const Reservation** temp = new const Reservation*[m_count + 1];
            for (size_t i = 0; i < m_count; i++)
            {
                temp[i] = m_reservation[i];
            }
            temp[m_count++] = &res;
            delete[] m_reservation;
            m_reservation = temp;
        }
        return *this;
    }


    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
        bool add = false; size_t i;

        for (i = 0; i < m_count && !add; i++)
        {
            if (m_reservation[i] == &res)
            {
                add = true;
            }
        }
        if (add)
        {
            const Reservation** temp = new const Reservation*[m_count - 1];
            i--;
            --m_count;
            for (size_t j = i; j < m_count; j++)
            {
                m_reservation[j] = m_reservation[j + 1];
            }
            for (size_t j = 0; j < m_count; j++)
            {
                temp[j] = m_reservation[j];
            }
            delete[] m_reservation;
            m_reservation = temp;            
        }
        return *this;
    }


    ostream& operator <<(std::ostream& os, const ConfirmationSender& sender) {
        os <<   "--------------------------\n"
                "Confirmations to Send\n"
                "--------------------------\n";

        if(sender.m_count > 0) {
            for (size_t i = 0; i < sender.m_count; i++)
            {
                os << *sender.m_reservation[i];
            }
        }
        else {
            os << "There are no confirmations to send!\n";
        }
        os << "--------------------------\n";
        return os;
    }


    // The Rule of 5 follows: 
    ConfirmationSender::ConfirmationSender(const ConfirmationSender& res) {
        *this = res;
    }
        
    ConfirmationSender::ConfirmationSender(ConfirmationSender&& res) {
        *this = move(res);
    }
    
    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& res) {
        if (this != &res)
        {
            delete[] m_reservation;
            m_count = res.m_count;
            m_reservation = new const Reservation*[m_count];
            for (size_t i = 0; i < m_count; i++)
            {
                m_reservation[i] = res.m_reservation[i];
            }
        }
        return *this;
    }
    
    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& res) {
        if (this != &res)
        {
            delete[] m_reservation;
            m_count = res.m_count;
            m_reservation = res.m_reservation;
            res.m_reservation = nullptr;
            res.m_count = 0;
        }
        return *this;
    }
    
    ConfirmationSender::~ConfirmationSender() {
        delete[] m_reservation;
    }
}