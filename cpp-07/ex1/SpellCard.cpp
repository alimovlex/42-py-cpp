//
// Created by alalimov on 2/22/26.
//

#include "SpellCard.hpp"

std::string SpellCard::get_effect_type()
{
    return this->effect_type;
}

std::map<std::string, std::string> SpellCard::play(std::map<std::string, std::string> &game_state)
{
    std::map<std::string, std::string> result = {
            {"card_played", name},
            {"mana_used", std::to_string(cost)},
            {"effect", effect_type.append(" effect applied")},
            {"effect", "spell"}
};
    if (effect_type == "damage")
        result["effect"] = "Deal " + std::to_string(cost) + " damage to target";
    else if (effect_type == "heal")
        result["effect"] = "Heal " + std::to_string(cost * 2) + " health";
    else if (effect_type == "buff")
        result["effect"] = "Grant + " + std::to_string(cost) + "/+"
                + std::to_string(cost) + " buff";
    else if (effect_type == "debuff")
        result["effect"] = "Apply - " + std::to_string(cost) + " debuff to target";

    return result;
}

std::map<std::string, std::any> SpellCard::resolve_effect(std::vector<std::string>& targets)
{
    std::map<std::string, std::any> result = {
            {"spell_name", name},
            {"effect_type", effect_type},
            {"targets_affected", std::to_string(targets.size())},
            {"targets", targets},
            {"resolved", true}
            };

    if (effect_type == "damage")
        result["damage_dealt"] = cost * targets.size();
    else if (effect_type == "heal")
        result["health_restored"] = cost * 2 * targets.size();

    return result;
}

std::string SpellCard::toString()
{
    return name + " (Spell)";
}