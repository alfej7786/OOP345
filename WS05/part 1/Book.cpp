
#include <iomanip>
#include "Book.h"

using namespace std;
namespace sdds {
    Book::Book() { ; }

    const string& Book::title() const{
        return m_title;
    }

    const string& Book::country() const{
        return m_country;
    }

    const size_t& Book::year() const {
        return m_year;
    }

    double& Book::price() {
        return m_price;
    }

    Book::Book(const string& strBook) {

    }

    string& Book::trim(string& str) {
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

    Book::Book(const string& strBook) {
        string trm{};
        size_t left{};
        size_t right{strBook.find(",")};
        m_author = strBook.substr(left, right);
        m_author = trim(m_author); // Trim the whitespace on both sides
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

    ostream& operator<<(ostream& os, const Book& book) {
        os.width(20);
        os << book.m_author << " | " ;
        os.width(22);
        os << book.m_title << " | " ;
        os.width(5);
        os << book.m_country << " | " ;
        os.width(4);
        os << book.m_country << " | " ;
        os.width(6);
        os.precision(2);
        os << book.m_price << " | " ;
        os << book.m_description << endl;

        return os;
    }

}