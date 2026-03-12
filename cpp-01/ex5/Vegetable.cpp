//
// Created by robot on 3/12/26.
//

#include "Vegetable.hpp"

Vegetable::Vegetable(std::string name, int height, int days, std::string harvest_season,
                     std::string nutritional_value):
        Plant(name, height, days), harvest_season(harvest_season), nutritional_value(nutritional_value)
{
    //this->harvest_season = harvest_season;
    //this->nutritional_value = nutritional_value;
    std::cout << name << " (Vegetable): " << height << "cm, " << days << "days, ";
    std::cout << harvest_season << std::endl;
    std::cout << name << " is rich in " << nutritional_value << std::endl;
}