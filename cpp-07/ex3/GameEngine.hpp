#pragma once
#include "CardFactory.hpp"
#include "GameStrategy.hpp"
#include <memory>
#include <vector>

class GameEngine {
private:
    std::unique_ptr<CardFactory> factory;
    std::unique_ptr<GameStrategy> strategy;
    int turns_simulated = 0;
    int total_damage = 0;
    int cards_created = 0;

public:
    void configure_engine(std::unique_ptr<CardFactory> f, std::unique_ptr<GameStrategy> s);
    std::map<std::string, std::variant<std::string, int>> simulate_turn();
    std::map<std::string, std::variant<std::string, int>> get_engine_status() const;
};
