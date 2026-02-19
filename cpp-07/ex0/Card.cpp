//
// Created by alalimov on 2/19/26.
//

#include "Card.hpp"

std::map<std::string, std::string> Card::get_card_info()
{
    return {
            {"name", name},
            {"cost", std::to_string(cost)},
            {"rarity", rarity},
            {"type", "Creature"}
    };
}

bool Card::is_playable(int mana)
{
    this->available_mana = mana;
    if (available_mana >= cost)
        return true;
    else
        return false;
}