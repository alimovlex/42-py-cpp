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
    int age;
    Plant(std::string name, int height, int age);
    static std::size_t get_objects_count();
private:
    static std::size_t instance_count;
};


