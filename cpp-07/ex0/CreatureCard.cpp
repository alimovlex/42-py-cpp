//
// Created by robot on 3/9/26.
//

#include "CreatureCard.hpp"

std::map<std::string, std::variant<std::string, int>>
CreatureCard::play(std::map<std::string, std::variant<std::string, int>> game_state)
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"card_played", name},
            {"mana_used", cost},
            {"effect", std::string("Creature summoned to battlefield")}
    };
    return dict;
}

std::map<std::string, std::variant<std::string, int>> CreatureCard::get_card_info() const
{
    std::map<std::string, std::variant<std::string, int>> info = Card::get_card_info();
    info["type"] = std::string("Creature");
    info["attack"] = attack;
    info["health"] = health;
    return info;
}

std::map<std::string, std::variant<std::string, int>> CreatureCard::attack_target(const std::string &target_name)
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"attacker", name},
            {"target", target_name},
            {"damage_dealt", attack},
            {"combat_resolved", 1} // Using 1 for True as bool isn't in variant here
    };
    return dict;
}