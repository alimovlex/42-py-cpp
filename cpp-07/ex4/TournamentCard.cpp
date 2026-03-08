//
// Created by alalimov on 3/8/26.
//

#include "TournamentCard.hpp"

std::map<std::string, std::string> TournamentCard::play(std::map<std::string, std::string> &game_state)
{
    std::map<std::string, std::string> dict = {
            {"card_played", name},
            {"mana_used", std::to_string(cost)},
            {"effect", "Tournament card played"},
            {"card_type", "tournament"},
            {"rating", std::to_string(rating)}
    };
    return dict;
}

std::map<std::string, std::string> TournamentCard::get_card_info()
{
    std::map<std::string, std::string> dict = {
            {"name", name},
            {"cost", std::to_string(cost)},
            {"rarity", rarity},
            {"type", "tournament"},
            {"rating", std::to_string(rating)}
    };
    return dict;
}

bool TournamentCard::is_playable(int available_mana)
{
    bool isPlayable = available_mana >= cost;
    return isPlayable;
}

std::map<std::string, std::string> TournamentCard::attack(std::string &target)
{
    std::map<std::string, std::string> dict = {
            {"attacker", name},
            {"target", target},
            {"damage", std::to_string(attack_power)},
            {"combat_type", "tournament_combat"}
    };
    return dict;
}

std::map<std::string, std::string> TournamentCard::defend(int &incoming_damage)
{
    int damage_blocked = std::min(defense, incoming_damage);
    int damage_taken = incoming_damage - damage_blocked;
    bool is_survived = damage_taken < defense;
    std::map<std::string, std::string> dict = {
            {"defender", name},
            {"damage_taken", std::to_string(damage_taken)},
            {"damage_blocked", std::to_string(damage_blocked)},
            {"survived", std::to_string(is_survived)}
    };
    return dict;
}

std::map<std::string, std::string> TournamentCard::get_combat_stats()
{
    std::map<std::string, std::string> dict = {
            {"attack", std::to_string(attack_power)},
            {"defense", std::to_string(defense)},
            {"power_rating", std::to_string(attack_power + defense)}
    };
    return dict;
}

int TournamentCard::calculate_rating()
{
    const int win_value = 16;
    rating = base_rating + (wins * win_value) - (losses * win_value);
    return rating;
}

void TournamentCard::update_wins(int wins)
{
    this->wins += wins;
    calculate_rating();
}

void TournamentCard::update_losses(int losses)
{
    this->losses += losses;
    calculate_rating();
}

std::map<std::string, std::string> TournamentCard::get_rank_info()
{
    std::map<std::string, std::string> dict = {
            {"name", name},
            {"rating", std::to_string(rating)},
            {"wins", std::to_string(wins)},
            {"losses", std::to_string(losses)},
            {"record", std::to_string(wins - losses)}
    };
    return dict;
}

std::map<std::string, std::map<std::string, std::string>> TournamentCard::get_tournament_stats()
{
    std::map<std::string, std::map<std::string, std::string>> dict = {
            {"card_info", get_card_info()},
            {"combat_stats", get_combat_stats()},
            {"rank_info", get_rank_info()}
    };
    return dict;
}

std::string TournamentCard::toString()
{
    return name + "(Tournament Card)";
}