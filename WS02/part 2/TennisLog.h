/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 25/09/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H

#include <iostream>
#include <cstring>
#include <string>

namespace sdds {
    struct TennisMatch{
        std::string torneyID{};
        std::string torneyName{};
        unsigned int matchID{};  // a positive integer 
        std::string match_Winner{};
        std::string match_Loser{};
        operator bool() const;
    };
    std::ostream& operator<<(std::ostream& os, const TennisMatch& match);

    class TennisLog {
    private:
        /* data */
        TennisMatch* matches{};
        size_t numOfMatches{ 0 };

    public:
        TennisLog(/* args */);
        TennisLog(const char* filename);
        void addMatch(const TennisMatch& match);
        TennisLog findMatches(const char* playerName);
        const TennisMatch operator[](size_t index) const;
        operator size_t() const;

        // The Rule of 5
        TennisLog(const TennisLog& src); // Copy Constructor
        TennisLog& operator=(const TennisLog& src); // copy Assignment operator
        TennisLog(TennisLog&& src); // Move Constructor
        TennisLog& operator=(TennisLog&& src); // Move Assignment operator
        ~TennisLog(); // Destructor
    };
}


#endif // !SDDS_TENNISLOG_H