//
// Created by alalimov on 2/21/26.
//

#include <iostream>
#include <memory>
#include "FantasyCardFactory.hpp"
#include "AggressiveStrategy.hpp"
#include "GameEngine.hpp"

int main()
{
    std::cout << "=== DataDeck Game Engine ===\n" << std::endl;
    std::cout << "Configuring Fantasy Card Game..." << std::endl;
    std::unique_ptr<FantasyCardFactory> fantasy = std::make_unique<FantasyCardFactory>();
    std::unique_ptr<AggressiveStrategy> aggressive = std::make_unique<AggressiveStrategy>();

    fantasy->display_name();
    aggressive->display_name();

    std::cout << "Available types: " << std::endl;
    //std::cout << fantasy->get_supported_types();

    GameEngine gameEngine;
    //gameEngine.configure_engine(fantasy, aggressive);

    return 0;
}