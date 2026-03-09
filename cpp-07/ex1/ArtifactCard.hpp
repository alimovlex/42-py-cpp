#pragma once
#include "../ex0/Card.hpp"

class ArtifactCard : public Card {
private:
    int durability;
    std::string effect;

public:
    ArtifactCard(std::string name, int cost, std::string rarity, int durability, std::string effect)
        : Card(std::move(name), cost, std::move(rarity)), durability(durability), effect(std::move(effect)) {}

    std::map<std::string, std::variant<std::string, int>> play(std::map<std::string, std::variant<std::string, int>> game_state) override;
    std::map<std::string, std::variant<std::string, int>> activate_ability();
};

