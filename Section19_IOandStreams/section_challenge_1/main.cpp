#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

// struct is like a class by everything is public
// most of time in cpp it's just used to collect data
struct City { 
    std::string name;
    long population;
    double cost;
};

struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main (void)
{
    Tours tours
        {
            "Tours Ticket Prices from Miami",
            {
                {
                    "Colombia",
                    {
                        {"Bogota", 8778000, 400.98},
                        {"Cali", 2401000, 424.12},
                        {"Medellin", 2464000, 350.98},
                        {"Cartagena", 972000, 345.98}
                    },
                },
                {
                    "Brazil",
                    {
                        {"Rio De Janiero", 13500000, 567.45},
                        {"Sao Paulo", 11310000, 975.45},
                        {"Salvador", 18234000, 855.99}
                    },
                },
                {
                    "Chile",
                    {
                        {"Valdivia", 260000, 569.12},
                        {"Santiago", 7040000, 520.00}
                    },
                },
                {
                    "Argentina",
                    {
                        {"Buenos Aires", 3010000, 723.77}
                    }
                }
            }
        };

    // ruler of 70
    std::cout << "1234567890123456789012345678901234567890123456789012345678901234567890" << std::endl;
    std::cout << std::endl;

    const int totalWidth {70};
    const int fw1 {20}; // field width
    const int fw2 {20}; 
    const int fw3 {15}; 
    const int fw4 {15}; 

    // Unformatted
    int titleLength = tours.title.length();
    std::cout << std::setw((totalWidth - titleLength)/2) << "" << tours.title << std::endl;
    std::cout << std::endl;
    
    std::cout << std::left  << std::setw(fw1) << "Country"
                            << std::setw(fw2) << "City"
              << std::right << std::setw(fw3) << "Population"
                            << std::setw(fw4) << "Price" << std::endl;
    
    std::cout << "----------------------------------------------------------------------" << std::endl;

    std::cout << std::fixed << std::setprecision(2) << std::showpoint; // setup for price format

    for (auto country : tours.countries) {
        for (size_t i = 0; i < country.cities.size(); i++) {
            std::cout << std::left  << std::setw(fw1) << ((i == 0) ? country.name : "");
            std::cout << std::left  << std::setw(fw2) << country.cities.at(i).name
                      << std::right << std::setw(fw3) << country.cities.at(i).population
                                    << std::setw(fw4) << country.cities.at(i).cost 
                                    << std::endl;
        }
    }

    std::cout << std::endl; 

    return 0;
}