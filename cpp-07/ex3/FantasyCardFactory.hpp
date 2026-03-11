#pragma once
#include "CardFactory.hpp"
#include "../ex0/CreatureCard.hpp"
#include "../ex1/SpellCard.hpp"
#include "../ex1/ArtifactCard.hpp"

class FantasyCardFactory : public CardFactory {
public:
    std::unique_ptr<Card> create_creature(std::variant<std::monostate, std::string, int> name_or_power = std::monostate{}) override;
    std::unique_ptr<Card> create_spell(std::variant<std::monostate, std::string, int> name_or_power = std::monostate{}) override;
    std::unique_ptr<Card> create_artifact(std::variant<std::monostate, std::string, int> name_or_power = std::monostate{}) override;
    std::map<std::string, std::variant<std::string, int>> create_themed_deck(int size) override;
    std::map<std::string, std::variant<std::string, int>> get_supported_types() const override;
};

