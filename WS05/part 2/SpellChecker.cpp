/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 16/10/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <fstream>
#include "SpellChecker.h"

using namespace std;
namespace sdds
{
    SpellChecker::SpellChecker() { ; }
    
    
    SpellChecker::SpellChecker(const char* filename) {
        if (filename != nullptr)
        {
            ifstream file(filename);
            if (file)
            {
                size_t index{};
                while (file && index < SIZE)
                {
                    size_t left{};
                    size_t right{};
                    string line;

                    getline(file, line, '\n');
                    right = line.find(' ');
                    m_badWords[index] = line.substr(left, right);

                    left = line.find_first_not_of(' ', right + 1);
                    m_goodWords[index] = line.substr(left);
                    index++;
                }
            }
            else
            {
                throw("Bad file name!");
            }
        }
        else
        {
            throw("Bad file name!");
        }
    }

    void SpellChecker::operator()(string &text) {
        for (size_t i = 0; i < SIZE; i++)
        {
            size_t index = text.find(m_badWords[i]);
            while (index != string::npos)
            {
                text.replace(index, m_badWords[i].length(), m_goodWords[i]);
                m_corrected[i]++;
                index = text.find(m_badWords[i]);
            }
        }
    }

    void SpellChecker::showStatistics(ostream &out) const {
        out << "Spellchecker Statistics" << endl;
        for (size_t i = 0; i < SIZE; i++)
        {
            out.width(15);
            out << right << m_badWords[i] << ": " << m_corrected[i] << " replacements" << endl;
        }
    }
}