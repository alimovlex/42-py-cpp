//
// Created by robot on 3/9/26.
//

#include "SpellCard.hpp"

std::map<std::string, std::variant<std::string, int>>
SpellCard::play(std::map<std::string, std::variant<std::string, int>> game_state)
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"card_played", name},
            {"mana_used", cost},
            {"effect", std::string("Deal 3 damage to target")}
    };

    return dict;
}

std::map<std::string, std::variant<std::string, int>>
SpellCard::resolve_effect(const std::vector<std::string> &targets)
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"spell_name", name},
            {"effect_type", effect_type},
            {"targets_count", (int)targets.size()}
    };

    return dict;
}

std::string SpellCard::getEffectType() const
{
    return effect_type;
}

