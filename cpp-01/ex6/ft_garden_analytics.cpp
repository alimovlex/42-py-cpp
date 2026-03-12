#include "GardenManager.hpp"
#include "FloweringPlant.hpp"
#include "PrizeFlower.hpp"
#include "GardenStats.hpp"

int main(int argc, char** argv)
{
    std::cout << "=== Garden Management System Demo ===" << std::endl;

    GardenManager manager = GardenManager::create_garden_network({"Alice", "Bob"});

    manager.add_plant("Alice", std::make_unique<Plant>("Oak Tree", 100));
    manager.add_plant("Alice", std::make_unique<FloweringPlant>("Rose", 25, "red"));
    manager.add_plant("Alice", std::make_unique<PrizeFlower>("Sunflower", 50, "yellow", 10));

    manager.grow_plants("Alice");

    manager.add_plant("Bob", std::make_unique<FloweringPlant>("Rose", 25, "red"));

    Garden* aliceGarden = manager.find_garden("Alice");
    if (aliceGarden)
        GardenStats::report(*aliceGarden);

    manager.get_scores();
    manager.get_gardencount();

    return 0;
}
