/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 09/11/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "CrimeStatistics.h"

using namespace std;
namespace sdds
{
    // CrimeStatistics::CrimeStatistics(/* args */) { ; }

    string &CrimeStatistics::trim(string &str)
    {
        bool trim = false;

        while (!trim)
        {
            trim = true;
            if (str.find(' ') == 0)
            {
                trim = false;
                str.erase(str.begin());
            }
            if (str.size() > 0 && str.substr(str.size() - 1, 1).find(' ') != std::string::npos)
            {
                str.erase(str.end() - 1);
                trim = false;
            }
        }
        return str;
    }

    CrimeStatistics::CrimeStatistics(const char *filename)
    {
        ifstream ifs(filename);
        if (ifs)
        {
            while (ifs)
            {
                Crime crime{};
                char line[25 + 1];
                string token{};

                // Province
                ifs.get(line, 26);
                token = string(line);
                token = trim(token);
                crime.m_province = token;

                // District
                ifs.get(line, 26);
                token = string(line);
                token = trim(token);
                crime.m_district = token;

                // Crime
                ifs.get(line, 26);
                token = string(line);
                token = trim(token);
                crime.crime = token;

                // Year
                ifs.get(line, 6);
                crime.m_year = atoi(line);

                // Cases
                ifs.get(line, 6);
                crime.m_numOfCases = atoi(line);

                // Resolved Cases
                ifs.get(line, 6);
                crime.m_resolved = atoi(line);

                getline(ifs, token);
                m_crime.push_back(crime);
            }
        }
        else
        {
            throw("File Not Valid!");
        }
    }

    void CrimeStatistics::display(ostream &out) const
    {
        for (auto i = m_crime.cbegin(); i < m_crime.cend(); i++)
        {
            out << *i << endl;
        }
        unsigned total{};
        total = accumulate(m_crime.cbegin(), m_crime.cend(), 0, [](unsigned left, Crime right)
                           { return left + right.m_numOfCases; });
        out << "----------------------------------------------------------------------------------------" << endl;
        out << "|                                                                 Total Crimes:";
        out.width(7);
        out << right << total << " |" << endl;

        total = accumulate(m_crime.cbegin(), m_crime.cend(), 0, [](unsigned left, Crime right)
                           { return left + right.m_resolved; });

        out << "|                                                         Total Resolved Cases:";
        out.width(7);
        out << right << total << " |" << endl;
    }

    std::ostream &operator<<(std::ostream &out, const Crime &theCrime)
    {
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
        out << right << theCrime.m_resolved << " |";

        return out;
    }

    void CrimeStatistics::sort(const char *field)
    {
        if (strcmp(field, "Province") == 0)
        {
            std::sort(m_crime.begin(), m_crime.end(), [](Crime m, Crime n)
            { 
                return m.m_province < n.m_province; 
            });
        }

        else if (strcmp(field, "Crime") == 0)
        {
            std::sort(m_crime.begin(), m_crime.end(), [](Crime m, Crime n)
            { 
                return m.crime < n.crime; 
            });
        }

        else if (strcmp(field, "Cases") == 0)
        {
            std::sort(m_crime.begin(), m_crime.end(), [](Crime m, Crime n)
            { 
                return m.m_numOfCases < n.m_numOfCases; 
            });
        }

        else if (strcmp(field, "Resolved") == 0)
        {
            std::sort(m_crime.begin(), m_crime.end(), [](Crime m, Crime n)
            { 
                return m.m_resolved < n.m_resolved; 
            });
        }
    }

    bool CrimeStatistics::inCollection(const char *crime) const
    {
        return std::count_if(m_crime.cbegin(), m_crime.cend(), [=](Crime c)
        { 
            return c.crime == crime; 
        }) > 0;
    }

    std::list<Crime> CrimeStatistics::getListForProvince(const char *m_province) const
    {
        std::size_t size = std::count_if(m_crime.cbegin(), m_crime.cend(), [=](Crime c)
        { 
            return c.m_province.compare(m_province) == 0; 
        });

        std::list<Crime> line(size);
        std::copy_if(m_crime.cbegin(), m_crime.cend(), line.begin(), [=](Crime c)
        { 
            return strcmp(c.m_province.c_str(), m_province) == 0; 
        });
        return line;
    }

    void CrimeStatistics::cleanList()
    {
        std::vector<Crime> line(m_crime.size());
        std::transform(m_crime.cbegin(), m_crime.cend(), line.begin(), [](Crime c)
        {
            if (c.crime.compare("[None]") == 0) 
            {
                c.crime = "";
            }
            return c; 
        });
        m_crime = line;
    }

}