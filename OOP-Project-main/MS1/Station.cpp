// Name: Alfej Savaya
// Seneca Student ID: 118823210
// Seneca email: aasavaya@myseneca.ca
// Date of completion: 08-Nov-2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iomanip>
#include "Station.h"

using namespace std;
namespace sdds {
size_t Station::m_widthField = 1;
size_t Station::id_generator = 0;
    // Station::Station() { ; }

    Station::Station(const string& name) {
        Utilities newName{};
        size_t next_pos{};
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
        return m_serialNumber++;
    }

    size_t Station::getQuantity() const {
        return m_numOfItems;
    }

    void Station::updateQuantity() {
        if (m_numOfItems > 0)
	{
		m_numOfItems--;
	}
    }

    void Station::display(std::ostream& os, bool full) const {
      os.width(3);
      os.fill('0');
      os << std::right << m_stationID << " | ";
      os.width(m_widthField);
      os.fill(' ');
      os << std::left << m_name << " | ";
      os.width(6);
      os.fill('0');
      os << std::right << m_serialNumber << " | ";
      os.fill(' ');
      if (full) {
         // os << " ";
         os.width(4);
         os << std::right << m_numOfItems << " | " << m_description;
      }
      os << std::endl;
    }
}