#include <iostream>
#include <stdexcept>
#include <string>
#include "test_plant_checks.hpp"

int main(int argc, char** argv)
{
    std::cout << "=== Garden Plant Health Checker ===" << std::endl;
    test_plant_checks();
    std::cout << "All error raising tests completed!" << std::endl;
    return 0;
}
