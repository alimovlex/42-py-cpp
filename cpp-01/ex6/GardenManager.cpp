//
// Created by robot on 3/12/26.
//

#include "GardenManager.hpp"

GardenManager GardenManager::create_garden_network(const std::vector<std::string> &gardeners)
{
    GardenManager mgr;
    for (const auto& name : gardeners) {
        mgr.add_garden(name);
    }
    return mgr;
}

void GardenManager::add_garden(const std::string &name)
{
    gardens.emplace_back(std::make_unique<Garden>(name));
}

Garden *GardenManager::find_garden(const std::string &name) const
{
    size_t i = 0;
    while (i < gardens.size())
        if (gardens[i]->get_owner() == name)
            return gardens[i].get();
        else
            ++i;
    return nullptr;
}

void GardenManager::add_plant(const std::string &garden_name, std::unique_ptr<Plant> p)
{
    Garden* g = find_garden(garden_name);
    if (g)
        g->add_plant(std::move(p));
}

void GardenManager::grow_plants(const std::string &garden_name)
{
    Garden* g = find_garden(garden_name);
    if (g)
        g->grow_plants();
}

void GardenManager::get_scores() const
{
    std::cout << "Garden scores - ";
    size_t i = 0;
    while (i < gardens.size())
    {
        const Garden* g = gardens[i].get();
        int score = 0;
        const auto& vec = g->get_plants();
        size_t j = 0;
        while (j < vec.size())
        {
            score += vec[j]->get_points();
            ++j;
        }
        std::cout << g->get_owner() << ": " << score << ", ";
        ++i;
    }
    std::cout << std::endl;
}

void GardenManager::get_gardencount() const
{
    std::cout << "Total gardens managed: " << gardens.size() << std::endl;
}