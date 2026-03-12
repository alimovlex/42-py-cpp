//
// Created by robot on 3/9/26.
//

#include "Deck.hpp"

void Deck::add_card(std::unique_ptr<Card> card)
{
    cards.push_back(std::move(card));
}

bool Deck::remove_card(const std::string &card_name)
{
    //TODO: Simplify this method. Replace lambda function it here.
    auto it = std::find_if(cards.begin(), cards.end(), [&](const std::unique_ptr<Card>& c) {
        return c->getName() == card_name;
    });

    if (it != cards.end())
    {
        cards.erase(it);
        return true;
    }
    else
        return false;
}

void Deck::shuffle()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

std::unique_ptr<Card> Deck::draw_card()
{
    if (cards.empty())
        return nullptr;

    std::unique_ptr<Card> card = std::move(cards.back());
    cards.pop_back();
    return card;
}

std::map<std::string, std::variant<std::string, int>> Deck::get_deck_stats() const
{
    std::map<std::string, std::variant<std::string, int>> dict;
    int creatures = 0;
    int spells = 0;
    int artifacts = 0;
    double total_cost = 0;
    int avg_cost = 0;

    for (const auto& card : cards)
    {
        total_cost += card->getCost();
        if (dynamic_cast<CreatureCard*>(card.get()))
            creatures++;
        else if (dynamic_cast<SpellCard*>(card.get()))
            spells++;
        else if (dynamic_cast<ArtifactCard*>(card.get()))
            artifacts++;
    }

    int total = cards.size();

    if (total > 0)
        avg_cost = static_cast<int>(total_cost / total);

    dict = {
            {"total_cards", total},
            {"creatures", creatures},
            {"spells", spells},
            {"artifacts", artifacts},
            {"avg_cost", avg_cost}
    };

    return dict;
}