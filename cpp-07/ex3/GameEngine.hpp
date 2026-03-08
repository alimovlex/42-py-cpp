#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

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
    void configure_engine(std::unique_ptr<CardFactory> f, std::unique_ptr<GameStrategy> s) {
        factory = std::move(f);
        strategy = std::move(s);
    }

    std::map<std::string, std::variant<std::string, int>> simulate_turn() {
        if (!factory || !strategy) return {{"error", std::string("Engine not configured")}};

        std::vector<std::shared_ptr<Card>> hand;
        hand.push_back(std::shared_ptr<Card>(factory->create_creature("dragon")));
        hand.push_back(std::shared_ptr<Card>(factory->create_creature("goblin")));
        hand.push_back(std::shared_ptr<Card>(factory->create_spell("fireball")));
        cards_created += 3;

        std::vector<std::shared_ptr<Card>> battlefield;
        auto turn_result = strategy->execute_turn(hand, battlefield);
        
        turns_simulated++;
        if (std::holds_alternative<int>(turn_result["damage_dealt"])) {
            total_damage += std::get<int>(turn_result["damage_dealt"]);
        }

        return turn_result;
    }

    std::map<std::string, std::variant<std::string, int>> get_engine_status() const {
        return {
            {"turns_simulated", turns_simulated},
            {"strategy_used", strategy ? strategy->get_strategy_name() : "None"},
            {"total_damage", total_damage},
            {"cards_created", cards_created}
        };
    }
};

#endif
