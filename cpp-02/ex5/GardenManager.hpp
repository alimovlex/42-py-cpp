//
// Created by robot on 3/14/26.
//
#pragma once
#include "Plant.hpp"
#include "GardenError.hpp"
#include "WaterError.hpp"
#include "PlantError.hpp"
#include "finally.hpp"

class GardenManager
{
public:
    std::vector<Plant> plants;
    int tanksize;
    int water;
    GardenManager(int tanksize): tanksize(tanksize) { }

    void add_plants(std::vector<Plant>& plants);
    void water_plants(int amount);
    static void check_plant_health(Plant& plant);
    void check_plants();
    void recover();
};

