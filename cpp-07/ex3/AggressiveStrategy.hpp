//
// Created by alalimov on 3/5/26.
//

#pragma once
#include "GameStrategy.hpp"
#include <iostream>

class AggressiveStrategy: GameStrategy {
public:
    std::string name;
    void display_name();
    AggressiveStrategy(): name("AggressiveStrategy") {}
};

