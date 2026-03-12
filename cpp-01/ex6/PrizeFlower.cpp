//
// Created by robot on 3/12/26.
//

#include "PrizeFlower.hpp"

int PrizeFlower::get_points() const
{
    return (get_height() + points) * 3;
}

void PrizeFlower::info() const
{
    FloweringPlant::info();
    std::cout << ", prize points: " << points;
}