//
// Created by alalimov on 2/21/26.
//

#include "ArtifactCard.hpp"

int ArtifactCard::get_durability()
{
    return this->durability;
}

int ArtifactCard::get_current_durability()
{
    return this->current_durability;
}

std::string ArtifactCard::get_effect()
{
    return this->effect;
}

std::map<std::string, std::string> ArtifactCard::play(std::map<std::string, std::string> &game_state)
{
    std::map<std::string, std::string> dict = {
            {"card_played", name},
            {"mana_used", std::to_string(cost)},
            {"effect", "Permanent: " + effect}

    };
    return dict;
}

std::map<std::string, std::string> ArtifactCard::activate_ability()
{
    if (current_durability <= 0)
        return {
                {"artifact_name", name},
                {"activated", "False"},
                {"message", "Artifact is destroyed (no durability remaining)"}
    };

    current_durability--;
    bool is_destroyed = current_durability <= 0;

    return {
            {"artifact_name", name},
            {"activated", "True"},
            {"effect", effect},
            {"durability_remaining", std::to_string(current_durability)},
            {"destroyed", std::to_string(is_destroyed)}
    };

}

void ArtifactCard::repair(int amount)
{
    current_durability = std::min(current_durability + amount, durability);
}

std::string ArtifactCard::toString()
{
    return name + " (Artifact)";
}