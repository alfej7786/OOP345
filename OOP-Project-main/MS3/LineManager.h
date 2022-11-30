#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "Workstation.h"
#include "Utilities.h"

namespace sdds {
    class LineManager
    {
    private:
        /* data */
        std::vector<Workstation*> m_activeLine;
        size_t m_cntCustomerOrder;
        Workstation* m_firstStation;
    public:
        // LineManager(/* args */);
        LineManager(const std::string& file, const std::vector<Workstation*>& stations);
        void reorderStations();
        bool run(std::ostream& os);
        void display(std::ostream& os) const;
        // ~LineManager();
    };
}

#endif // !SDDS_LINEMANAGER_H