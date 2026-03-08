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
    std::unique_ptr<CardFactory> fantasy = std::make_unique<FantasyCardFactory>();
    std::unique_ptr<GameStrategy> aggressive = std::make_unique<AggressiveStrategy>();

    //fantasy->display_name();
    //aggressive->display_name();

    std::cout << "Available types: " << std::endl;
    //std::cout << fantasy->get_supported_types();

    GameEngine gameEngine;
    //Dependency injection, may be invoking abstract factory pattern???
    gameEngine.configure_engine(fantasy, aggressive);
    std::cout << "Simulating aggressive turn..." << std::endl;
    std::map<std::string, std::string> result = gameEngine.simulate_turn();
    std::cout << "Hand: " << result["hand"] << std::endl;
    std::cout << "Turn execution:" << std::endl;
    std::string turn_exec = result["turn_execution"];
    std::cout << "Strategy: " << result["strategy"] << std::endl;
    std::cout << "Actions: \n" << "cards_played: " << result["cards_played"] << std::endl;
    std::cout << "mana_used: " << result["mana_used"] << std::endl;
    std::cout << "targets_attacked: " << result["targets_attacked"] << std::endl;
    std::cout << "damage_dealt: " << result["damage_dealt"] << std::endl;

    std::cout << "Game Report: " << std::endl;
    std::map<std::string, std::string> status = gameEngine.get_engine_status();
    std::cout << "turns_simulated: " << status["turns_simulated"] << std::endl;
    std::cout << "strategy_used: " << status["strategy_used"] << std::endl;
    std::cout << "total_damage: " << status["total_damage"] << std::endl;
    std::cout << "cards_created: " << status["cards_created"] << std::endl;

    std::cout << std::endl << "Abstract Factory + Strategy Pattern: Maximum flexibility achieved!" << std::endl;
    return 0;
}