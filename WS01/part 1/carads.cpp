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
namespace sdds {

    double g_taxrate = 0;
    double g_discount = 0;
    Cars::Cars(): m_price(0), m_discount(false) {

    }

    void listArgs(int argc, char* argv[]) {
		cout << "Command Line:" << endl;
		cout << "--------------------------" << endl;
		for (auto i = 0; i < argc; i++)
		{
			cout << "  " << i + 1 << ": " << argv[i] << endl;
	}
		cout << "--------------------------\n" << endl;
    } 

    std::istream& Cars::read(std::istream& is)
	{
		char DStatus = '\0';
		if (is) {
			is >> m_status;
			is.ignore();
			is.getline(m_brand, 10, ',');
			is.getline(m_model, 15, ',');
			is >> m_made_year;
			is.ignore();
			is >> m_price;
			is.ignore();
			is >> DStatus;
			if (DStatus == 'Y') { m_discount = true; }
		}
		return is;
	}

    void Cars::display(bool reset) {
		static int counter = 0;
		cout.width(2);
		cout.setf(std::ios::left);
		cout << ++counter;
		cout << ". ";
		if (m_brand)
		{
			cout.width(10);
			cout.setf(std::ios::left);
			cout << m_brand;
			cout << "|";

			cout.width(15);
			cout.setf(std::ios::left);
			cout << m_model;
			cout << " | ";

			cout.width(4);
			cout << m_made_year;
			cout << " |";

			cout.width(12);
			cout.precision(2);
			cout.setf(std::ios::left);
			cout << (m_price + (m_price * g_taxrate));
			cout << "|";
			if (m_discount) {
				cout.setf(ios::right);
				cout.precision(2);
				cout.width(12);
				cout << (m_price - (m_price * g_discount));
			}
			cout << endl;
		}
		else {
			cout << " No Car" << endl;
		}
		if (reset)
		{
			counter = 0;
		}
	}

    char Cars::getStatus() {
        return m_status;
    }

    // Cars::operator bool()const {
    //     bool status = false;
    //     if(m_status == "N")
    //     {
    //         status = true;
    //     }
    //     else {
    //         status = false;
    //     }
    //     return m_status;
    // }

}