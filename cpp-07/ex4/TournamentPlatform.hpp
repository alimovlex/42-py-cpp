#ifndef TOURNAMENTPLATFORM_HPP
#define TOURNAMENTPLATFORM_HPP

#include "TournamentCard.hpp"
#include <vector>
#include <memory>
#include <algorithm>
#include <map>
#include <string>
#include <variant>

class TournamentPlatform {
private:
    std::vector<std::shared_ptr<TournamentCard>> registered_cards;
    int matches_played = 0;

public:
    std::string register_card(std::shared_ptr<TournamentCard> card) {
        registered_cards.push_back(card);
        return card->getId();
    }

    std::map<std::string, std::variant<std::string, int>> create_match(const std::string& card1_id, const std::string& card2_id) {
        auto it1 = std::find_if(registered_cards.begin(), registered_cards.end(), [&](const std::shared_ptr<TournamentCard>& c) {
            return c->getId() == card1_id;
        });
        auto it2 = std::find_if(registered_cards.begin(), registered_cards.end(), [&](const std::shared_ptr<TournamentCard>& c) {
            return c->getId() == card2_id;
        });

        if (it1 == registered_cards.end() || it2 == registered_cards.end()) {
            return {{"error", std::string("Card not found")}};
        }

        std::shared_ptr<TournamentCard> winner = *it1;
        std::shared_ptr<TournamentCard> loser = *it2;

        // Simple win logic for demo: higher rating wins
        if ((*it2)->calculate_rating() > (*it1)->calculate_rating()) {
            std::swap(winner, loser);
        }

        winner->update_wins(1);
        loser->update_losses(1);
        matches_played++;

        return {
            {"winner", winner->getId()},
            {"loser", loser->getId()},
            {"winner_rating", winner->calculate_rating()},
            {"loser_rating", loser->calculate_rating()}
        };
    }

    std::vector<std::map<std::string, std::variant<std::string, int>>> get_leaderboard() {
        std::vector<std::shared_ptr<TournamentCard>> sorted_cards = registered_cards;
        std::sort(sorted_cards.begin(), sorted_cards.end(), [](const std::shared_ptr<TournamentCard>& a, const std::shared_ptr<TournamentCard>& b) {
            return a->calculate_rating() > b->calculate_rating();
        });

        std::vector<std::map<std::string, std::variant<std::string, int>>> leaderboard;
        for (const auto& card : sorted_cards) {
            leaderboard.push_back(card->get_tournament_stats());
        }
        return leaderboard;
    }

    std::map<std::string, std::variant<std::string, int>> generate_tournament_report() const {
        int total_rating = 0;
        for (const auto& card : registered_cards) {
            total_rating += card->calculate_rating();
        }
        int avg_rating = registered_cards.empty() ? 0 : total_rating / (int)registered_cards.size();

        return {
            {"total_cards", (int)registered_cards.size()},
            {"matches_played", matches_played},
            {"avg_rating", avg_rating},
            {"platform_status", std::string("active")}
        };
    }
};

#endif
