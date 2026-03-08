//
// Created by alalimov on 3/8/26.
//

#include "TournamentPlatform.hpp"
#include <memory>

std::string TournamentPlatform::register_card(TournamentCard card)
{
    std::string card_id = card.name;
    return card_id;
}

std::map<std::string, std::string> TournamentPlatform::create_match(std::string &card1_id, std::string &card2_id)
{
    std::map<std::string, std::string> dict;
    for (auto& key: cards)
        if (key.first != card1_id || key.first != card2_id)
        {
            dict = { {"error", "Invalid card ID"}, {"message", "One or both cards not found"} };
            return dict;
        }
    std::unique_ptr<TournamentCard> card1; //= cards[card1_id];
    std::unique_ptr<TournamentCard> card2; //= cards[card2_id];

    std::map<std::string, std::string> combat1 = card1->get_combat_stats();
    std::map<std::string, std::string> combat2 = card2->get_combat_stats();

    std::string power1 = combat1["power_rating"];
    std::string power2 = combat2["power_rating"];

    std::string winner_id, loser_id;
    std::unique_ptr<TournamentCard> winner, loser;

    if (power1 > power2)
    {
        std::string winner_id = card1_id;
        std::string loser_id = card2_id;
        //TournamentCard winner = card1;
        //TournamentCard loser = card2;
    }
    else
    {
        std::string winner_id = card2_id;
        std::string loser_id = card1_id;
        //TournamentCard winner = card2;
        //TournamentCard loser = card1;
    }

    winner->update_wins(1);
    loser->update_losses(1);

    matches_played += 1;

    dict = {
            {"winner", winner_id},
            {"loser", loser_id},
            {"winner_rating", std::to_string(winner->rating)},
            {"loser_rating", std::to_string(loser->rating)}
    };

    return dict;
}

std::map<std::string, std::string> TournamentPlatform::get_leaderboard()
{
    std::unique_ptr<TournamentCard> card;
    std::map<std::string, std::string> rank_info = card->get_rank_info();
    std::map<std::string, std::string> leaderboard = {
            {"rank", ""},
            {"name", rank_info["name"]},
            {"rating", rank_info["rating"]}
    };
    return leaderboard;

}

std::map<std::string, std::string> TournamentPlatform::generate_tournament_report()
{
    std::map<std::string, std::string> dict;
    if (cards.empty())
        dict = {
                {"total_cards", std::to_string(0)},
                {"matches_played", std::to_string(0)},
                {"avg_rating", std::to_string(0)},
                {"platform_status", "empty"}
    };
    else
        dict = {
                {"total_cards", std::to_string(cards.size())},
                {"matches_played", std::to_string(matches_played)},
                {"platform_status", "active"}
    };

    return dict;
}