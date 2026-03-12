//
// Created by robot on 3/12/26.
//
#pragma once
#include "Plant.hpp"

class Vegetable: Plant
{
public:
    std::string harvest_season;
    std::string nutritional_value;

    Vegetable(std::string name, int height, int days,
              std::string harvest_season, std::string nutritional_value);
};
