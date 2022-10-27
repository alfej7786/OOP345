#include <iomanip>
#include "Station.h"

using namespace std;
namespace sdds {
size_t Station::m_widthField = 0u;
size_t Station::id_generator = 0u;
    Station::Station() { ; }

    Station::Station(const string& name) {
        Utilities newName;
        size_t next_pos = 0;
        bool more = false;

        if (!name.empty())
        {
            more = true;
        }
        m_name = newName.extractToken(name, next_pos, more);
        m_serialNumber = stoi(newName.extractToken(name, next_pos, more));
        m_numOfItems = stoi(newName.extractToken(name, next_pos, more));
        m_description = name.substr(next_pos);
        m_stationID = ++id_generator;
        
        if(m_widthField < newName.getFieldWidth())
        {
            m_widthField = newName.getFieldWidth();
        }
    }

    const string& Station::getItemName() const {
        return m_name;
    }

    size_t Station::getNextSerialNumber() {
        return m_serialNumber;
    }

    size_t Station::getQuantity() const {
        return m_numOfItems;
    }

    void Station::updateQuantity() {
        m_numOfItems--;
        if (m_numOfItems < 0)
        {
            m_numOfItems = 0;
        }
    }

    void Station::display(std::ostream& os, bool full) const {
        if (!full)
        {
            os << left << setw(3) << m_stationID << " | " <<  left << setw(m_widthField) << 
            m_name << " | " << setw(6) << m_serialNumber << " | " << endl;
        }
        else if(full)
        {
            os << left << setw(3) << m_stationID << " | " <<  left << setw(m_widthField) << 
            m_name << " | " << setw(6) << m_serialNumber << " | " << right << setw(4) << 
            m_numOfItems << " | " << m_description << endl;
        }
    }
}