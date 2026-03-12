#include <iostream>
#include <string>
#include "Plant.hpp"

int main(int argc, char** argv)
{
    std::cout << "=== Garden Plant Registry ===" << std::endl;
    Plant rose("Rose", 25, 30);
    Plant sunflower("Sunflower", 80, 45);
    Plant cactus("Cactus", 15, 120);
    return 0;
}
