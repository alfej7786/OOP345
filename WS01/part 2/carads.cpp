/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 18/09/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <cstring>
#include <iomanip>
#include <string>
#include "carads.h"

using namespace std;

double g_taxrate = 0.13;
double g_discount = 0.05;
namespace sdds {

    Cars::Cars(){
        m_price = 0;
        m_status = '\0';
        m_model[0] = '\0';
        m_made_year = 0;
        m_discount = false;
        m_brand = nullptr;
    }

    Cars::Cars(const Cars &cars)
    {
        if (cars.m_brand == nullptr)
        {
            m_brand = nullptr;
        }
        else
        {
            m_brand = new char[strlen(cars.m_brand) + 1];
            strcpy(m_brand, cars.m_brand);
        }
        m_status = cars.m_status;
        m_made_year = cars.m_made_year;
        m_brand = cars.m_brand;
        m_price = cars.m_price;
        strcpy(m_model, cars.m_model);
    }

    Cars &Cars::operator=(const Cars &cars)
    {
        if (this != &cars)
        {
            if (m_brand == nullptr)
            {
                m_brand = nullptr;
            }
            else
            {
                delete[] m_brand;
                m_brand = nullptr;
            }
            if (cars.m_brand != nullptr)
            {
                m_brand = new char[strlen(cars.m_brand) + 1];
                strcpy(m_brand, cars.m_brand);
            }
            strcpy(m_model, cars.m_model);
            m_price = cars.m_price;
            m_status = cars.m_status;
            m_discount = cars.m_discount;
            m_made_year = cars.m_made_year;
        }
        return *this;
    }

    Cars::~Cars()
    {
        if (m_brand != nullptr)
            delete[] m_brand;
        m_brand = nullptr;
    }

    void listArgs(int argc, char* argv[]) {
        cout << "Command Line:\n";
        cout << "--------------------------\n";
        for (int i = 0; i < argc; i++)
        {
            cout << setw(3)
                << i + 1 << ": "
                << argv[i] << endl;
        }
        cout << "--------------------------\n\n";
    }

    void Cars::read(istream &is)
    {
        if (!is.good())
        {
            return;
        }
        else
        {
            
            if (m_brand != nullptr)
            {
                delete[] m_brand;
            }
            m_brand = nullptr;
            string line;
            is >> m_status;
            is.ignore(1000, ',');
            getline(is, line, ',');
            m_brand = new char[strlen(line.c_str()) + 1];
            strcpy(m_brand, line.c_str());
            is.getline(m_model, 15, ',');
            is >> m_made_year;
            is.ignore(1000, ',');
            is >> m_price;
            is.ignore(1000, ',');
            
            char discStatus;
            is >> discStatus;
            if (is.peek() == '\n')
                is.ignore();
            
            if (discStatus == 'Y')
                m_discount = true;
            else
                m_discount = false;
        }
    }

    void Cars::display(bool reset)
    {
        static int counter = 0;
        if (reset) {
            counter = 0;
        }
        counter++;
        cout << setw(2) << left << counter << ". ";
        if (m_brand[0] != '\0')
        {
            double prc_tax = m_price * (1 + g_taxrate);
            double prc_dic = prc_tax * (1 - g_discount);

            cout << setw(10) << left << m_brand << "| ";
            cout << setw(15) << left << m_model << "| ";
            cout << setw(4) << right << m_made_year << " |";
            cout << setw(12) << right << fixed << setprecision(2) << prc_tax << "|";
            if (m_discount) {
                cout << setw(12) << right << fixed << setprecision(2) << prc_dic;
            }
            cout << endl;
        }
        else
        {
            cout << "No Car" << endl;
        }
    }

    char Cars::getStatus() {
        return m_status;
    }

    Cars::operator bool() {
        return m_status == 'N';
    }

    istream &operator>>(istream &is, Cars &car)
    {
        car.read(is);
        return is;
    }
    void operator>>(const Cars &car1, Cars &car2)
    {
        car2 = car1;
    }

    // Cars::operator bool()const {
    //     bool status = false;
    //     if(m_status == 'N')
    //     {
    //         status = true;
    //     }
    //     else {
    //         status = false;
    //     }
    //     return m_status;
    // }
}