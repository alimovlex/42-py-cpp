//
// Created by robot on 3/12/26.
//
#pragma once
#include "FloweringPlant.hpp"

class PrizeFlower : public FloweringPlant {
public:
    int points;

    PrizeFlower(std::string n, int h, std::string c, int p)
            : FloweringPlant(std::move(n), h, std::move(c)), points(p) {}
    int get_points() const override;
    void info() const override;
};

