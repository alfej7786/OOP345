

#include "Car.h"

using namespace std;
namespace sdds {
    Car::Car() { ; }

    // clear whitespaces
    std::string& trim(std::string& str) {
      bool trimmed = false;

      while (!trimmed) {
         trimmed = true;
         if (str.find(' ') == 0) {
            trimmed = false;
            str.erase(str.begin());
         }
         if (str.size() > 0 &&
             str.substr(str.size() - 1, 1).find(' ') != std::string::npos) {
            str.erase(str.end() - 1);
            trimmed = false;
         }
      }
      return str;
   }

    Car::Car(istream& is) {
        string token{}; 
        getline(is, token, ',');
        getline(is, token, ',');
        token = trim(token);
        m_maker = token;

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
        else {
            throw("Invalid record!");
        }

        // Speed
        getline(is, token, ',');
        token = trim(token);
        try
        {
            m_speed = stod(token);
        }
        catch(...)
        {
            throw("Invalid record!");
        }
    }

    string Car::condition() const {
        return (m_condition == New ? "new" : (m_condition == Used ? "used" : "broken"));
    }

    double Car::topSpeed() const {
        return m_speed;
    }

    void Car::display(std::ostream& out) const {
        out << "| ";
        out.width(10);
        out << right << m_maker << " | ";
        out.width(6);
        out << left << (m_condition == New ? "new" : (m_condition == Used ? "used" : "broken")) << " | ";
        out.precision(2);
        out.width(6);
        out << fixed << m_speed << " | ";
    }
}