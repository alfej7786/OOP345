
#include "Utilities.h"

using namespace std;
namespace sdds
{
    // Utilities::Utilities() { ; }

    char Utilities::m_delimiter{','};

    string &Utilities::trim(string &str)
    {
        bool trimmed = false;

        while (!trimmed)
        {
            trimmed = true;
            if (str.find(' ') == 0)
            {
                trimmed = false;
                str.erase(str.begin());
            }
            if (str.size() > 0 &&
                str.substr(str.size() - 1, 1).find(' ') != string::npos)
            {
                str.erase(str.end() - 1);
                trimmed = false;
            }
        }
        return str;
    }

    void Utilities::setFieldWidth(size_t newWidth)
    {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const
    {
        return m_widthField;
    }

    string Utilities::extractToken(const string &str, size_t &next_pos, bool &more)
    {
        string token{};
        size_t right = str.find(m_delimiter, next_pos);
        if (right == next_pos)
        {
            more = false;
            throw("Invalid next position!");
        }
        if (right != string::npos)
        {
            token = str.substr(next_pos, right - next_pos);
            token = trim(token);
            more = true;
            if (m_widthField < right - next_pos)
            {
                m_widthField = right - next_pos;
            }
            next_pos = right + 1;
        }
        else
        {
            token = str.substr(next_pos);
            token = trim(token);
            more = false;
        }
        return token;
    }

    void Utilities::setDelimiter(char newDelimiter)
    {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }
}