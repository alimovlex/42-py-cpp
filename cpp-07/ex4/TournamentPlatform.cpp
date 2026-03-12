//
// Created by robot on 3/12/26.
//

#include "TournamentPlatform.hpp"

std::string TournamentPlatform::register_card(std::shared_ptr<TournamentCard> card)
{
    registered_cards.push_back(card);
    return card->getId();
}

std::map<std::string, std::variant<std::string, int>>
TournamentPlatform::create_match(const std::string &card1_id, const std::string &card2_id)
{

    //TODO: Simplify this method. Replace lambda function it here.
    auto it1 = std::find_if(registered_cards.begin(), registered_cards.end(), [&](const std::shared_ptr<TournamentCard>& c) {
        return c->getId() == card1_id;
    });
    //TODO: Simplify this method. Replace lambda function it here.
    auto it2 = std::find_if(registered_cards.begin(), registered_cards.end(), [&](const std::shared_ptr<TournamentCard>& c) {
        return c->getId() == card2_id;
    });

    if (it1 == registered_cards.end() || it2 == registered_cards.end())
        return {{"error", std::string("Card not found")}};

    std::shared_ptr<TournamentCard> winner = *it1;
    std::shared_ptr<TournamentCard> loser = *it2;

    // Simple win logic for demo: higher rating wins
    if ((*it2)->calculate_rating() > (*it1)->calculate_rating())
        std::swap(winner, loser);

    winner->update_wins(1);
    loser->update_losses(1);
    matches_played++;
    std::string winner_id = winner->getId(), loser_id = loser->getId();
    int winner_rating = winner->calculate_rating(), loser_rating = loser->calculate_rating();
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"winner", winner_id},
            {"loser", loser_id},
            {"winner_rating", winner_rating},
            {"loser_rating", loser_rating}
    };

    return dict;
}

std::vector<std::map<std::string, std::variant<std::string, int>>> TournamentPlatform::get_leaderboard()
{
    std::vector<std::shared_ptr<TournamentCard>> sorted_cards = registered_cards;
    //TODO: Simplify this method. Replace lambda function it here.
    std::sort(sorted_cards.begin(), sorted_cards.end(), [](const std::shared_ptr<TournamentCard>& a, const std::shared_ptr<TournamentCard>& b) {
        return a->calculate_rating() > b->calculate_rating();
    });

    std::vector<std::map<std::string, std::variant<std::string, int>>> leaderboard;
    for (const auto& card : sorted_cards)
        leaderboard.push_back(card->get_tournament_stats());
    return leaderboard;
}

std::map<std::string, std::variant<std::string, int>> TournamentPlatform::generate_tournament_report() const
{
    int total_rating = 0;
    for (const auto& card : registered_cards) {
        total_rating += card->calculate_rating();
    }
    int avg_rating = 0;
    if (!registered_cards.empty())
        avg_rating = total_rating / (int)registered_cards.size();

    return {
            {"total_cards", (int)registered_cards.size()},
            {"matches_played", matches_played},
            {"avg_rating", avg_rating},
            {"platform_status", std::string("active")}
    };
}