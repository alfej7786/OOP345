// Name: Alfej Savaya
// Seneca Student ID: 118823210
// Seneca email: aasavaya@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>
#include <string>

namespace sdds {
    class Utilities
    {
    private:
        /* data */
        size_t m_widthField;
        static char m_delimiter;
        std::string& trim(std::string& str);
    public:
        // Utilities(/* args */);
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();
    };
}


#endif // !SDDS_UTILITIES_H