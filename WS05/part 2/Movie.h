/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 16/10/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <string>

namespace sdds {
    class Movie
    {
    private:
        /* data */
        std::string m_title{};
        size_t m_year{};
        std::string m_description{};
        std::string& trim(std::string& str);
    public:
        Movie(/* args */);
        const std::string& title() const;
        Movie(const std::string& strMovie);
        template <typename T> 
        void fixSpelling(T& spellChecker) {
            spellChecker(m_description);
            spellChecker(m_title);
        }
        friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
    };
}

#endif // !SDDS_MOVIE_H