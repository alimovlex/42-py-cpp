//
// Created by robot on 3/12/26.
//
#pragma once
#include <iostream>

class SafePlant
{
public:
    void set_height(int new_height);
    void set_age(int new_age);
    int get_height();
    int get_age();
    void get_info();

    SafePlant(std::string name, int height, int age);

private:
    std::string name;
    int height;
    int age;
};

