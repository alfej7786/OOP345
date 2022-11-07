/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 06/11/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include "Van.h"
using namespace std;
namespace sdds
{
    Van::Van(istream &in)
    {
        string tag, type, purpose, condition, topSpeed;
        getline(in, tag, ',');
        tag.erase(0, tag.find_first_not_of(" "));
        tag.erase(tag.find_last_not_of(" ") + 1);
        if (tag == "v" || tag == "V" || tag == "l" || tag == "L")
        {
            getline(in, m_maker, ',');
            m_maker.erase(0, m_maker.find_first_not_of(" "));
            m_maker.erase(m_maker.find_last_not_of(" ") + 1);

            getline(in, type, ',');
            type.erase(0, type.find_first_not_of(" "));
            type.erase(type.find_last_not_of(" ") + 1);
            if (type == "p" || type == "P" || type == "" || type == " ")
                m_type = "pickup";
            if (type == "m" || type == "M")
                m_type = "mini-bus";
            if (type == "c" || type == "C")
                m_type = "camper";
            if (m_type != "pickup" && m_type != "mini-bus" && m_type != "camper")
                throw string("Invalid record!");

            getline(in, purpose, ',');
            purpose.erase(0, purpose.find_first_not_of(" "));
            purpose.erase(purpose.find_last_not_of(" ") + 1);
            if (purpose == "d" || purpose == "D" || purpose == "" || purpose == " ")
                m_purpose = "delivery";
            if (purpose == "p" || purpose == "C")
                m_purpose = "passenger";
            if (purpose == "c" || purpose == "C")
                m_purpose = "camping";
            if (m_purpose != "delivery" && m_purpose != "passenger" && m_purpose != "camping")
                throw string("Invalid record!");

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
                m_topSpeed = stod(topSpeed);
            }
            else
            {
                throw string("Invalid record!");
            }
        }
    }

    string Van::condition() const
    {
        return m_condition;
    }

    string Van::type() const
    {
        return m_type;
    }

    string Van::usage() const
    {
        return m_purpose;
    }

    double Van::topSpeed() const
    {
        return m_topSpeed;
    }
    void Van::display(ostream &out) const
    {
        if (m_maker.length() >= 8)
        {
            out << "|" << right << setw(9) << m_maker << " | " 
            << left << setw(12) << this->type() << " | " 
            << setw(12) << this->usage() << " | " 
            << setw(6) << this->condition() << " | " 
            << setw(6) << fixed << setprecision(2) 
            << this->topSpeed() << " |";
        }
        else
        {
            out << "| " << right << setw(8) << m_maker << " | " 
            << left << setw(12) << this->type() << " | " 
            << setw(12) << this->usage() << " | " << setw(6) 
            << this->condition() << " | " << setw(6) << fixed 
            << setprecision(2) << this->topSpeed() << " |";
        }
    }
}