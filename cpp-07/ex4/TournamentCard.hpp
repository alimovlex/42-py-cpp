//
// Created by alalimov on 3/8/26.
//

#pragma once
#include "Rankable.hpp"
#include "../ex0/Card.hpp"
#include "../ex2/Combatable.hpp"

class TournamentCard: public Card, public Combatable, public Rankable {

public:
    std::string name, rarity;
    int cost, attack_power, defense, wins, losses, base_rating, rating;

    std::map<std::string, std::string> play(std::map<std::string, std::string> &game_state) override;
    std::map<std::string, std::string> get_card_info() override;
    std::map<std::string, std::string> attack(std::string &target) override;
    std::map<std::string, std::string> defend(int &incoming_damage) override;
    std::map<std::string, std::string> get_combat_stats() override;
    int calculate_rating() override;
    void update_wins(int wins) override;
    void update_losses(int losses) override;
    std::map<std::string, std::string> get_rank_info() override;

    std::map<std::string, std::map<std::string, std::string>> get_tournament_stats();
    bool is_playable(int available_mana);
    std::string toString();

    TournamentCard(std::string& name, int cost, std::string& rarity, int attack_power, int defense):
    Card(name, cost, rarity), name(name), cost(cost), rarity(rarity), attack_power(attack_power), defense(defense),
    wins(0), losses(0), base_rating(1200), rating(base_rating) {}
};

