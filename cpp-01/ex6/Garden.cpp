//
// Created by robot on 3/12/26.
//

#include "Garden.hpp"

const std::string &Garden::get_owner() const
{
    return owner;
}

void Garden::add_plant(std::unique_ptr<Plant> p)
{
    std::cout << "Added " << p->name << " to " << owner << "'s garden" << std::endl;
    plants.emplace_back(std::move(p));
}

void Garden::grow_plants()
{
    std::cout << std::endl << owner << " is helping all plants grow..." << std::endl;
    size_t i = 0;
    while (i < plants.size()) {
        plants[i]->grow();
        ++i;
    }
    std::cout << std::endl;
}

const std::vector<std::unique_ptr<Plant>> &Garden::get_plants() const
{
    return plants;
}