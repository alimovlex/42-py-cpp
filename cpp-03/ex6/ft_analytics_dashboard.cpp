#include <iostream>
#include <vector>
#include <string>
#include <map>

int main(void)
{
    std::cout << "=== Game Analytics Dashboard ===\n" << std::endl;
    std::vector<std::string> players = {"alice", "bob", "charlie", "diana"};
    std::vector<std::string> regions = {"north", "east", "central", "north"};
    std::vector<int> scores = {2300, 1800, 2150, 2050}, scores_doubled;
    std::vector<std::string> high_scorers, active_players;


    std::map<std::string, bool> active = {
        {"alice", true}, {"bob", true}, {"charlie", true}, {"diana", false}
    };

    std::map<std::string, std::vector<std::string>> achievements = {
      {
          "alice",
          {"first_kill", "level_10", "boss_slayer", "quest_complete", "treasure_hunter"}
      },
      {
          "bob",
          {"first_kill", "level_5", "quest_complete"}
      },
      {
          "diana",
          {"first_kill", "level_8", "quest_complete"}
      }
    };

    std::cout << "=== List Comprehension Examples ===" << std::endl;
    for (size_t i = 0; i < players.size(); ++i)
        if (scores[i] > 2000)
            high_scorers.push_back(players[i]);

    std::cout << "High scorers (>2000): [";
    for (auto& str: high_scorers)
        std::cout << "'" << str << "', ";
    std::cout << "]" << std::endl;

    for (auto& score: scores)
        scores_doubled.push_back(score * 2);

    std::cout << "Scores doubled: [";
    for (auto& score: scores_doubled)
        std::cout << score << ", ";
    std::cout << "]" << std::endl;

    for (const auto& player: players)
    {
        std::map<std::string, bool>::iterator itr = active.find(player);
        if (itr != active.end())
            if (itr->second == true)
                active_players.push_back(player);
    }

    std::cout << "Active players: [";
    for (auto& player: active_players)
        std::cout << "'" << player << "', ";
    std::cout << "]\n" << std::endl;

    std::cout << "=== Dict Comprehension Examples ===" << std::endl;

    return 0;
}
