#include <iostream>
#include <string>
#include "Plant.hpp"

int main(int argc, char** argv)
{
    Plant rose("Rose", 25, 30);
    std::cout << "=== Day 1 ===" << std::endl;
    rose.get_info();
    std::cout << std::endl;
    int first_day_height = rose.height;
    std::cout << "=== Day 7 ===" << std::endl;
    rose.grow(6);
    rose.age(6);
    rose.get_info();
    std::cout << std::endl;
    std::cout << "Growth this week: +" << rose.height - first_day_height << "cm";
    std::cout << std::endl;
    return 0;
}
