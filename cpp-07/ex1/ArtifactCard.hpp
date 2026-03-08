#ifndef ARTIFACTCARD_HPP
#define ARTIFACTCARD_HPP

#include "../ex0/Card.hpp"

class ArtifactCard : public Card {
private:
    int durability;
    std::string effect;

public:
    ArtifactCard(std::string name, int cost, std::string rarity, int durability, std::string effect)
        : Card(std::move(name), cost, std::move(rarity)), durability(durability), effect(std::move(effect)) {}

    std::map<std::string, std::variant<std::string, int>> play(std::map<std::string, std::variant<std::string, int>> game_state) override {
        return {
            {"card_played", name},
            {"mana_used", cost},
            {"effect", std::string("Permanent: ") + effect}
        };
    }

    std::map<std::string, std::variant<std::string, int>> activate_ability() {
        return {
            {"artifact", name},
            {"ability_activated", 1},
            {"effect_applied", effect}
        };
    }
};

#endif
