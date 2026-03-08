#ifndef AGGRESSIVESTRATEGY_HPP
#define AGGRESSIVESTRATEGY_HPP

#include "GameStrategy.hpp"
#include <algorithm>

class AggressiveStrategy : public GameStrategy {
public:
    std::map<std::string, std::variant<std::string, int>> execute_turn(const std::vector<std::shared_ptr<Card>>& hand, const std::vector<std::shared_ptr<Card>>& battlefield) override {
        int mana_used = 0;
        std::vector<std::string> cards_played;
        
        // Simple logic: play cards from hand until mana is exhausted or hand is empty
        int available_mana = 5; // Example mana
        for (const auto& card : hand) {
            if (card->getCost() <= (available_mana - mana_used)) {
                mana_used += card->getCost();
                cards_played.push_back(card->getName());
            }
        }

        return {
            {"cards_played_count", (int)cards_played.size()},
            {"mana_used", mana_used},
            {"damage_dealt", 8}, // Simulated for example
            {"strategy", get_strategy_name()}
        };
    }

    std::string get_strategy_name() const override {
        return "AggressiveStrategy";
    }

    std::vector<std::string> prioritize_targets(const std::vector<std::string>& available_targets) override {
        std::vector<std::string> targets = available_targets;
        // Aggressive strategy might sort targets by importance or just pick the face
        return targets;
    }
};

#endif
