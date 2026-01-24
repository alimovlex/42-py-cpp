#include <iostream>
#include <string>

void ft_seed_inventory(std::string seed_type, int quantity, std::string unit)
{
    auto it = seed_type.begin();
    *it = static_cast<char>(std::toupper(*it));
    if (unit == "packets")
        std::cout << seed_type << " seeds: " << quantity << " " << unit << " " << "available";
    else if(unit == "grams")
        std::cout << seed_type << " seeds: " << quantity << " " << unit << " " << "total";
    else if (unit == "area")
    {
        unit = "square meters";
        std::cout << seed_type << " seeds: " << "covers" << " " << quantity << " " << unit;
    }
    else
        std::cout << "Unknown unit type";
    std::cout << std::endl;
}

int main(void)
{
    ft_seed_inventory("tomato", 15, "packets");
    ft_seed_inventory("carrot", 8, "grams");
    ft_seed_inventory("lettuce", 12,"area");
    return 0;
}
