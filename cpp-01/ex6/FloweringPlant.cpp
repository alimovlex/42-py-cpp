//
// Created by robot on 3/12/26.
//

#include "FloweringPlant.hpp"

int FloweringPlant::get_points() const
{
    return get_height() * 2;
}

void FloweringPlant::info() const
{
    Plant::info();
    std::cout << ", " << color << " flowers (blooming)";
}