//
// Created by alalimov on 2/21/26.
//

#pragma once
#include <map>
#include <string>
#include <vector>
#include <memory>
#include "../ex0/Card.hpp"

class Deck: public Card {
public:
    std::vector<std::map<std::string, std::string>> card_added;

    void add_card(const std::vector<std::shared_ptr<Card>>& cards);
};

