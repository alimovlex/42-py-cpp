//
// Created by alalimov on 2/21/26.
//

#pragma once
#include <map>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include "../ex0/Card.hpp"

class Deck: public Card {
public:
    std::vector<std::shared_ptr<Card>> card_added;

    void add_card(const std::shared_ptr<Card>& card);
    bool remove_card(const std::string& card_name);
    void shuffle();
    std::map<std::string, std::string> draw_card();
    std::map<std::string, double> get_deck_stats();
};

