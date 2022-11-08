#include <iostream>
#include <fstream>
#include "CrimeStatistics.h"

using namespace std;
namespace sdds {
    // CrimeStatistics::CrimeStatistics(/* args */) { ; }

    string& CrimeStatistics::trim(string& str) {
        bool trim = false;

        while (!trim) {
            trim = true;
            if (str.find(' ') == 0) 
            {
                trim = false;
                str.erase(str.begin());
            }
            if (str.size() > 0 && str.substr(str.size() - 1, 1).find(' ') != std::string::npos) {
                str.erase(str.end() - 1);
                trim = false;
            }
        }
        return str;
    }


    CrimeStatistics::CrimeStatistics(const char* filename) {
        ifstream ifs(filename);
        if (ifs)
        {
            while (ifs)
            {
                Crime crime{};
                char temp[25 + 1];
                string token{};
    
                // Province
                ifs.get(temp, 26);
                token = string(temp);
                token = trim(token);
                crime. m_province = token;

                // District
                ifs.get(temp, 26);
                token = string(temp);
                token = trim(token);
                crime. m_district = token;

                // Crime
                ifs.get(temp, 26);
                token = string(temp);
                token = trim(token);
                crime.crime = token;

                // Year
                ifs.get(temp, 6);
                crime.m_year = atoi(temp);

                // Cases
                ifs.get(temp, 6);
                crime.m_numOfCases = atoi(temp);

                // Resolved Cases
                ifs.get(temp, 6);
                crime.m_numOfresolved = atoi(temp);

                getline(ifs, token);
                m_crime.push_back(crime);
            }
        }
        else
        {
            throw("File Not Valid!");
        }
    }


    void CrimeStatistics::display(ostream& out) const {
        for (auto it = m_crime.cbegin(); it < m_crime.cend(); it++) 
        {
            out << *it << endl;
        }
    }


    std::ostream& operator<<(std::ostream& out, const Crime& theCrime) {
        // Province
        out << "| ";
        out.width(21);
        out.fill(' ');
        out << left << theCrime.m_province << " | ";

        // District
        out.width(15);
        out.fill(' ');
        out << left << theCrime.m_district << " | ";

        // Crime
        out.width(20);
        out.fill(' ');
        out << left << theCrime.crime << " | ";

        // Year
        out.width(6);
        out.fill(' ');
        out << right << theCrime.m_year << " | ";

        // Cases
        out.width(4);
        out.fill(' ');
        out << right << theCrime.m_numOfCases << " | ";

        // Cases Resolved
        out.width(3);
        out.fill(' ');
        out << right << theCrime.m_numOfresolved << " |";

        return out;
    }
}