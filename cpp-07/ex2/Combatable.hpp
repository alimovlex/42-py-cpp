//
// Created by robot on 2/28/26.
//
#pragma once
#include <map>
#include <any>
#include <string>
#include <vector>

class Combatable {
public:
    virtual std::map<std::string, std::string> attack(std::string& target) = 0;
    virtual std::map<std::string, std::string> defend(int& incoming_damage) = 0;
    virtual std::map<std::string, std::string> get_combat_stats() = 0;
    virtual ~Combatable() = default;
};

