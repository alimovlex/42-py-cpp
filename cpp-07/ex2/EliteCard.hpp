//
// Created by robot on 2/28/26.
//
#pragma once
#include "../ex0/Card.hpp"
#include "Combatable.hpp"
#include "Magical.hpp"

class EliteCard : public Card, public Combatable, public Magical {
public:
    std::map<std::string, std::string> game_state;
    std::string target, spell_name;
    int incoming_damage, amount, current_mana, mana_pool;
    std::vector<std::string> targets;

    std::map<std::string, std::string> play(std::map<std::string, std::string> &game_state) override;
    std::map<std::string, std::string> attack(std::string &target) override;
    std::map<std::string, std::string> defend(int &incoming_damage) override;
    std::map<std::string, std::string> get_combat_stats() override;
    std::map<std::string, std::string> cast_spell(std::string &spell_name,
                                                  std::vector<std::string> &targets) override;
    std::map<std::string, std::string> channel_mana(int amount) override;
    std::map<std::string, std::string> get_magic_stats() override;
};

