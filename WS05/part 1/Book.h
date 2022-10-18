#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>

namespace sdds {
    class Book
    {
    private:
        /* data */
        std::string m_author{};
        std::string m_title{};
        std::string m_country{};
        unsigned int m_year{};
        double m_price{};
        std::string m_description{};
    public:
        Book(/* args */);
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;;
        double& price();
        Book(const std::string& strBook);
        friend std::ostream& operator<<(std::ostream& os, const Book& book);
        std::string& trim(std::string& str);
    };
    
}

#endif // !SDDS_BOOK_H