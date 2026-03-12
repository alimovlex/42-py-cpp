//
// Created by robot on 3/12/26.
//

#include "SafePlant.hpp"

SafePlant::SafePlant(std::string name, int height, int age):
        name(name), height(height), age(age)
{
    // this->name = name;
    // this->height = height;
    // this->age = age;
    std::cout << "Plant Created: " << this->name << std::endl;
}

void SafePlant::set_height(int new_height)
{
    if (new_height < 0)
    {
        std::cout << "Invalid operation attempted: " << new_height << "cm [REJECTED]";
        std::cout << std::endl;
        std::cout << "Security: Negative height rejected" << std::endl;
    }
    else
    {
        this->height = new_height;
        std::cout << "Height updated: " << this->height << "cm [OK]" << std::endl;
    }
}

void SafePlant::set_age(int new_age)
{
    if (new_age < 0)
    {
        std::cout << "Invalid operation attempted: " << new_age << "days [REJECTED]";
        std::cout << std::endl;
        std::cout << "Security: Negative age rejected" << std::endl;
    }
    else
    {
        this->age = new_age;
        std::cout << "Age updated: " << this->age << "days [OK]" << std::endl;
    }
}

int SafePlant::get_height()
{
    return height;
}

int SafePlant::get_age()
{
    return age;
}

void SafePlant::get_info()
{
    std::cout << name << ": " << height << "cm, " << age << " days" << std::endl;
}
