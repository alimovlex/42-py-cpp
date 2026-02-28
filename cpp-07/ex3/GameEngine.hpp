//
// Created by robot on 2/28/26.
//

#pragma once
#include "CardFactory.hpp"
#include "GameStrategy.hpp"

class GameEngine {
public:
   //CardFactory factory;
    //GameStrategy strategy;
    int turns_simulated, total_damage, cards_created;

   void configure_engine(CardFactory factory, GameStrategy strategy);
   std::map<std::string, std::string> simulate_turn();
   std::map<std::string, std::string> get_engine_status();

   GameEngine(): turns_simulated(0), total_damage(0), cards_created(0) { };


};

