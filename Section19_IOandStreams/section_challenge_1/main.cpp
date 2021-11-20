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
    // Unformatted
    std::cout << std::setw(50) << tours.title << std::endl;
    std::cout << std::endl;
    
    std::cout << std::left  << std::setw(20) << "Country"
                            << std::setw(20) << "City"
              << std::right << std::setw(15) << "Population"
                            << std::setw(15) << "Price" << std::endl;
    
    std::cout << "----------------------------------------------------------------------" << std::endl;
    
    for (auto country : tours.countries) {
        std::cout << std::left << std::setw(20) << country.name;
        for (auto city : country.cities) {
            std::cout << std::left  << std::setw(20) << city.name
                      << std::right << std::setw(15) << city.population
                                    << std::fixed << std::setprecision(2) << std::showpoint 
                                    << std::setw(15) << city.cost
                      << std::endl  << std::setw(20) << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl; 

    return 0;
}