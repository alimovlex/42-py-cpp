//
// Created by robot on 3/12/26.
//
#pragma once
#include <iostream>

class Plant
{
public:
    std::string name;
    int height;
    int days;
    Plant(std::string name, int height, int days);
    void grow(int cm);
    void age(int duration);
    void get_info();
};

