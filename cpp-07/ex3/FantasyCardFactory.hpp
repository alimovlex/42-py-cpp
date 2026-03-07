//
// Created by robot on 2/28/26.
//
#pragma once
#include "CardFactory.hpp"
#include <iostream>
#include <memory>

class FantasyCardFactory: public CardFactory {
public:
    std::map<std::string, std::map<std::string, std::string>> creature_types;
    std::map<std::string, std::map<std::string, std::string>> spell_types;
    std::map<std::string, std::map<std::string, std::string>> artifact_types;

    void display_name();
    std::map<std::string, std::vector<std::string>> get_supported_types() override;
    std::map<std::string, std::string> create_themed_deck(int size) override;
    Card create_creature(std::string &name_or_power) override;
    Card create_spell(std::string &name_or_power) override;
    Card create_artifact(std::string &name_or_power) override;

    FantasyCardFactory();
};

