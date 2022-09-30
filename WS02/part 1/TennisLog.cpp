/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 25/09/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iomanip>
#include <fstream>
#include "TennisLog.h"
using namespace std;

namespace sdds {
TennisMatch::operator bool() const {
    return matchID > 0 && torneyID.length() > 0;
}


ostream& operator<<(ostream& os, const TennisMatch& match) {
    if(!match){
        os << "Empty Match";
    }
    else {
        os.fill('.'); os.width(20); os << right << "Tourney ID" << " : "; os.width(30); os << left << match.torneyID << endl;
        os.fill('.'); os.width(20); os << right << "Match ID" << " : "; os.width(30); os << left << match.matchID << endl;
        os.fill('.'); os.width(20); os << right << "Tourney" << " : "; os.width(30); os << left << match.torneyName << endl;
        os.fill('.'); os.width(20); os << right << "Winner" << " : "; os.width(30); os << left << match.match_Winner << endl;
        os.fill('.'); os.width(20); os << right << "Loser" << " : "; os.width(30); os << left << match.match_Loser << endl;
    }
    return os;
}


// Default Constructor
TennisLog::TennisLog() {}


// TennisLog::TennisLog(const char* filename){
//     if(filename) {
//         ifstream fin(filename);
//         string line;
//         cin.ignore(1000, \n); // Skip first line
//         for (unsigned i = 0; fin; i++)
//         {
//             line.clear();
//             numOfMatches++;
//         }
//         fin.clear();
//         fin.seekg(0);
//         for (unsigned i = 0; i < numOfMatches; i++)
//         {
//             line.clear();
//             getline(fin, line);
//         }
//     }
// }

TennisLog::TennisLog(const char* filename){
    ifstream fstr(filename);
    string line; 

    size_t m_numMatches{0};
    if (fstr.is_open()) {
        getline(fstr, line); 
            while (fstr) {
                getline(fstr, line);
                m_numMatches++;
            }
        m_numMatches--;
        matches = new TennisMatch[m_numMatches];
        fstr.clear();
        fstr.seekg(0);
        getline(fstr, line);
        while (fstr) {
            getline(fstr, line, ',');
            if (fstr) {
                matches[numOfMatches].torneyID = line;
                getline(fstr, line, ',');
                matches[numOfMatches].torneyName = line;
                getline(fstr, line, ',');
                matches[numOfMatches].matchID = stoul(line);
                getline(fstr, line, ',');
                matches[numOfMatches].match_Winner = line;
                getline(fstr, line);
                matches[numOfMatches].match_Loser = line;
                numOfMatches++;
        }
    }
    fstr.close();
    } else {
        cerr << "Error: Could not open file: " << filename << std::endl;
    }
}


void TennisLog::addMatch(const TennisMatch& match) {
    TennisMatch* addMatches = new TennisMatch[numOfMatches + 1];
        for (size_t i = 0; i < numOfMatches; i++) {
            addMatches[i] = matches[i];
        }
        delete[] matches;
        matches = addMatches;
        matches[numOfMatches] = match;
        numOfMatches++;
}



TennisLog TennisLog::findMatches(const char* playerName) {
    TennisLog find;
    for (size_t i = 0; i < numOfMatches; i++) {
        if (strcmp(playerName, matches[i].match_Winner.c_str()) == 0 ||
            strcmp(playerName, matches[i].match_Loser.c_str()) == 0) {
            find.addMatch(matches[i]);
        }
    }
    return find;
}

    
const TennisMatch TennisLog::operator[] (size_t index) const{
    TennisMatch match;
    if (index < numOfMatches) {
        match = matches[index];
    }
    return match;
}


    TennisLog::operator size_t() const {
        return this->numOfMatches;
    }

    

    // Part 
    
    // Copy constructor
    TennisLog::TennisLog(const TennisLog& src) {
        *this = src;
    }


    // Move constructor
    TennisLog::TennisLog(TennisLog&& src) {
        *this = std::move(src);
    }


    // Copy assignment operator
    TennisLog& TennisLog::operator=(const TennisLog& src) {
        if(this != &src) {
            delete[] matches;
            numOfMatches = src.numOfMatches;
            matches = new TennisMatch[numOfMatches];
                for (size_t i = 0; i < numOfMatches; i++)
                {
                    matches[i] = src.matches[i];
                }
            }
        return *this;
        }


    // Move Assignment operator
    TennisLog& TennisLog::operator=(TennisLog&& src) {
    if (this != &src && src.numOfMatches > 0) {
        numOfMatches = src.numOfMatches;
        delete[] matches;
        matches = src.matches;
        src.matches = nullptr;
        src.numOfMatches = 0;
    }
    return *this;
    }


    // destructor
    TennisLog::~TennisLog() {
        delete[] matches;
    }
}