/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 16/10/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "Movie.h"

using namespace std;
namespace sdds {
    Movie::Movie()  { ; }

    string &Movie::trim(string &str)
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
            if (str.substr(str.size() - 1, 1).find(' ') != string::npos)
            {
                str.erase(str.end() - 1);
                trim = false;
            }
        }
        return str;
    }

    Movie::Movie(const string &strMovie)
    {
        string trm{};
        size_t left{};
        size_t right = strMovie.find(",");

        m_title = strMovie.substr(left, right);
        m_title = trim(m_title);
        left = right;

        right = strMovie.find(",", left + 1);
        trm = strMovie.substr(left + 1, right - left - 1);
        m_year = stoi(trm);
        left = right;

        right = strMovie.find('\n', left + 1);
        m_description = strMovie.substr(left + 1, right - left - 1);
        m_description = trim(m_description);
    }

    const string &Movie::title() const {
        return m_title; 
    }

    ostream &operator<<(ostream& os, const Movie& movie)
    {
        os.width(40);
        os << movie.m_title << " | ";
        os.width(4);
        os << movie.m_year << " | " << movie.m_description << endl;
        return os;
    }
}