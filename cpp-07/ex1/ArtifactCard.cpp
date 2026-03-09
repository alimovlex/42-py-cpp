//
// Created by robot on 3/9/26.
//

#include "ArtifactCard.hpp"

std::map<std::string, std::variant<std::string, int>>
ArtifactCard::play(std::map<std::string, std::variant<std::string, int>> game_state)
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"card_played", name},
            {"mana_used", cost},
            {"effect", std::string("Permanent: ") + effect}
    };

    return dict;
}

std::map<std::string, std::variant<std::string, int>> ArtifactCard::activate_ability()
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"artifact", name},
            {"ability_activated", 1},
            {"effect_applied", effect}
    };

    return dict;
}