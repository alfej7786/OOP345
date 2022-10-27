#include "Utilities.h"

namespace sdds
{
    Vehicle *createInstance(std::istream &is)
    {
        Vehicle *v{};
        std::string line{};
        std::getline(is, line);
        if (line.length() > 0)
        {
            std::istringstream ss(line);
            line = trim(line);
            if (line[0] == 'c' || line[0] == 'C')
            {
                v = new Car(ss);
            }
            else if (line[0] == 'v' || line[0] == 'V')
            {
                v = new Van(ss);
            }
            else if (line[0] == 'r' || line[0] == 'R')
            {
                v = new Racecar(ss);
            }
            else if (line[0] == 'l' || line[0] == 'L')
            {
                v = new Luxuryvan(ss);
            }
            else
            {
                throw("Unrecognized record type [" + line.substr(0, 1) + "]");
            }
        }
        return v;
    }
}