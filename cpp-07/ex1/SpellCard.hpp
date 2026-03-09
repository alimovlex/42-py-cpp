#pragma once
#include "../ex0/Card.hpp"
#include <vector>

class SpellCard : public Card {
private:
    std::string effect_type;

public:
    SpellCard(std::string name, int cost, std::string rarity, std::string effect_type)
        : Card(std::move(name), cost, std::move(rarity)), effect_type(std::move(effect_type)) {}

    std::map<std::string, std::variant<std::string, int>> play(std::map<std::string, std::variant<std::string, int>> game_state) override;
    std::map<std::string, std::variant<std::string, int>> resolve_effect(const std::vector<std::string>& targets);
    std::string getEffectType() const;
};

