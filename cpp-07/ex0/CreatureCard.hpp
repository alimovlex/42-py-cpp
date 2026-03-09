#pragma once
#include "Card.hpp"
#include <stdexcept>
#include <iostream>

class CreatureCard : public Card {
private:
    int attack;
    int health;

public:
    CreatureCard(std::string name, int cost, std::string rarity, int attack, int health)
        : Card(std::move(name), cost, std::move(rarity)), attack(attack), health(health)
        {
        if (attack < 0 || health < 0)
            throw std::invalid_argument("Attack and health must be non-negative integers.");
        }

    std::map<std::string, std::variant<std::string, int>> play(std::map<std::string, std::variant<std::string, int>> game_state) override;
    std::map<std::string, std::variant<std::string, int>> get_card_info() const override;
    std::map<std::string, std::variant<std::string, int>> attack_target(const std::string& target_name);
};


