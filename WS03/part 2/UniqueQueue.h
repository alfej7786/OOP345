/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 02/10/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H

#include <iostream>
#include <cmath>
#include <string>

#include "Queue.h"
#include "Dictionary.h"

namespace sdds {
    template<typename T> 
    class UniqueQueue : public Queue<T, 100> {

    public: 
        UniqueQueue() { ; }
        bool push(const T& item) {
            for(size_t i = 0; i < this->size(); i++) {
                if(item == this->m_item[i]) {
                    return false;
                }
            }
            return Queue<T, 100>::push(item);
        }
    };


    template<>
    bool UniqueQueue<double>::push(const double& item) {
        for (unsigned int i = 0; i < this->m_size; i++) {
            if (std::fabs(item - this->m_item[i]) <= 0.005) {
                return false;
            }
        }
        return Queue<double, 100>::push(item);
    };
}


#endif // !SDDS_UNIQUEQUEUE_H
