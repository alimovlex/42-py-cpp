//
// Created by alalimov on 2/19/26.
//
#pragma once
#include "Card.hpp"

class CreatureCard : public Card
{
public:
    int attack, health;
    CreatureCard(std::string name, int cost, std::string rarity, int attack, int health) :
    Card(name, cost, rarity), attack(attack), health(health) { }
};
