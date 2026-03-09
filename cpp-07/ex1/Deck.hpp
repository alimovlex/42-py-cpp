#pragma once
#include "../ex0/Card.hpp"
#include "../ex0/CreatureCard.hpp"
#include "SpellCard.hpp"
#include "ArtifactCard.hpp"
#include <vector>
#include <memory>
#include <algorithm>
#include <random>
#include <chrono>

class Deck {
private:
    std::vector<std::unique_ptr<Card>> cards;

public:
    void add_card(std::unique_ptr<Card> card);
    bool remove_card(const std::string& card_name);
    void shuffle();
    std::unique_ptr<Card> draw_card();
    std::map<std::string, std::variant<std::string, int>> get_deck_stats() const;
};

