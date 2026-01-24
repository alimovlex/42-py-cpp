#include <exception>
#include <iostream>
#include <string>
#include <vector>

class GardenError: public std::exception { };

class PlantError: public GardenError
{
    private:
        std::string message;
    public:
        PlantError(const std::string& msg): message(msg) { }
        const char* what() const noexcept
        {
            return message.c_str();
        }
};

class WaterError: public GardenError
{
    private:
        std::string message;
    public:
    WaterError(const std::string& msg): message(msg) { }
    const char* what() const noexcept
    {
        return message.c_str();
    }
};

void test_moisture(int moisture)
{
    if (moisture < 1)
        throw PlantError("The tomato plant is wilting!");
    else
        std::cout << "Plant OK!" << std::endl;
}

void test_water(int water)
{
    if (water < 1)
        throw WaterError("Not enough water in the tank!");
    else
        std::cout << "Water OK!" << std::endl;
}

void test_errors()
{
    try
    {
        std::cout << "Testing PlantError..." << std::endl;
        test_moisture(0);
    }
    catch (const PlantError& e)
    {
        std::cout << "Caught PlantError: '" << " " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Testing WaterError..." << std::endl;
        test_water(0);
    }
    catch (const WaterError& e)
    {
        std::cout << "Caught WaterError: '" << " " << e.what() << std::endl;
    }

    std::vector<std::exception> exceptions;
    std::cout << "Testing all garden errors..." << std::endl;

    try
    {
        test_moisture(0);
    }
    catch (const PlantError& e)
    {
        exceptions.push_back(e);
    }

    try
    {
        test_water(0);
    }
    catch (const WaterError& e)
    {
        exceptions.push_back(e);
    }

    for(auto& i: exceptions)
        std::cout << "Caught a garden error: " << i.what() << std::endl;
    std::cout << "All custom error types work correctly!" << std::endl;
}

int main()
{
    test_errors();
    return 0;
}
