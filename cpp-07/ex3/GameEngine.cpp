//
// Created by robot on 3/11/26.
//

#include "GameEngine.hpp"

void GameEngine::configure_engine(std::unique_ptr<CardFactory> f, std::unique_ptr<GameStrategy> s)
{
    factory = std::move(f);
    strategy = std::move(s);
}

std::map<std::string, std::variant<std::string, int>> GameEngine::simulate_turn()
{
    if (!factory || !strategy)
        return {{"error", std::string("Engine not configured")}};

    std::vector<std::shared_ptr<Card>> hand;
    hand.push_back(std::shared_ptr<Card>(factory->create_creature("dragon")));
    hand.push_back(std::shared_ptr<Card>(factory->create_creature("goblin")));
    hand.push_back(std::shared_ptr<Card>(factory->create_spell("fireball")));
    cards_created += 3;

    std::vector<std::shared_ptr<Card>> battlefield;
    auto turn_result = strategy->execute_turn(hand, battlefield);

    turns_simulated++;
    if (std::holds_alternative<int>(turn_result["damage_dealt"]))
        total_damage += std::get<int>(turn_result["damage_dealt"]);

    return turn_result;
}

std::map<std::string, std::variant<std::string, int>> GameEngine::get_engine_status() const
{

    std::map<std::string, std::variant<std::string, int>> dict = {
            {"turns_simulated", turns_simulated},
            {"strategy_used", ""},
            {"total_damage", total_damage},
            {"cards_created", cards_created}
    };

    if (strategy)
        dict["strategy_used"] = strategy->get_strategy_name();
    else
        dict["strategy_used"] = "None";

    return dict;
}
