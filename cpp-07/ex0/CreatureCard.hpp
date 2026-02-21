//
// Created by alalimov on 2/19/26.
//
#pragma once
#include "Card.hpp"

class CreatureCard : public Card
{
public:
    int attack, health;
    std::map<std::string, std::string> game_state;
    std::map<std::string, std::string> target;

    std::map<std::string, std::string> play(std::map<std::string, std::string> &state) override;
    std::map<std::string, std::string> get_card_info() override;
    std::map<std::string, std::string> attack_target(std::map<std::string, std::string> &current_target);
    bool is_valid();
    CreatureCard(std::string name, int cost, std::string rarity, int attack, int health) :
    Card(name, cost, rarity), attack(attack), health(health) { }

};
