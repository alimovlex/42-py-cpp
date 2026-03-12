//
// Created by robot on 3/12/26.
//

#include "Plant.hpp"

Plant::Plant(std::string name, int height, int days):
        name(name), height(height), days(days)
{
    // this->name = name;
    // this->height = height;
    // this->days = days;
}

void Plant::grow(int cm)
{
    height += cm;
}

void Plant::age(int duration)
{
    days+=duration;
}

void Plant::get_info()
{
    std::cout << name << ": " << height << "cm, " << days << " days old";
}