#include <iostream>
#include <stdexcept>
#include <string>

void check_plant_health(std::string plant_name, int water_level, int sunlight_hours)
{
    if (plant_name.empty())
        throw std::invalid_argument("Error: plant name can't be empty!");
    else if (water_level > 10)
        throw std::invalid_argument("Error: water level is too high (max 10)");
    else if (water_level < 1)
       throw std::invalid_argument("Error: water level is too low (min 10)");
    else if (sunlight_hours > 12)
        throw std::invalid_argument("Error: sunlight hours is too high (max 12)");
    else if (sunlight_hours < 2)
        throw std::invalid_argument("Error: sunlight hours is too low (min 2)");
    else
        std::cout << "Plant " << plant_name << " is healthy!" << std::endl;
}

void test_plant_checks()
{
    try
    {
        std::cout << "Testing good values..." << std::endl;
        check_plant_health("tomato", 5, 6);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Testing empty plant name..." << std::endl;
        check_plant_health("", 5, 6);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Testing bad water level..." << std::endl;
        check_plant_health("tomato", 15, 6);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Testing bad sunlight hours..." << std::endl;
        check_plant_health("tomato", 5, 0);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "=== Garden Plant Health Checker ===" << std::endl;
    test_plant_checks();
    std::cout << "All error raising tests completed!" << std::endl;
    return 0;
}
