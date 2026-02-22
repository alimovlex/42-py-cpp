//
// Created by alalimov on 2/21/26.
//

#include "Deck.hpp"

void Deck::add_card(const std::shared_ptr<Card>& card)
{
    card_added.push_back(card);
}

bool Deck::remove_card(const std::string& card_name)
{
    for (auto it = card_added.begin(); it != card_added.end(); ++it)
    {
        if ((*it)->name == card_name)
        {
            card_added.erase(it);
            return true;
        }
    }
    return false;
}

void Deck::shuffle()
{
    std::random_shuffle(card_added.begin(), card_added.end());
}

std::map<std::string, std::string> Deck::draw_card()
{
    if (card_added.empty())
        return {};
    auto card = card_added.front();
    std::cout << "Drew: " << card->name << " (" << card->type << ")" << std::endl;
    std::map<std::string, std::string> dict = {
            {"card_played", card->name},
            {"mana_used", std::to_string(card->cost)},
            {"type", card->type}
    };
    return dict;
}

std::map<std::string, double> Deck::get_deck_stats()
{
    if (card_added.empty())
        return {};

    int creature = 0, spell = 0, artifact = 0;
    double total_cost = 0;

    for (const auto& card : card_added) {
        std::string str_type = card->type;
        //std::transform(str_type.begin(), str_type.end(), str_type.begin(), ::tolower);

        if (str_type.find("creature") != std::string::npos)
            creature++;
        else if (str_type.find("spell") != std::string::npos)
            spell++;
        else if (str_type.find("artifact") != std::string::npos)
            artifact++;

        total_cost += card->cost;
    }
    std::map<std::string, double> dict = {
            {"total_cards", static_cast<double>(card_added.size())},
            {"creature", static_cast<double>(creature)},
            {"spells", static_cast<double>(spell)},
            {"artifacts", static_cast<double>(artifact)},
            {"avg_cost", total_cost / card_added.size()}
    };

    return dict;
}