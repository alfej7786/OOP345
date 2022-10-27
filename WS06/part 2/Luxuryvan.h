#ifndef SDDS_LUXURYVAN_H
#define SDDS_LUXURYVAN_H

#include "Van.h"
#include "Car.h"

namespace sdds {
    class Luxuryvan : public Van
    {
        std::string m_consumption{};

    public:
        Luxuryvan(std::istream &in);
        void display(std::ostream &out) const;
        std::string consumption() const;
    };
} // namespace sdds

#endif //! SDDS_LUXURYVAN_H