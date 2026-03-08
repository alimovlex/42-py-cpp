#ifndef CREATURECARD_HPP
#define CREATURECARD_HPP

#include "Card.hpp"
#include <stdexcept>
#include <iostream>

class CreatureCard : public Card {
private:
    int attack;
    int health;

public:
    CreatureCard(std::string name, int cost, std::string rarity, int attack, int health)
        : Card(std::move(name), cost, std::move(rarity)), attack(attack), health(health) {
        if (attack < 0 || health < 0) {
            throw std::invalid_argument("Attack and health must be non-negative integers.");
        }
    }

    std::map<std::string, std::variant<std::string, int>> play(std::map<std::string, std::variant<std::string, int>> game_state) override {
        return {
            {"card_played", name},
            {"mana_used", cost},
            {"effect", std::string("Creature summoned to battlefield")}
        };
    }

    std::map<std::string, std::variant<std::string, int>> get_card_info() const override {
        auto info = Card::get_card_info();
        info["type"] = std::string("Creature");
        info["attack"] = attack;
        info["health"] = health;
        return info;
    }

    std::map<std::string, std::variant<std::string, int>> attack_target(const std::string& target_name) {
        return {
            {"attacker", name},
            {"target", target_name},
            {"damage_dealt", attack},
            {"combat_resolved", 1} // Using 1 for True as bool isn't in variant here
        };
    }
};

#endif
