#ifndef SDDS_DRIMESTATISTICS_H
#define SDDS_DRIMESTATISTICS_H
#include <string>
#include <vector>

namespace sdds {
    // Crime structure
    struct Crime
    {
        std::string m_province{};
        std::string m_district{};
        std::string crime{};
        size_t m_numOfCases{};
        size_t m_year{};
        size_t m_numOfresolved{};
    };

    // Class CrimeStatistics
    class CrimeStatistics
    {
    private:
        /* data */
        std::vector<Crime> m_crime;
        std::string& trim(std::string& str);
    public:
        CrimeStatistics(/* args */);
        CrimeStatistics(const char* filename);
        void display(std::ostream& out) const;
    };
        // Free Helpers
        std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
    
}

#endif // !SDDS_DRIMESTATISTICS_H