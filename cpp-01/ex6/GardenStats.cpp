//
// Created by robot on 3/12/26.
//

#include "GardenStats.hpp"

void GardenStats::report(const Garden &garden)
{
    std::cout << "=== " << garden.get_owner() << "'s Garden Report ===" << std::endl;
    get_plants(garden);
    get_plant_stats(garden);
    get_plant_types(garden);
    validate_heights(garden);
    std::cout << std::endl;
}

void GardenStats::get_plants(const Garden &garden)
{
    std::cout << "Plants in garden:" << std::endl;
    const auto& vec = garden.get_plants();
    size_t i = 0;
    while (i < vec.size())
    {
        vec[i]->info();
        std::cout << std::endl;
        ++i;
    }
    std::cout << std::endl;
}

void GardenStats::get_plant_stats(const Garden &garden)
{
    int total_growth = 0;
    const auto& vec = garden.get_plants();
    size_t i = 0;
    while (i < vec.size())
    {
        total_growth += vec[i]->get_growth();
        ++i;
    }
    std::cout << "Plants added: " << vec.size()
              << ", total growth: " << total_growth << "cm" << std::endl;
}

void GardenStats::get_plant_types(const Garden &garden)
{
    int regular = 0, flowering = 0, prize = 0;
    const auto& vec = garden.get_plants();
    size_t i = 0;
    while (i < vec.size())
    {
        const Plant* p = vec[i].get();
        if (dynamic_cast<const Plant*>(p) && !dynamic_cast<const FloweringPlant*>(p))
            ++regular;
        else if (dynamic_cast<const FloweringPlant*>(p) && !dynamic_cast<const PrizeFlower*>(p))
            ++flowering;
        else if (dynamic_cast<const PrizeFlower*>(p))
            ++prize;
        ++i;
    }
    std::cout << "Plant types: " << regular << " regular, "
              << flowering << " flowering, " << prize << " prize flowers\n";
}

void GardenStats::validate_heights(const Garden &garden)
{
    bool ok = true;
    const auto& vec = garden.get_plants();
    size_t i = 0;
    while (i < vec.size())
    {
        if (vec[i]->get_height() < 0)
        {
            ok = false;
            break;
        }
        ++i;
    }
    std::cout << "Height validation test: ";
    if (ok)
        std::cout << "true";
    else
        std::cout << "false";
    std::cout << std::endl;
}