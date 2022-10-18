/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 08/10/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include "Reservation.h"

namespace sdds {
    class Restaurant {
    private:
        /* data */
        Reservation** m_reservations{};
        size_t count{};
        void setEmpty();
    public:
        // Restaurant(/* args */) = default;
        Restaurant(const Reservation* reservations[], size_t cnt);
        size_t size() const;
        friend std::ostream& operator<< (std::ostream& out, const Restaurant& res);

        // The Rule of 5
        Restaurant(const Restaurant& res);
        Restaurant(Restaurant&& res);
        Restaurant& operator=(const Restaurant& res);
        Restaurant& operator=(Restaurant&& res);
        ~Restaurant();
    };
    
}


#endif // !SDDS_RESTAURANT_H