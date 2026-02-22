//
// Created by alalimov on 2/22/26.
//

#pragma once

#include "../ex0/Card.hpp"

class SpellCard: public Card
{
public:
    std::string name, rarity, effect_type;
    int cost;

    std::string get_effect_type();
    //std::map<std::string, std::string> play(std::map<std::string, std::string> &game_state) override;

    SpellCard(std::string name, int cost, std::string rarity, std::string effect_type):
    Card(name, cost, rarity), name(name), cost(cost), rarity(rarity), effect_type(effect_type) {}
};

