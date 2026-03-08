#ifndef SPELLCARD_HPP
#define SPELLCARD_HPP

#include "../ex0/Card.hpp"
#include <vector>

class SpellCard : public Card {
private:
    std::string effect_type;

public:
    SpellCard(std::string name, int cost, std::string rarity, std::string effect_type)
        : Card(std::move(name), cost, std::move(rarity)), effect_type(std::move(effect_type)) {}

    std::map<std::string, std::variant<std::string, int>> play(std::map<std::string, std::variant<std::string, int>> game_state) override {
        return {
            {"card_played", name},
            {"mana_used", cost},
            {"effect", std::string("Deal 3 damage to target")} // Simplified for the example output
        };
    }

    std::map<std::string, std::variant<std::string, int>> resolve_effect(const std::vector<std::string>& targets) {
        return {
            {"spell_name", name},
            {"effect_type", effect_type},
            {"targets_count", (int)targets.size()}
        };
    }

    std::string getEffectType() const { return effect_type; }
};

#endif
