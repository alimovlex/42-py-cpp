#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main(void) {
  std::cout << "=== Game Analytics Dashboard ===\n" << std::endl;
  std::vector<std::string> players = {"alice", "bob", "charlie", "diana"};
  std::vector<std::string> regions = {"north", "east", "central", "north"};
  std::vector<int> scores = {2300, 1800, 2150, 2050}, scores_doubled;
  std::vector<std::string> high_scorers, active_players;

  std::map<std::string, int> player_scores, score_categories, achievement_counts;
  int high = 0, medium = 0, low = 0;

  std::map<std::string, bool> active = {
      {"alice", true}, {"bob", true}, {"charlie", true}, {"diana", false}};

  std::map<std::string, std::vector<std::string>> achievements = {
      {"alice",
       {"first_kill", "level_10", "boss_slayer", "quest_complete",
        "treasure_hunter"}},
      {"bob", {"first_kill", "level_5", "quest_complete"}},
      {"diana", {"first_kill", "level_8", "quest_complete"}}};

  std::cout << "=== List Comprehension Examples ===" << std::endl;
  for (size_t i = 0; i < players.size(); ++i)
    if (scores[i] > 2000)
      high_scorers.push_back(players[i]);

  std::cout << "High scorers (>2000): [";
  for (auto &str : high_scorers)
    std::cout << "'" << str << "', ";
  std::cout << "]" << std::endl;

  for (auto &score : scores)
    scores_doubled.push_back(score * 2);

  std::cout << "Scores doubled: [";
  for (auto &score : scores_doubled)
    std::cout << score << ", ";
  std::cout << "]" << std::endl;

  for (const auto &player : players) {
    std::map<std::string, bool>::iterator itr = active.find(player);
    if (itr != active.end())
      if (itr->second == true)
        active_players.push_back(player);
  }

  std::cout << "Active players: [";
  for (auto &player : active_players)
    std::cout << "'" << player << "', ";
  std::cout << "]\n" << std::endl;

  std::cout << "=== Dict Comprehension Examples ===" << std::endl;
  for (size_t i = 0; i < players.size(); ++i)
    player_scores[players[i]] = scores[i];

  std::cout << "Player scores processed." << std::endl;
  for (int s : scores)
    if (s > 2000)
      high++;
    else if (s >= 1900)
      medium++;
    else
      low++;

  score_categories["high"] = high;
  score_categories["medium"] = medium;
  score_categories["low"] = low;

  std::cout << "Score categories: {";
  for (auto& score : score_categories)
    std::cout << "'" << score.first << "': " << score.second << ", ";
  std::cout << "}\n" << std::endl;

  for (const auto &player : players)
    if (achievements.count(player))
      achievement_counts[player] = achievements.at(player).size();
    else
      achievement_counts[player] = 0;

  std::cout << "=== Set Comprehension Examples ===" << std::endl;

  std::set<std::string> unique_players(players.begin(), players.end());

  std::set<std::string> unique_achievements;
  for (const auto &p : players) {
    if (achievements.count(p)) {
      for (const auto &ach : achievements.at(p)) {
        unique_achievements.insert(ach);
      }
    }
  }

  std::set<std::string> unique_regions(regions.begin(), regions.end());
  std::cout << "Active regions count: " << unique_regions.size() << "\n";

  std::cout << "\n=== Combined Analysis ===\n";

  int total_players = players.size();
  int total_unique_achievements = unique_achievements.size();

  double sum = 0;
  for (int s : scores)
    sum += s;
  double average_score = sum / scores.size();

  int max_score = scores[0];
  int top_index = 0;
  for (size_t i = 1; i < scores.size(); ++i) {
    if (scores[i] > max_score) {
      max_score = scores[i];
      top_index = i;
    }
  }

  std::string top_performer = players[top_index];
  int top_achievements = 0;
  if (achievements.count(top_performer)) {
    top_achievements = achievements.at(top_performer).size();
  }

  std::cout << "Total players: " << total_players << "\n";
  std::cout << "Total unique achievements: " << total_unique_achievements
            << "\n";
  std::cout << "Average score: " << average_score << "\n";
  std::cout << "Top performer: " << top_performer << " (" << max_score
            << " points, " << top_achievements << " achievements)\n";

  return 0;
}
