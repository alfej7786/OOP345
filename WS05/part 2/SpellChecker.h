/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 16/10/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>

namespace sdds {
    constexpr size_t SIZE = 6;
    class SpellChecker
    {
    private:
        /* data */
        std::string m_badWords[SIZE]{};
        std::string m_goodWords[SIZE]{};
        int m_corrected[SIZE]{};

    public:
        SpellChecker(/* args */);
        SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}

#endif // !SDDS_SPELLCHECKER_H