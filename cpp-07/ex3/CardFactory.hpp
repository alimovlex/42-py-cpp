//
// Created by robot on 2/28/26.
//

#pragma once
#include "../ex0/Card.hpp"
#include "../ex0/CreatureCard.hpp"
#include "../ex1/SpellCard.hpp"
#include "../ex1/ArtifactCard.hpp"

class CardFactory {

public:
    virtual Card create_creature(std::string& name_or_power) = 0;
    virtual Card create_spell(std::string& name_or_power) = 0;
    virtual Card create_artifact(std::string& name_or_power) = 0;

    virtual std::map<std::string, std::string> create_themed_deck(int size) = 0;
    virtual std::map<std::string, std::vector<std::string>> get_supported_types() = 0;
    virtual ~CardFactory() = default;
};

