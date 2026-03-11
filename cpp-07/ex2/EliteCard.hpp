#pragma once
#include "../ex0/Card.hpp"
#include "Combatable.hpp"
#include "Magical.hpp"
#include <iostream>

class EliteCard : public Card, public Combatable, public Magical {
private:
    int attack_power;
    int health;
    int mana_pool;

public:
    EliteCard(std::string name, int cost, std::string rarity, int attack, int health, int mana)
        : Card(std::move(name), cost, std::move(rarity)), attack_power(attack), health(health), mana_pool(mana) {}

    std::map<std::string, std::variant<std::string, int>> play(std::map<std::string, std::variant<std::string, int>> game_state) override;
    std::map<std::string, std::variant<std::string, int>> attack(const std::string& target) override;
    std::map<std::string, std::variant<std::string, int>> defend(int incoming_damage) override;
    std::map<std::string, std::variant<std::string, int>> get_combat_stats() const override;
    std::map<std::string, std::variant<std::string, int>> cast_spell(const std::string& spell_name, const std::vector<std::string>& targets) override;
    std::map<std::string, std::variant<std::string, int>> channel_mana(int amount) override;
    std::map<std::string, std::variant<std::string, int>> get_magic_stats() const override;
};

