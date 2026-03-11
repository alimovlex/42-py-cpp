//
// Created by robot on 3/11/26.
//

#include "EliteCard.hpp"

std::map<std::string, std::variant<std::string, int>>
EliteCard::play(std::map<std::string, std::variant<std::string, int>> game_state)
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"card_played", name},
            {"mana_used", cost},
            {"effect", std::string("Elite card entered the battlefield")}
    };
    return dict;
}

std::map<std::string, std::variant<std::string, int>> EliteCard::attack(const std::string &target)
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"attacker", name},
            {"target", target},
            {"damage", attack_power},
            {"combat_type", std::string("melee")}
    };
    return dict;
}

std::map<std::string, std::variant<std::string, int>> EliteCard::defend(int incoming_damage)
{
    const int blocked = 3; // Fixed block for example
    int taken = std::max(0, incoming_damage - blocked);
    health -= taken;

    if (health > 0)
        health = 1;
    else
        health = 0;

    std::map<std::string, std::variant<std::string, int>> dict = {
            {"defender", name},
            {"damage_taken", taken},
            {"damage_blocked", blocked},
            {"still_alive", health}
    };
    return dict;
}

std::map<std::string, std::variant<std::string, int>> EliteCard::get_combat_stats() const
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"attack", attack_power},
            {"health", health}
    };
    return dict;
}

std::map <std::string, std::variant<std::string, int>>
EliteCard::cast_spell(const std::string &spell_name, const std::vector <std::string> &targets)
{
    int mana_cost = 4;
    mana_pool -= mana_cost;
    std::map <std::string, std::variant<std::string, int>> dict = {
            {"caster", name},
            {"spell", spell_name},
            {"targets_count", (int)targets.size()},
            {"mana_used", mana_cost}
    };
    return dict;
}

std::map<std::string, std::variant<std::string, int>> EliteCard::channel_mana(int amount)
{
    mana_pool += amount;
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"channeled", amount},
            {"total_mana", mana_pool}
    };
    return dict;
}

std::map<std::string, std::variant<std::string, int>> EliteCard::get_magic_stats() const
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"mana_pool", mana_pool}
    };
    return dict;
}