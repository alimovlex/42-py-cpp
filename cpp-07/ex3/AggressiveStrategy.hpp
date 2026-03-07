//
// Created by alalimov on 3/5/26.
//

#pragma once
#include "GameStrategy.hpp"
#include <iostream>

class AggressiveStrategy: public GameStrategy {
public:
    std::string name;
    void display_name();
    std::map<std::string, std::string> execute_turn(std::vector<std::string> &hand, std::vector<std::string> &battlefield) override;
    std::string get_strategy_name() override;
    std::vector<std::string> prioritize_targets(std::vector<std::string> &list) override;
    AggressiveStrategy(): name("AggressiveStrategy") {}
};

