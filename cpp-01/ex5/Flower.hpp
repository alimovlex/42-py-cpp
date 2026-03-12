//
// Created by robot on 3/12/26.
//
#pragma once
#include "Plant.hpp"

class Flower: Plant
{
public:
    std::string color;

    void bloom();
    Flower(std::string name, int height, int days, std::string color);
};
