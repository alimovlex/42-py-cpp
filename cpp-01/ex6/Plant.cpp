//
// Created by robot on 3/12/26.
//

#include "Plant.hpp"

void Plant::grow()
{
    ++growth;
    std::cout << name << " grew 1cm" << std::endl;
}

int Plant::get_height() const
{
    return height + growth;
}

int Plant::get_growth() const
{
    return growth;
}

int Plant::get_points() const
{
    return height + growth;
}

void Plant::info() const
{
    std::cout << "- " << name << ": " << get_height() << "cm";
}