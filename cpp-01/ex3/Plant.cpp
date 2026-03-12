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
    instance_count++;
    std::cout << "Created: " << name << " (" << height << "cm, " << age <<  " days)";
    std::cout << std::endl;
}

std::size_t Plant::get_objects_count()
{
    return instance_count;
}