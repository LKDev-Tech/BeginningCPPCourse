#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours
    { "Tour Ticket Prices from Miami",
        {
            {
                "Colombia", {
                    { "Bogota", 8778000, 400.98 },
                    { "Cali", 2401000, 424.12 },
                    { "Medellin", 2464000, 350.98 },
                    { "Cartagena", 972000, 345.34 }
                },
            },
            {
                "Brazil", {
                    { "Rio De Janiero", 13500000, 567.45 },
                    { "Sao Paulo", 11310000, 975.45 },
                    { "Salvador", 18234000, 855.99 }
                },
            },
            {
                "Chile", {
                    { "Valdivia", 260000, 569.12 },
                    { "Santiago", 7040000, 520.00 }
            },
        },
            { "Argentina", {
                { "Buenos Aires", 3010000, 723.77 }
            }
        },
    }
    };

    // Unformatted display so you can see how to access the vector elements
    std::cout << std::setw(50) << tours.title << std::endl;
    // space country: 15, city: 20 Left aligned
    // space population: 15, price: 10
    std::cout << std::left << std::setw(15) << "Country" << std::setw(20) << "City" << std::right << std::setw(15) << "Population" << std::setw(12) << "Price" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;

    for (auto &country : tours.countries) {   // loop through the countries
        std::cout << std::left << std::setw(15) << country.name;
        bool first = true;
        for (auto &city : country.cities) {       // loop through the cities for each country
            if (first == true)
            {
                std::cout << std::left << std::setw(20) << city.name << std::right << std::setw(15) << city.population << std::setw(12) << city.cost << std::endl;
                first = false;
            }
            else
                std::cout << std::left << std::setw(15) << " " << std::setw(20) << city.name << std::right << std::setw(15) << city.population << std::setw(12) << city.cost << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}