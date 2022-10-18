/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 02/10/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Dictionary.h"

using namespace std;

namespace sdds {
    ostream& Dictionary::display(ostream& ostr) const {
        ostr.width(20);
        ostr.setf(ios::right);
        ostr << getTerm();
        ostr.unsetf(ios::right);
        ostr.setf(ios::left);
        ostr << ": " << getDefinition();
        return ostr;
    }


    ostream& operator<<(std::ostream& ostr, const Dictionary& dictionary) {
        return dictionary.display(ostr);
    }

    bool operator==(const Dictionary& lhs, const Dictionary& rhs) {
        return lhs.getTermConst() == rhs.getTermConst();
    }
}