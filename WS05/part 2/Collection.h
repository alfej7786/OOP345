/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 16/10/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <stdexcept>
#include <string>
namespace sdds {
    template <typename T>
    class Collection
    {
        std::string m_name{};
        T *m_arrSize{};
        size_t m_size{};
        void (*m_observer)(const Collection<T> &, const T &) {};

    public:
        Collection() { ; }

        Collection(const std::string &name) { m_name = name; }

        Collection(const Collection &) = delete;

        Collection &operator=(const Collection &) = delete;

        ~Collection() { 
            delete[] m_arrSize; 
        }

        const std::string &name() const { 
            return m_name; 
        }

        size_t size() const { 
            return m_size; 
        }
        void setObserver(void (*observer)(const Collection<T> &, const T &)) {
            m_observer = observer;
        }
        Collection<T> &operator+=(const T &item) {
            bool have = false;
            for (size_t i = 0; i < m_size; i++)
            {
                if (m_arrSize[i].title().compare(item.title()) == 0)
                {
                    have = true;
                }
            }
            if (!have)
            {
                T *temp = new T[m_size + 1];

                for (size_t i = 0; i < m_size; i++)
                {
                    temp[i] = m_arrSize[i];
                }

                delete[] m_arrSize;
                temp[m_size] = item;
                m_arrSize = temp;
                m_size++;

                if (m_observer)
                    m_observer(*this, item);
            }
            return *this;
        }

        T &operator[](size_t idx) const{
            if (idx >= m_size)
            {
                throw std::out_of_range("Bad index [" + std::to_string(idx) +
                                        "]. Collection has [" +
                                        std::to_string(m_size) + "] items.");
            }
            return m_arrSize[idx];
        }

        T *operator[](const std::string &title) const        {
            T *value = nullptr;
            for (size_t i = 0; i < m_size; i++)
            {
                if (title.compare(m_arrSize[i].title()) == 0)
                {
                    value = &m_arrSize[i];
                }
            }
            return value;
        }

        friend std::ostream &operator<<(std::ostream &os, const Collection<T> &collection)
        {
            for (size_t i = 0; i < collection.m_size; i++)
            {
                os << collection.m_arrSize[i];
            }
            return os;
        }
    };
}

#endif