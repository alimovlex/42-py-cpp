//
// Created by robot on 3/12/26.
//
#pragma once
#include "Garden.hpp"
#include "PrizeFlower.hpp"

class GardenStats {
public:
    static void report(const Garden& garden);
    static void get_plants(const Garden& garden);
    static void get_plant_stats(const Garden& garden);
    static void get_plant_types(const Garden& garden);
    static void validate_heights(const Garden& garden);
};

