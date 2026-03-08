#ifndef FANTASYCARDFACTORY_HPP
#define FANTASYCARDFACTORY_HPP

#include "CardFactory.hpp"
#include "../ex0/CreatureCard.hpp"
#include "../ex1/SpellCard.hpp"
#include "../ex1/ArtifactCard.hpp"

class FantasyCardFactory : public CardFactory {
public:
    std::unique_ptr<Card> create_creature(std::variant<std::monostate, std::string, int> name_or_power = std::monostate{}) override {
        if (std::holds_alternative<std::string>(name_or_power)) {
            std::string name = std::get<std::string>(name_or_power);
            if (name == "dragon") return std::make_unique<CreatureCard>("Fire Dragon", 5, "Legendary", 7, 5);
            if (name == "goblin") return std::make_unique<CreatureCard>("Goblin Warrior", 2, "Common", 2, 1);
        }
        return std::make_unique<CreatureCard>("Generic Fantasy Creature", 1, "Common", 1, 1);
    }

    std::unique_ptr<Card> create_spell(std::variant<std::monostate, std::string, int> name_or_power = std::monostate{}) override {
        return std::make_unique<SpellCard>("Fireball", 3, "Rare", "damage");
    }

    std::unique_ptr<Card> create_artifact(std::variant<std::monostate, std::string, int> name_or_power = std::monostate{}) override {
        return std::make_unique<ArtifactCard>("Mana Ring", 2, "Uncommon", 3, "Add 1 mana");
    }

    std::map<std::string, std::variant<std::string, int>> create_themed_deck(int size) override {
        return {
            {"deck_theme", std::string("Fantasy")},
            {"deck_size", size}
        };
    }

    std::map<std::string, std::variant<std::string, int>> get_supported_types() const override {
        return {
            {"creatures", std::string("dragon, goblin")},
            {"spells", std::string("fireball")},
            {"artifacts", std::string("mana_ring")}
        };
    }
};

#endif
