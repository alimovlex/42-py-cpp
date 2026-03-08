#ifndef GAMESTRATEGY_HPP
#define GAMESTRATEGY_HPP

#include <vector>
#include <map>
#include <string>
#include <variant>
#include <memory>
#include "../ex0/Card.hpp"

class GameStrategy {
public:
    virtual ~GameStrategy() = default;
    virtual std::map<std::string, std::variant<std::string, int>> execute_turn(const std::vector<std::shared_ptr<Card>>& hand, const std::vector<std::shared_ptr<Card>>& battlefield) = 0;
    virtual std::string get_strategy_name() const = 0;
    virtual std::vector<std::string> prioritize_targets(const std::vector<std::string>& available_targets) = 0;
};

#endif
