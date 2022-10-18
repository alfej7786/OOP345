/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 16/10/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace sdds {
    class Book
    {
        /* data */
        std::string m_author{};
        std::string m_title{};
        std::string m_country{};
        size_t m_year{};
        double m_price{};
        std::string m_description{};
        std::string& trim(std::string& str);

    public:
        Book(/* args */);
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        Book(const std::string& strBook);
        friend std::ostream &operator<<(std::ostream& out, const Book& book);
        template <typename T>
        void fixSpelling(T&spellChecker) {
            spellChecker(m_description);
        }
    };

}

#endif // !SDDS_BOOK_H