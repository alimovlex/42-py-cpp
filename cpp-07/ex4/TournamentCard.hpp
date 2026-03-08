#ifndef TOURNAMENTCARD_HPP
#define TOURNAMENTCARD_HPP

#include "../ex0/Card.hpp"
#include "../ex2/Combatable.hpp"
#include "Rankable.hpp"
#include <string>
#include <map>
#include <variant>
#include <vector>

class TournamentCard : public Card, public Combatable, public Rankable {
private:
    int attack_power;
    int health;
    int wins = 0;
    int losses = 0;
    int rating = 1200;
    std::string card_id;

public:
    TournamentCard(std::string name, int cost, std::string rarity, int attack, int health, std::string id)
        : Card(std::move(name), cost, std::move(rarity)), attack_power(attack), health(health), card_id(std::move(id)) {}

    std::map<std::string, std::variant<std::string, int>> play(std::map<std::string, std::variant<std::string, int>> game_state) override {
        return {
            {"card_played", name},
            {"mana_used", cost},
            {"effect", std::string("Tournament card entered play")}
        };
    }

    std::map<std::string, std::variant<std::string, int>> attack(const std::string& target) override {
        return {
            {"attacker", name},
            {"target", target},
            {"damage", attack_power}
        };
    }

    std::map<std::string, std::variant<std::string, int>> defend(int incoming_damage) override {
        health -= incoming_damage;
        return {
            {"defender", name},
            {"damage_taken", incoming_damage},
            {"still_alive", health > 0 ? 1 : 0}
        };
    }

    std::map<std::string, std::variant<std::string, int>> get_combat_stats() const override {
        return {
            {"attack", attack_power},
            {"health", health}
        };
    }

    int calculate_rating() const override {
        return rating;
    }

    void update_wins(int w) override {
        wins += w;
        rating += 16 * w;
    }

    void update_losses(int l) override {
        losses += l;
        rating -= 16 * l;
    }

    std::map<std::string, std::variant<std::string, int>> get_rank_info() const override {
        return {
            {"rating", rating},
            {"wins", wins},
            {"losses", losses}
        };
    }

    std::map<std::string, std::variant<std::string, int>> get_tournament_stats() const {
        return {
            {"id", card_id},
            {"name", name},
            {"rating", rating},
            {"record", std::to_string(wins) + "-" + std::to_string(losses)}
        };
    }

    std::string getId() const { return card_id; }
};

#endif
