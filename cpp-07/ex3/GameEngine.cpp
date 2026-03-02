//
// Created by robot on 2/28/26.
//

#include "GameEngine.hpp"

void GameEngine::configure_engine(CardFactory factory, GameStrategy strategy)
{
    //this->factory = factory;
    //this->strategy = strategy;
}

std::map<std::string, std::string> GameEngine::simulate_turn()
{
    std::map<std::string, std::string> dict;
    //if (!factory || !strategy)
        dict = {
                {"error", "Engine not configured"},
                {"message", "Call configure_engine() first"}
    };
        /*
    std::vector<CardFactory> hand = {factory.create_creature(),
                                     factory.create_creature("goblin"),
                                     factory.create_spell()};
        cards_created = hand.size();
    auto turn_result = strategy.execute_turn(hand, battlefiels);
    turns_simulated += 1;
    total_damage += turn_result["damage_dealt"];
    */
    return dict;
}

std::map<std::string, std::string> GameEngine::get_engine_status()
{
    std::map<std::string, std::string> dict = {
            {"turns_simulated", std::to_string(turns_simulated)},
            {"total_damage", std::to_string(total_damage)},
            {"cards_created", std::to_string(cards_created)},
            //{"factory_configured", std::to_string(!this->factory)},
            //{"strategy_configured", std::to_string(!this->strategy)}
            //{"strategy_used", strategy.get_strategy_name()}
    };
    return dict;
}