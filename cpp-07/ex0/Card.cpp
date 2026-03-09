//
// Created by robot on 3/9/26.
//

#include "Card.hpp"

std::map<std::string, std::variant<std::string, int>> Card::get_card_info() const
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"name", name},
            {"cost", cost},
            {"rarity", rarity}
    };
    return dict;
}

bool Card::is_playable(int available_mana) const
{
    bool is_mana_available = available_mana >= cost;
    return is_mana_available;
}

std::string Card::getName() const
{
    return name;
}

int Card::getCost() const
{
    return cost;
}