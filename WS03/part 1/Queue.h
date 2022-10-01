#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H
#include "Dictionary.h"

namespace sdds {
    template <typename T, unsigned int CAPACITY> 
    class Queue {
        T m_item[CAPACITY]{};
        unsigned int m_size{};
        T dummy{};
    public:
        Queue(){};
        bool push(const T& item) {
            bool add = false;
            if (m_size < CAPACITY) {
                m_item[m_size] = item;
                m_size++;
                add = true;
            }
            return add;
        }

        void pop() {
			T tempQueue = m_item[0];
			for (size_t i = 0; i < m_size - 1; i++) {
				m_item[i] = m_item[i + 1];
			}
			if (m_size > 0) m_size--;
			return tempQueue;
		}


        unsigned int size() const { return m_size; }


        std::ostream& display(std::ostream& ostr = std::cout) {
            ostr << "----------------------" << std::endl;
            ostr << "| Dictionary Content |" << std::endl;
            ostr << "----------------------" << std::endl;
            for (unsigned int i = 0; i < m_size; i++)
            {
                ostr << m_item[i] << std::endl;
            }
            ostr << "----------------------" << std::endl;
            return ostr;            
        }


        T& operator[](unsigned int index) {
            // if (index >= 0 && index < m_size){
            //     m_item[index];
            // }
            // return dummy;
        return index < m_size ? m_item[index] : dummy;
        }

    };

    template<>
    Queue<Dictionary, 100>::Queue() {
        Dictionary a("Empty Term", "Empty Substitute");
        dummy = a;
    }
}

#endif // !SDDS_QUEUE_H