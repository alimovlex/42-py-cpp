//
// Created by robot on 3/12/26.
//

#include "TournamentCard.hpp"

std::map<std::string, std::variant<std::string, int>>
TournamentCard::play(std::map<std::string, std::variant<std::string, int>> game_state)
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"card_played", name},
            {"mana_used", cost},
            {"effect", std::string("Tournament card entered play")}
    };
    return dict;
}

std::map<std::string, std::variant<std::string, int>> TournamentCard::attack(const std::string &target)
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"attacker", name},
            {"target", target},
            {"damage", attack_power}
    };
    return dict;
}

std::map<std::string, std::variant<std::string, int>> TournamentCard::defend(int incoming_damage)
{
    health -= incoming_damage;
    int is_still_alive = 0;
    if (health > 0)
        is_still_alive = 1;
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"defender", name},
            {"damage_taken", incoming_damage},
            {"still_alive", is_still_alive}
    };
    return dict;
}

std::map<std::string, std::variant<std::string, int>> TournamentCard::get_combat_stats() const
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"attack", attack_power},
            {"health", health}
    };
    return dict;
}

std::map<std::string, std::variant<std::string, int>> TournamentCard::get_rank_info() const
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"rating", rating},
            {"wins", wins},
            {"losses", losses}
    };
    return dict;
}

std::map<std::string, std::variant<std::string, int>> TournamentCard::get_tournament_stats() const
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"id", card_id},
            {"name", name},
            {"rating", rating},
            {"record", std::to_string(wins) + "-" + std::to_string(losses)}
    };
    return dict;
}

int TournamentCard::calculate_rating() const
{
    return rating;
}

void TournamentCard::update_wins(int w)
{
    wins += w;
    rating += 16 * w;
}

void TournamentCard::update_losses(int l)
{
    losses += l;
    rating -= 16 * l;
}

std::string TournamentCard::getId() const
{
    return card_id;
}