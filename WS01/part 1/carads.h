#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H
#include<iostream>

extern double g_taxrate;
extern double g_discount;
#define MAX_BRAND 10
#define MAX_MODEL 15

namespace sdds {

    void listArgs(int argc, char* argv[]);
    class Cars  {

    private:
        char m_brand[MAX_BRAND]{}; 
        char m_model [MAX_MODEL]{};
        int m_made_year{};
        double m_price{};
        char m_status = 'N' || 'U';
        bool m_discount{};
    public:
        Cars(/* args */);
        std::istream& read(std::istream& is);
        void display(bool reset);
        char getStatus();
        // operator bool() const;
    };

std::istream& operator>>(std::istream& is, Cars& car);
void operator>>(const Cars& car1, Cars& car2);
}
#endif // !SDDS_CARADS_H