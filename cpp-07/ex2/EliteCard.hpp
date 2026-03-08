#ifndef ELITECARD_HPP
#define ELITECARD_HPP

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

    std::map<std::string, std::variant<std::string, int>> play(std::map<std::string, std::variant<std::string, int>> game_state) override {
        return {
            {"card_played", name},
            {"mana_used", cost},
            {"effect", std::string("Elite card entered the battlefield")}
        };
    }

    std::map<std::string, std::variant<std::string, int>> attack(const std::string& target) override {
        return {
            {"attacker", name},
            {"target", target},
            {"damage", attack_power},
            {"combat_type", std::string("melee")}
        };
    }

    std::map<std::string, std::variant<std::string, int>> defend(int incoming_damage) override {
        int blocked = 3; // Fixed block for example
        int taken = std::max(0, incoming_damage - blocked);
        health -= taken;
        return {
            {"defender", name},
            {"damage_taken", taken},
            {"damage_blocked", blocked},
            {"still_alive", health > 0 ? 1 : 0}
        };
    }

    std::map<std::string, std::variant<std::string, int>> get_combat_stats() const override {
        return {
            {"attack", attack_power},
            {"health", health}
        };
    }

    std::map<std::string, std::variant<std::string, int>> cast_spell(const std::string& spell_name, const std::vector<std::string>& targets) override {
        int mana_cost = 4;
        mana_pool -= mana_cost;
        return {
            {"caster", name},
            {"spell", spell_name},
            {"targets_count", (int)targets.size()},
            {"mana_used", mana_cost}
        };
    }

    std::map<std::string, std::variant<std::string, int>> channel_mana(int amount) override {
        mana_pool += amount;
        return {
            {"channeled", amount},
            {"total_mana", mana_pool}
        };
    }

    std::map<std::string, std::variant<std::string, int>> get_magic_stats() const override {
        return {
            {"mana_pool", mana_pool}
        };
    }
};

#endif
