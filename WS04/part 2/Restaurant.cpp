/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 08/10/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Restaurant.h"

using namespace std;

namespace sdds {
    void Restaurant::setEmpty() {
        for (size_t i = 0; i < count; i++)
        {
            delete m_reservations[i];
        }
        delete[] m_reservations;        
    }

    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
        m_reservations = new Reservation*[cnt];
        for (size_t i = 0; i < cnt; i++)
        {
            m_reservations[i] = new Reservation;
            *m_reservations[i] = *reservations[i];
        }
        count = cnt;
    }


    size_t Restaurant::size() const {
        return count;
    }

    ostream& operator<< (std::ostream& out, const Restaurant& res) {
        static unsigned call_cnt = 0;
        call_cnt++;

        out <<  "--------------------------\n"
                "Fancy Restaurant (" << call_cnt << ")\n"
                "--------------------------\n";

        if (res.count > 0 )
        {
            for (size_t i = 0; i < res.count; i++)
            {
                out << *res.m_reservations[i];
            }
        }
        else {
            out << "This restaurant is empty!\n";
        }
        out << "--------------------------\n";
        return out;
    }


    // The Rule of 5 follows:
    Restaurant::Restaurant(const Restaurant& res) { 
        *this = res; 
    }

    
    Restaurant::Restaurant(Restaurant&& res) {
        *this = move(res);
    }

    
    Restaurant& Restaurant::operator=(const Restaurant& res) {
        if (this != &res) 
        {
            setEmpty();
            m_reservations = new Reservation*[res.count];

            for (size_t i = 0; i < res.count; i++) 
            {
                m_reservations[i] = new Reservation;
                *m_reservations[i] = *res.m_reservations[i];
            }
            count = res.count;
        }
        return *this;
    }

    
    Restaurant& Restaurant::operator=(Restaurant&& res) {
        if (this != &res) 
        {
            setEmpty();
            count = res.count;
            m_reservations = res.m_reservations;
            res.m_reservations = nullptr;
            res.count = 0;
        }
        return *this;
    }

    Restaurant::~Restaurant() {
        setEmpty();
    }
}