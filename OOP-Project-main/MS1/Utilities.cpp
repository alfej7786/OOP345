
#include "Utilities.h"

using namespace std;
namespace sdds {
    Utilities::Utilities() { ; }

    void Utilities::setFieldWidth(size_t newWidth) {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const{
        return m_widthField;
    }

    string Utilities::extractToken(const string& str, size_t& next_pos, bool& more) {
        string token;
        size_t pos; 
        size_t cnt{ 0 };

        pos = str.find(getDelimiter(), next_pos);
        for (size_t i = next_pos; i < pos; i++)
        {
            cnt++;
        }
        token = str.substr(next_pos, cnt);
        next_pos = pos + 1;

        try
        {
            if (token.empty()) 
            {
                more = false;
                throw "ERROR: No token.";
            }
            else
            {
                more = true;
                if (token.size() > getFieldWidth())
                {
                    setFieldWidth(token.size());
                }
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return token;        
    }

    void Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter() {
        return m_delimiter;
    }
}