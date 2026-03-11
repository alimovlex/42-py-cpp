#pragma once
#include "GameStrategy.hpp"
#include <algorithm>

class AggressiveStrategy : public GameStrategy {
public:
    std::map<std::string, std::variant<std::string, int>> execute_turn(const std::vector<std::shared_ptr<Card>>& hand, const std::vector<std::shared_ptr<Card>>& battlefield) override;
    std::string get_strategy_name() const override;
    std::vector<std::string> prioritize_targets(const std::vector<std::string>& available_targets) override;
};

