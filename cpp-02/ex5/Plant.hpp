//
// Created by robot on 3/13/26.
//
#pragma once
#include <iostream>
#include <vector>

class Plant
{
public:
    std::string name;
    int water;
    int sun;

    Plant(std::string name, int water, int sun):
            name(name), water(water), sun(sun) { }

    void add_water(int amount);
    void info();
};

