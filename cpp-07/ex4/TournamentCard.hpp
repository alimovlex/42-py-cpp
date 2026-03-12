#pragma once
#include "../ex0/Card.hpp"
#include "../ex2/Combatable.hpp"
#include "Rankable.hpp"
#include <string>
#include <map>
#include <variant>
#include <vector>

class TournamentCard : public Card, public Combatable, public Rankable {
private:
    int attack_power, health, wins = 0, losses = 0, rating = 1200;
    std::string card_id;

public:
    TournamentCard(std::string name, int cost, std::string rarity, int attack, int health, std::string id)
        : Card(std::move(name), cost, std::move(rarity)), attack_power(attack), health(health), card_id(std::move(id)) {}

    std::map<std::string, std::variant<std::string, int>> play(std::map<std::string, std::variant<std::string, int>> game_state) override;
    std::map<std::string, std::variant<std::string, int>> attack(const std::string& target) override;
    std::map<std::string, std::variant<std::string, int>> defend(int incoming_damage) override;
    std::map<std::string, std::variant<std::string, int>> get_combat_stats() const override;
    int calculate_rating() const override;
    void update_wins(int w) override;
    void update_losses(int l) override;
    std::map<std::string, std::variant<std::string, int>> get_rank_info() const override;
    std::map<std::string, std::variant<std::string, int>> get_tournament_stats() const;
    std::string getId() const;
};
