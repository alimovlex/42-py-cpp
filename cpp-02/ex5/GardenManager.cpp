//
// Created by robot on 3/14/26.
//

#include "GardenManager.hpp"

void GardenManager::add_plants(std::vector<Plant> &plants)
{
    std::cout << "Adding plants to garden..." << std::endl;
    try
    {
        for (auto& plant: plants)
        {
            if (plant.name.empty())
                throw std::invalid_argument("Plant name cannot be empty!");
            else
                std::cout << "Added " << plant.name << " successfully" << std::endl;
            this->plants.push_back(plant);
        }
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Error: adding plant: " << e.what() << std::endl;
    }
}

void GardenManager::water_plants(int amount)
{
    std::cout << "Watering plants..." << std::endl;
    std::cout << "Opening watering system" << std::endl;

    try
    {
        if (plants.empty())
            throw GardenError("no plants to water");
        int consumption = plants.size() * amount;

        if (consumption == 0)
            throw WaterError("0 water used");
        else if (consumption > water)
            throw WaterError("not enough water in tank");
        else
            water -= consumption;

        for (auto& plant: plants)
        {
            plant.add_water(amount);
            std::cout << "Watering " << plant.name << " - success" << std::endl;
        }
    }
    catch (const GardenError& e)
    {
        std::cout << "Error watering plants: " << e.what() << std::endl;
    }
    finally cleanup([]{
        std::cout << "Closing watering system (cleanup)" << std::endl;
        std::cout << std::endl;
    });
}

void GardenManager::check_plant_health(Plant &plant)
{
    if (plant.water > 10)
        throw PlantError("water level is too high (max 10");
    else if (plant.water < 1)
        throw PlantError("water level is too low (min 1)");
    else if (plant.sun > 12)
        throw PlantError("sunlight hours are too high (max 12)");
    else if (plant.sun < 2)
        throw PlantError("sunlight hours are too low (min 2)");
    else
        plant.info();
}

void GardenManager::check_plants()
{
    std::cout << "Checking plant health..." << std::endl;
    for (auto& plant: plants)
    {
        try
        {
            this->check_plant_health(plant);
        }
        catch (const PlantError& e)
        {
            std::cout << "Error checking " << plant.name << ": " << e.what() << std::endl;
        }
    }
}

void GardenManager::recover()
{
    std::cout << "Testing error recovery..." << std::endl;
    try
    {
        if (water < tanksize)
            throw WaterError("not enough water in tank");
        else
            std::cout << "Water tank OK!" << std::endl;
    }
    catch (const WaterError& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
        water = tanksize;
        std::cout << "System recovered and continuing" << std::endl;
    }
}