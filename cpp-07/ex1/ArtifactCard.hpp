//
// Created by alalimov on 2/21/26.
//
#pragma once
#include "../ex0/Card.hpp"

class ArtifactCard : public Card
{
public:

    std::string name, rarity, effect;
    int cost, durability, current_durability;

    int get_durability();
    int get_current_durability();
    std::string get_effect();

    std::map<std::string, std::string> play(std::map<std::string, std::string> &game_state) override;
    std::map<std::string, std::string> activate_ability();
    void repair(int amount);
    std::string toString();

    ArtifactCard(std::string& name, int cost, std::string& rarity, int durability, std::string& effect):
    Card(name, cost, rarity), name(name), cost(cost), rarity(rarity), durability(durability), effect(effect), current_durability(durability) {}
};

