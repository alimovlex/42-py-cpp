#include <iostream>
#include <string>
#include "Plant.hpp"

std::size_t Plant::instance_count = 0;

int main(int argc, char** argv)
{
    std::cout << "=== Plant Factory Output ===" << std::endl;
    Plant rose("Rose", 25, 30);
    Plant oak("Oak", 200, 365);
    Plant cactus("Cactus", 5, 90);
    Plant sunflower("Sunflower", 80, 45);
    Plant fern("Fern", 15, 120);
    std::cout << std::endl;
    std::cout << "Total plants created: " << Plant::get_objects_count() << std::endl;
    return 0;
}
