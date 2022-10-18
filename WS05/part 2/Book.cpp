/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 16/10/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Book.h"
#include <iostream>

using namespace std;
namespace sdds
{
    Book::Book() { ; }

    const string &Book::title() const { 
        return m_title; 
    }

    const string &Book::country() const { 
        return m_country; 
    }

    const size_t &Book::year() const { 
        return m_year; 
    }

    double &Book::price() { 
        return m_price; 
    }

    string &Book::trim(string &str) {
        bool trim = false;

        while (!trim) {
            trim = true;
            if (str.find(' ') == 0) 
            {
                trim = false;
                str.erase(str.begin());
            }
            if (str.substr(str.size() - 1, 1).find(' ') != string::npos) {
                str.erase(str.end() - 1);
                trim = false;
            }
        }
        return str;
    }

    

    // Parses an input string describing a book into a Book object
    Book::Book(const string &strBook) {
        string trm{};
        size_t left{};
        size_t right{strBook.find(",")};

        m_author = strBook.substr(left, right);
        m_author = trim(m_author); // Trim the whitespace from both sides

        left = right;
        right = strBook.find(",", left + 1);
        m_title = strBook.substr(left + 1, right - left - 1);
        m_title = trim(m_title);

        left = right;
        right = strBook.find(",", left + 1);
        m_country = strBook.substr(left + 1, right - left - 1);
        m_country = trim(m_country);

        left = right;
        right = strBook.find(",", left + 1);
        trm  = strBook.substr(left + 1, right - left - 1);
        m_price = stod(trm);

        left = right;
        right  = strBook.find(",", left + 1);
        trm  = strBook.substr(left + 1, right - left - 1);
        m_year = stoi(trm);

        left = right;
        right = strBook.find('\n', left + 1);
        m_description = strBook.substr(left + 1, right - left - 1);
        m_description = trim(m_description);
    }

    ostream& operator<<(ostream& out, const Book& book)
    {
        out.width(20);
        out << book.m_author << " | ";
        out.width(22);
        out << book.m_title << " | ";
        out.width(5);
        out << book.m_country << " | ";
        out.width(4);
        out << book.m_year << " | ";
        out.width(6);
        out.precision(2);
        out << fixed << book.m_price << " | " << book.m_description << endl;

        return out;
    }
}