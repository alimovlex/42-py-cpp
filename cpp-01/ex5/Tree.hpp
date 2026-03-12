//
// Created by robot on 3/12/26.
//
#pragma once
#include "Plant.hpp"

class Tree: Plant
{
public:
    int trunk_diameter;

    void produce_shade();
    Tree(std::string name, int height, int days, int trunk_diameter);
};

