//
// Created by robot on 3/13/26.
//

#include "Plant.hpp"

void Plant::add_water(int amount)
{
    water += amount;
}

void Plant::info()
{
    std::cout << name << ": healthy (water: " << water << " " << sun << std::endl;
}