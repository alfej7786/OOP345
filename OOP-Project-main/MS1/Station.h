
#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>
#include <string>
#include "Utilities.h"

namespace sdds {
    class Station
    {
    private:
        /* data */
        int m_stationID;
        std::string m_name;
        std::string m_description;
        size_t m_serialNumber;
        size_t m_numOfItems;
        static size_t m_widthField;
        static size_t id_generator;
    public:
        // Station(/* args */);
        Station(const std::string& record);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
}
#endif //!SDDS_STATION_H