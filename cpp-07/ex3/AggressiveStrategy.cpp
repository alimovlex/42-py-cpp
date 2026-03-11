//
// Created by robot on 3/11/26.
//

#include "AggressiveStrategy.hpp"

std::string AggressiveStrategy::get_strategy_name() const
{
    return "AggressiveStrategy";
}

std::map<std::string, std::variant<std::string, int>>
AggressiveStrategy::execute_turn(const std::vector<std::shared_ptr<Card>> &hand,
                                 const std::vector<std::shared_ptr<Card>> &battlefield)

{
    int mana_used = 0;
    std::vector<std::string> cards_played;

    // Simple logic: play cards from hand until mana is exhausted or hand is empty
    int available_mana = 5; // Example mana
    for (const auto& card : hand)
    {
        if (card->getCost() <= (available_mana - mana_used))
        {
            mana_used += card->getCost();
            cards_played.push_back(card->getName());
        }
    }

    std::string strategy_name = get_strategy_name();
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"cards_played_count", (int)cards_played.size()},
            {"mana_used", mana_used},
            {"damage_dealt", 8}, // Simulated for example
            {"strategy", strategy_name}
    };

    return dict;
}

std::vector<std::string> AggressiveStrategy::prioritize_targets(const std::vector<std::string> &available_targets)
{
    std::vector<std::string> targets = available_targets;
    // Aggressive strategy might sort targets by importance or just pick the face
    return targets;
}