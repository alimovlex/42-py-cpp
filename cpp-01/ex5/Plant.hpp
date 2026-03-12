//
// Created by robot on 3/12/26.
//
#pragma once
#include <iostream>
#include <cmath>

class Plant
{
public:
    std::string name;
    int height, days;

    Plant(std::string name, int height, int days):
            name(name), height(height), days(days) { }
};


