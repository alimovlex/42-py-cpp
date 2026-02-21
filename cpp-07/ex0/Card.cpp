//
// Created by alalimov on 2/19/26.
//

#include "Card.hpp"

std::map<std::string, std::string> Card::get_card_info()
{
    std::map<std::string, std::string> dict = {
            {"name", name},
            {"cost", std::to_string(cost)},
            {"rarity", rarity},
            {"type", "Creature"}
    };
    return dict;
}

bool Card::is_playable(int mana)
{
    this->available_mana = mana;
    if (available_mana >= cost)
        return true;
    else
        return false;
}