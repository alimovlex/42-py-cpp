//
// Created by robot on 3/12/26.
//

#include "Plant.hpp"

Plant::Plant(std::string name, int height, int age):
        name(name), height(height), age(age)
{
    // this->name = name;
    // this->height = height;
    // this->age = age;
    std::cout << name << ": " << height << "cm, " << age <<  " days old";
    std::cout << std::endl;
}
