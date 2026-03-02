//
// Created by robot on 2/28/26.
//

#pragma once
#include <map>
#include <string>
#include <vector>

class GameStrategy {

public:
    virtual std::map<std::string, std::string> execute_turn(std::vector<std::string>& hand,
                                                            std::vector<std::string>& battlefield) = 0;

    virtual std::string get_strategy_name() = 0;
    virtual std::vector<std::string> prioritize_targets(std::vector<std::string>& list) = 0;
    virtual ~GameStrategy() = default;
};

