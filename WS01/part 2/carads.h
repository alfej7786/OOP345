/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 18/09/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H
#include<iostream>

extern double g_taxrate;
extern double g_discount;
// #define MAX_BRAND 10
#define MAX_MODEL 15

namespace sdds {

    void listArgs(int argc, char* argv[]);
    class Cars  {

    private:
        char* m_brand{}; 
        char m_model [MAX_MODEL]{};
        int m_made_year{};
        double m_price{};
        char m_status{};
        bool m_discount{};
    public:
        Cars(/* args */);
        Cars(const Cars &cars);
        void read(std::istream& is);
        void display(bool reset);
        char getStatus();
        operator bool();
        Cars& operator=(const Cars &cars);
        ~Cars();
        // operator bool() const;
    };

std::istream& operator>>(std::istream& is, Cars& car);
void operator>>(const Cars& car1, Cars& car2);
}
#endif // !SDDS_CARADS_H