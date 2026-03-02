//
// Created by robot on 2/28/26.
//

#include "EliteCard.hpp"

std::map<std::string, std::string> EliteCard::play(std::map<std::string, std::string> &game_state)
{
    this->game_state = game_state;
    std::map<std::string, std::string> dict = {
            {"card_played", this->name},
            {"mana_used", std::to_string(this->cost)},
            {"effect", "Elite card summoned with combat and magic abilities"},
            {"card_type", "elite"}
    };

    return dict;
}

std::map<std::string, std::string> EliteCard::attack(std::string &target)
{
    this->target = target;
    std::map<std::string, std::string> dict = {
            {"attacker", this->name},
            {"target", this->target},
            {"damage", std::to_string(this->cost)},
            {"combat_type", "melee"}
    };

    return dict;
}

std::map<std::string, std::string> EliteCard::defend(int &incoming_damage)
{
    this->incoming_damage = incoming_damage;
    std::map<std::string, std::string> dict = {
            {"defender", this->name},
            {"damage_taken", std::to_string(incoming_damage - 2)},
            {"damage_blocked", std::to_string(incoming_damage - 1)},
            {"still_alive", "true"}
    };

    return dict;
}

std::map<std::string, std::string> EliteCard::get_combat_stats()
{
    return {};
}

std::map<std::string, std::string> EliteCard::cast_spell(std::string &spell_name,
                                                         std::vector<std::string> &targets)
{
    this->spell_name = spell_name;
    this->targets = targets;

    std::map<std::string, std::string> dict = {
            {"caster", this->name},
            {"spell", this->spell_name},
            //{"targets", this->targets},
            {"mana_used", std::to_string(this->cost)}
    };

    return dict;
}

std::map<std::string, std::string> EliteCard::channel_mana(int amount)
{
    this->amount = amount;
    std::map<std::string, std::string> dict = {
            {"channeled", std::to_string(this->amount)},
            {"total_mana", std::to_string(this->amount + this->cost)}
    };

    return dict;
}

std::map<std::string, std::string> EliteCard::get_magic_stats()
{
    std::map<std::string, std::string> dict = {
            {"mana_pool", std::to_string(this->mana_pool)},
            {"current_mana", std::to_string(this->current_mana)}
    };

    return dict;
}

