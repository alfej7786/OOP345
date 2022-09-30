#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H

#include "Queue.h"

namespace sdds {
    template<typename T> 
    class UniqueQueue : public Queue<T, 100> {
        double count(const double& D) {
            return D < 0 ? -D : D;
        } 
    public: 
        bool push(const T& item) {
            bool add = false;
            for(unsigned int i = 0; i < this->size(); i++) {
                if(item == (*this)[i]) {
                    add = true;
                }
            }
            return (add == true) ? false : Queue<T, 100>::push(item);
        }


    template<>
    bool UniqueQueue<double>::push(const double& item) {
        bool add = false;
        for (unsigned int i = 0; i < this->size(); i++) {
            if(count((*this)[i] -  item) <= 0.05){
                add = true;
            }
        }
        return (add == false) ? false : Queue<double, 100>::push(item);
    }
    };
}


#endif // !SDDS_UNIQUEQUEUE_H
