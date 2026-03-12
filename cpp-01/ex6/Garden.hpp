//
// Created by robot on 3/12/26.
//
#pragma once
#include "Plant.hpp"

class Garden {
    std::string owner;
    std::vector<std::unique_ptr<Plant>> plants;

public:
    Garden(std::string o) : owner(std::move(o)) {}
    const std::string& get_owner() const;
    void add_plant(std::unique_ptr<Plant> p);
    void grow_plants();
    const std::vector<std::unique_ptr<Plant>>& get_plants() const;
};

