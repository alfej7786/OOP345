/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 09/11/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_DRIMESTATISTICS_H
#define SDDS_DRIMESTATISTICS_H
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <cstring>

namespace sdds {
    // Crime structure
    struct Crime
    {
        std::string m_province{};
        std::string m_district{};
        std::string crime{};
        size_t m_numOfCases{};
        size_t m_year{};
        size_t m_resolved{};
    };

    // Class CrimeStatistics
    class CrimeStatistics
    {
    private:
        /* data */
        std::vector<Crime> m_crime;
        std::string& trim(std::string& str);
    public:
        // CrimeStatistics(/* args */);
        CrimeStatistics(const char* filename);
        void display(std::ostream& out) const;
        void sort(const char*);
        void cleanList();
        bool inCollection(const char*) const;
        std::list<Crime> getListForProvince(const char*) const;
    };
        // Free Helpers
        std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
    
}

#endif // !SDDS_DRIMESTATISTICS_H