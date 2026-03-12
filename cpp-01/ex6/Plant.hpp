//
// Created by robot on 3/12/26.
//
#pragma once
#include <iostream>
#include <vector>
#include <memory>

class Plant {
public:
    std::string name;
    int height;
    int growth{0};

    Plant(std::string n, int h) : name(std::move(n)), height(h) {}
    virtual ~Plant() = default;

    virtual void grow();

    int get_height() const;
    int get_growth() const;
    virtual int get_points() const;

    virtual void info() const;
};



