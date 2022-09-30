#include <iostream>
#include "Dictionary.h"

using namespace std;

namespace sdds {
    ostream& Dictionary::display(ostream& ostr){
        ostr.width(20);
        ostr.setf(ios::right);
        ostr << getTerm();
        ostr.unsetf(ios::right);
        ostr.setf(ios::left);
        ostr << ": " << getDefinition();
        return ostr;
    }


    ostream& operator<<(std::ostream& ostr, Dictionary& dictionary) {
        return dictionary.display(ostr);
    }

    bool operator==(const Dictionary& lhs, const Dictionary& rhs) {
        return lhs.getTerm() == rhs.getTerm();
    }
}