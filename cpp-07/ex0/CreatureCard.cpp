//
// Created by alalimov on 2/19/26.
//

#include "CreatureCard.hpp"

std::map<std::string, std::string> CreatureCard::play(std::map<std::string, std::string> &state)
{
    state = {
            {"card_played", name},
            {"mana_used", std::to_string(cost)},
            {"effect","Creature summoned to battlefield"}
    };
    this->game_state = state;
    return state;
}

std::map<std::string, std::string> CreatureCard::get_card_info()
{
    std::map<std::string, std::string> dict = {
            {"name", name},
            {"cost", std::to_string(cost)},
            {"rarity", rarity},
            {"type", "Creature"},
            {"attack", std::to_string(attack)},
            {"health", std::to_string(health)}
    };
    return dict;
}

std::map<std::string, std::string> CreatureCard::attack_target(std::map<std::string, std::string> &current_target)
{
    current_target = {
            {"attacker", name},
            {"target", ""},
            {"combat_resolved","True"}
    };
    this->target = current_target;
    return current_target;
}

bool CreatureCard::is_valid()
{
    available_mana -= cost;
    if (available_mana < cost)
        return is_playable(available_mana);
    if ((attack < 0) && (health < 0))
        return false;
    return is_playable(available_mana);
}