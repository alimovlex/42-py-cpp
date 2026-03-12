//
// Created by robot on 3/12/26.
//
#pragma once
#include "Plant.hpp"

class FloweringPlant : public Plant {
public:
    std::string color;

    FloweringPlant(std::string n, int h, std::string c)
            : Plant(std::move(n), h), color(std::move(c)) {}
    int get_points() const override;
    void info() const override;
};

