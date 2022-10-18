/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 08/10/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <cstring>
#include "Reservation.h"

using namespace std;

namespace sdds {
    Reservation::Reservation() { ; }


    void Reservation::update(int day, int time){
        m_day = day;
        m_hour = time;
    }


    // Created Function Trim to cut whitespace from both ends
    string& trim(string& str) {
        bool trimmed = false;

        while (!trimmed)
        {
            trimmed = true;
            if (str.find(' ') == 0)
            {
                trimmed = false;
                str.erase(str.begin());
            }
            if (str.substr(str.size() - 1, 1).find(' ') != string::npos)
            {
                str.erase(str.end() - 1);
                trimmed = false;
            }
        } 
        return str;      
    }


    Reservation::Reservation(const std::string& res) {
        string temp = res; // copy
        size_t left = 0;
        size_t right = res.find(":");
        string id = temp.substr(left, right - left); //ID

        id = trim(id);
        strcpy(reservationID, id.c_str());

        left = right;
        right = res.find(",", left + 1);
        reservationName = res.substr(left + 1, right - left - 1);
        reservationName = trim(reservationName);

        left = right;
        right = res.find(",", left + 1);
        reservationEmail = res.substr(left + 1, right - left - 1);
        reservationEmail = trim(reservationEmail);

        left = right;
        right = res.find(",", left + 1);
        count = stoi(res.substr(left + 1, right - left - 1));

        left = right;
        right = res.find(",", left + 1);
        m_day = stoi(res.substr(left + 1, right - left - 1));

        left = right;
        right = res.find('\n', left + 1);
        m_hour = stoi(res.substr(left + 1));
    }


    ostream& operator<<(std::ostream& os, const Reservation& Res) {
        os << "Reservation ";
        os.width(10);
        os << right << Res.reservationID << ": ";

        os.width(20);
        os << right << Res.reservationName;

        os << left << "  <" << Res.reservationEmail << "> ";
        for (int i = Res.reservationEmail.length(); i <= 20; i++)
        {
            os << " ";
        }
        
        if (Res.m_hour >= 6 && Res.m_hour <= 9)
        {
            os << "Breakfast ";
        } else if(Res.m_hour >= 11 && Res.m_hour <= 15) {
            os << "Lunch ";
        } else if(Res.m_hour >= 17 && Res.m_hour <= 21) {
            os << "Dinner ";
        } else {
            os << "Drinks ";
        }
        os << "on day " << Res.m_day << " @ "<< Res.m_hour << ":00 for " << Res.count << (Res.count == 1 ? " person.\n" : " people.\n");

        return os;
    }


}