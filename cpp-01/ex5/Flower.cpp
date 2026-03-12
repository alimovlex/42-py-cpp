//
// Created by robot on 3/12/26.
//

#include "Flower.hpp"

void Flower::bloom()
{
    std::cout << this->name << " is blooming beautifully!" << std::endl;
}

Flower::Flower(std::string name, int height, int days, std::string color):
        Plant(name, height, days), color(color)
{
    //this->color = color;
    std::cout << name << " (Flower): " << height << "cm, " << days << "days, ";
    std::cout << color << " color" << std::endl;
}