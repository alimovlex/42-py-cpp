#include <iostream>
#include <string>
#include "SafePlant.hpp"

int main()
{
    std::cout << "=== Garden Security System ===" << std::endl;
    SafePlant rose = SafePlant("Rose", 25, 30);
    rose.set_height(25);
    rose.set_age(30);
    rose.set_height(-5);
    std::cout << std::endl;
    std::cout << "Current plant: ";
    rose.get_info();
    return 0;
}
