#pragma once
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
    std::string register_card(std::shared_ptr<TournamentCard> card);
    std::map<std::string, std::variant<std::string, int>> create_match(const std::string& card1_id, const std::string& card2_id);
    std::vector<std::map<std::string, std::variant<std::string, int>>> get_leaderboard();
    std::map<std::string, std::variant<std::string, int>> generate_tournament_report() const;
};

