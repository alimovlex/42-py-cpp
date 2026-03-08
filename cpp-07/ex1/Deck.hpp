#ifndef DECK_HPP
#define DECK_HPP

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
    void add_card(std::unique_ptr<Card> card) {
        cards.push_back(std::move(card));
    }

    bool remove_card(const std::string& card_name) {
        auto it = std::find_if(cards.begin(), cards.end(), [&](const std::unique_ptr<Card>& c) {
            return c->getName() == card_name;
        });
        if (it != cards.end()) {
            cards.erase(it);
            return true;
        }
        return false;
    }

    void shuffle() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
    }

    std::unique_ptr<Card> draw_card() {
        if (cards.empty()) return nullptr;
        std::unique_ptr<Card> card = std::move(cards.back());
        cards.pop_back();
        return card;
    }

    std::map<std::string, std::variant<std::string, int>> get_deck_stats() const {
        int creatures = 0;
        int spells = 0;
        int artifacts = 0;
        double total_cost = 0;

        for (const auto& card : cards) {
            total_cost += card->getCost();
            if (dynamic_cast<CreatureCard*>(card.get())) creatures++;
            else if (dynamic_cast<SpellCard*>(card.get())) spells++;
            else if (dynamic_cast<ArtifactCard*>(card.get())) artifacts++;
        }

        int total = cards.size();
        int avg_cost = total > 0 ? static_cast<int>(total_cost / total) : 0;

        return {
            {"total_cards", total},
            {"creatures", creatures},
            {"spells", spells},
            {"artifacts", artifacts},
            {"avg_cost", avg_cost}
        };
    }
};

#endif
