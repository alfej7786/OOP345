
#include "Van.h"

using namespace std;
namespace sdds
{
    Van::Van() { ; }

    Van::Van(istream &is)
    {
        string token{};
        getline(is, token, ',');

        getline(is, token, ',');
        token = trim(token);
        m_maker = token;

        // Get the vehicle type
        getline(is, token, ',');
        token = trim(token);
        if (token[0] == 'p')
        {
            m_type = Pickup;
        }
        else if (token[0] == 'm')
        {
            m_type = Minibus;
        }
        else if (token[0] == 'c')
        {
            m_type = Camper;
        }
        else
        {
            throw("Invalid record!");
        }

        getline(is, token, ',');
        token = trim(token);
        if (token[0] == 'd')
        {
            m_purpose = Delivery;
        }
        else if (token[0] == 'p')
        {
            m_purpose = Passenger;
        }
        else if (token[0] == 'c')
        {
            m_purpose = Camping;
        }
        else
        {
            throw("Invalid record!");
        }

        getline(is, token, ',');
        token = trim(token);
        if (token.find_first_not_of(' ') == string::npos)
        {
            m_condition = New;
        }
        else if (token[0] == 'n')
        {
            m_condition = New;
        }
        else if (token[0] == 'u')
        {
            m_condition = Used;
        }
        else if (token[0] == 'b')
        {
            m_condition = Broken;
        }
        else
        {
            throw("Invalid record!");
        }

        getline(is, token, ',');
        token = trim(token);
        try
        {
            m_speed = stod(token);
        }
        catch (...)
        {
            throw("Invalid record!");
        }
    }

    string Van::condition() const
    {
        return (m_condition == New ? "new" : (m_condition == Used ? "used" : "broken"));
    }

    double Van::topSpeed() const
    {
        return m_speed;
    }

    string Van::type() const
    {
        return (m_type == Pickup ? "pickup" : (m_type == Minibus ? "mini-bus" : "camper"));
    }

    string Van::usage() const
    {
        return (m_purpose == Delivery ? "delivery" : (m_purpose == Passenger ? "passenger" : "camping"));
    }

    void Van::display(ostream &out) const
    {
        out << "| ";
        out.width(8);
        out << right << m_maker << " | ";
        out.width(12);
        out << left << (m_type == Pickup ? "pickup" : (m_type == Minibus ? "mini-bus" : "camper")) << " | ";
        out.width(12);
        out << left << (m_purpose == Delivery ? "delivery" : (m_purpose == Passenger ? "passenger" : "camping")) << " | ";
        out.width(6);
        out << left << (m_condition == New ? "new" : (m_condition == Used ? "used" : "broken")) << " | ";
        out.precision(2);
        out.width(6);
        out << fixed << m_speed << " |";
    }
}
