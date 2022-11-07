/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 06/11/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iomanip>
#include "Car.h"

using namespace std;
namespace sdds
{
    Car::Car()
    {
    }
    Car::Car(istream &in)
    {
        string tag, condition, topSpeed;
        getline(in, tag, ',');
        tag.erase(0, tag.find_first_not_of(" "));
        tag.erase(tag.find_last_not_of(" ") + 1);
        if (tag == "C" || tag == "c" || tag == "r" || tag == "R")
        {
            getline(in, m_maker, ',');
            m_maker.erase(0, m_maker.find_first_not_of(" "));
            m_maker.erase(m_maker.find_last_not_of(" ") + 1);

            getline(in, condition, ',');
            condition.erase(0, condition.find_first_not_of(" "));
            condition.erase(condition.find_last_not_of(" ") + 1);
            if (condition == "n" || condition == "N" || condition == "" || condition == " ")
                m_condition = "new";
            if (condition == "u" || condition == "U")
                m_condition = "used";
            if (condition == "b" || condition == "B")
                m_condition = "broken";
            if (m_condition != "new" && m_condition != "used" && m_condition != "broken")
                throw string("Invalid record!");

            getline(in, topSpeed, ',');
            topSpeed.erase(0, topSpeed.find_first_not_of(" "));
            topSpeed.erase(topSpeed.find_last_not_of(" ") + 1);
            if (isdigit(*topSpeed.c_str()))
            {
                m_speed = stod(topSpeed);
            }
            else
            {
                throw string("Invalid record!");
            }
        }
    }

    double Car::topSpeed() const
    {
        return m_speed;
    }

    string Car::condition() const
    {
        return m_condition;
    }

    void Car::display(ostream &out) const
    {
        out << "| " << setw(10) << right << m_maker << " | " 
            << setw(6) << left << m_condition
            << " | " << setw(6) << fixed << setprecision(2)
            << topSpeed() << " |";
    }
}