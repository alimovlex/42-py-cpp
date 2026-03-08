//
// Created by alalimov on 3/8/26.
//

#pragma once
#include "TournamentCard.hpp"

class TournamentPlatform {
public:
    std::map<std::string, TournamentCard> cards;
    int matches_played;

    std::string register_card(TournamentCard card);
    std::map<std::string, std::string> create_match(std::string& card1_id, std::string& card2_id);
    std::map<std::string, std::string> get_leaderboard();
    std::map<std::string, std::string> generate_tournament_report();


    TournamentPlatform(): cards(), matches_played(0) {}

};

