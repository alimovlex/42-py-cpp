#include <iostream>
#include <variant>
#include <map>
#include <memory>
#include <vector>
#include "TournamentPlatform.hpp"
#include "TournamentCard.hpp"

void print_dict(const std::map<std::string, std::variant<std::string, int>>& dict)
{
    std::cout << "{";
    bool first = true;
    for (auto const& [key, val] : dict)
    {
        if (!first)
            std::cout << ", ";
        std::cout << "'" << key << "': ";
        if (std::holds_alternative<std::string>(val))
            std::cout << "'" << std::get<std::string>(val) << "'";
        else
            std::cout << std::get<int>(val);

        first = false;
    }
    std::cout << "}" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "=== DataDeck Tournament Platform ===" << std::endl;
    std::cout << "Registering Tournament Cards..." << std::endl;

    TournamentPlatform platform;
    
    std::shared_ptr<TournamentCard> dragon = std::make_shared<TournamentCard>("Fire Dragon", 5, "Legendary", 7, 5, "dragon_001");
    std::shared_ptr<TournamentCard> wizard = std::make_shared<TournamentCard>("Ice Wizard", 4, "Rare", 3, 4, "wizard_001");

    platform.register_card(dragon);
    platform.register_card(wizard);

    std::cout << "Fire Dragon (ID: dragon_001):" << std::endl;
    std::cout << "- Interfaces: [Card, Combatable, Rankable]" << std::endl;
    std::map<std::string, std::variant<std::string, int>> dragon_stats = dragon->get_tournament_stats();
    std::cout << "- Rating: " << std::get<int>(dragon_stats["rating"]) << std::endl;
    std::cout << "- Record: " << std::get<std::string>(dragon_stats["record"]) << std::endl;

    std::cout << "Ice Wizard (ID: wizard_001):" << std::endl;
    std::cout << "- Interfaces: [Card, Combatable, Rankable]" << std::endl;
    std::map<std::string, std::variant<std::string, int>> wizard_stats = wizard->get_tournament_stats();
    std::cout << "- Rating: " << std::get<int>(wizard_stats["rating"]) << std::endl;
    std::cout << "- Record: " << std::get<std::string>(wizard_stats["record"]) << std::endl;

    std::cout << "Creating tournament match..." << std::endl;
    std::map<std::string, std::variant<std::string, int>> match_result = platform.create_match("dragon_001", "wizard_001");
    std::cout << "Match result: ";
    print_dict(match_result);

    std::cout << "Tournament Leaderboard:" << std::endl;
    std::vector<std::map<std::string, std::variant<std::string, int>>> leaderboard = platform.get_leaderboard();
    int rank = 1;
    for (const auto& entry : leaderboard)
    {
        std::cout << rank++ << ". " << std::get<std::string>(entry.at("name")) 
                  << " - Rating: " << std::get<int>(entry.at("rating")) 
                  << " (" << std::get<std::string>(entry.at("record")) << ")" << std::endl;
    }

    std::cout << "Platform Report:" << std::endl;
    std::map<std::string, std::variant<std::string, int>> report = platform.generate_tournament_report();
    print_dict(report);

    std::cout << "=== Tournament Platform Successfully Deployed! ===" << std::endl;
    std::cout << "All abstract patterns working together harmoniously!" << std::endl;

    return 0;
}
