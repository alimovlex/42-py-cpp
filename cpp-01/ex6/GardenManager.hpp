//
// Created by robot on 3/12/26.
//
#pragma once
#include "Garden.hpp"

class GardenManager {
    std::vector<std::unique_ptr<Garden>> gardens;

public:
    // factory
    static GardenManager create_garden_network(const std::vector<std::string>& gardeners);
    void add_garden(const std::string& name);
    Garden* find_garden(const std::string& name) const;
    void add_plant(const std::string& garden_name, std::unique_ptr<Plant> p);
    void grow_plants(const std::string& garden_name);
    void get_scores() const;
    void get_gardencount() const;
};

