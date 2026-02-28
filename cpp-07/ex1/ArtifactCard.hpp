//
// Created by alalimov on 2/21/26.
//
#pragma once
#include "../ex0/Card.hpp"

class ArtifactCard : public Card
{
public:
    std::string name, rarity;
    int cost;

    int get_durability();
    int get_current_durability();
    std::string get_effect();
    std::map<std::string, std::string> play(std::map<std::string, std::string> &game_state) override;
    std::map<std::string, std::string> activate_ability();
    void repair(int amount);
    std::string toString();

    ArtifactCard(std::string& name, int cost, std::string& rarity, int durability, std::string& effect_type):
        Card(name, cost, rarity), name(name), cost(cost), rarity(rarity), durability(durability), current_durability(durability), effect_type(effect_type) {}

private:
    int durability, current_durability;
    std::string effect_type;
};

