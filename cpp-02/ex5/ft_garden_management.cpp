#include "GardenManager.hpp"

int main(int argc, char** argv)
{
    std::cout << "=== Garden Management System ===" << std::endl;
    GardenManager manager(30);
    Plant tomato("tomato", 2, 8);
    Plant lettuce("lettuce", 12, 8);
    Plant carrot("", 0, 8);

    std::vector<Plant> plants = {tomato, lettuce, carrot};
    manager.add_plants(plants);
    manager.water_plants(0);
    manager.check_plants();
    manager.recover();

    std::cout << "Garden Management system test complete!" << std::endl;

    return 0;
}
