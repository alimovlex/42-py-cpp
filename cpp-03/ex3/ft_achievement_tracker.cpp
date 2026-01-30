#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

class Player
{
    public:
    std::set<std::string> achievements;

    void print_achievemets()
    {
        for(auto& str: this->achievements)
            std::cout << "'" << str << "'" << ", ";
        std::cout << "}" << std::endl;
    }

    Player(std::set<std::string>& achievements): achievements(achievements) { }
};

int main(void)
{
    std::cout << "=== Achievement Tracker System ===" << std::endl;
    std::set<std::string> unique_values;
    std::set<std::string> intersection_values;
    std::set<std::string> different_values;
    std::set<std::string> common_values;
    std::set<std::string> alice_unique;

    std::set<std::string> temp;
    std::unordered_map<std::string, int> occurence;
    std::set<std::string> alice_achievements = {
        "first kill",
        "level_10",
        "treasure_hunter",
        "speed_demon"
    };
    std::set<std::string> bob_achievements = {
        "first kill",
        "level_10",
        "boss_slayer",
        "collector"
    };
    std::set<std::string> charlie_achievements = {
        "level_10",
        "treasure_hunter",
        "boss_slayer",
        "speed_demon",
        "perfectionist"
    };
    Player alice = Player(alice_achievements);
    Player bob = Player(bob_achievements);
    Player charlie = Player(charlie_achievements);

    std::cout << "Player alice achievements: {";
    alice.print_achievemets();
    std::cout << "Player bob achievements: {";
    bob.print_achievemets();
    std::cout << "Player charlie achievements: {";
    charlie.print_achievemets();

    std::cout << "=== Achievement Analytics ===" << std::endl;

    std::set_union(
        alice_achievements.begin(), alice_achievements.end(),
        bob_achievements.begin(),   bob_achievements.end(),
        std::inserter(unique_values, unique_values.begin())
    );

    std::set_union(
        unique_values.begin(),   unique_values.end(),
        charlie_achievements.begin(), charlie_achievements.end(),
        std::inserter(temp, temp.begin())
    );
    unique_values.swap(temp);

    std::cout << "All unique achievements: {";
    for(auto& value: unique_values)
        std::cout << "'" << value << "'" << ", ";
    std::cout << "}" << std::endl;
    std::cout << "Total unique achievements: " << unique_values.size() << std::endl;

    temp.clear();

    std::set_intersection(
        alice_achievements.begin(),   alice_achievements.end(),
        bob_achievements.begin(),     bob_achievements.end(),
        std::inserter(intersection_values, intersection_values.begin())
    );

    std::set_intersection(
        intersection_values.begin(),  intersection_values.end(),
        charlie_achievements.begin(), charlie_achievements.end(),
        std::inserter(temp, temp.begin())
    );
    intersection_values.swap(temp);

    std::cout << "Common to all players: {";
    for(auto& value: intersection_values)
        std::cout << "'" << value << "'" << ", ";
    std::cout << "}" << std::endl;

    temp.clear();

    for (const auto& achievement : alice_achievements)
        ++occurence[achievement];
    for (const auto& achievement : bob_achievements)
        ++occurence[achievement];
    for (const auto& achievement : charlie_achievements)
        ++occurence[achievement];

    for (const auto& [achievement, count] : occurence)
    {
        if (count == 1)
            different_values.insert(achievement);
    }

    std::cout << "Rare achievements (1 player): {";
    for (const auto& value : different_values)
        std::cout << "'" << value << "'" << ", ";
    std::cout << "}" << std::endl;

    std::set_intersection(
        alice_achievements.begin(),   alice_achievements.end(),
        bob_achievements.begin(),     bob_achievements.end(),
        std::inserter(common_values, common_values.begin())
    );

    std::set_difference(
        alice_achievements.begin(),   alice_achievements.end(),
        bob_achievements.begin(),     bob_achievements.end(),
        std::inserter(alice_unique, alice_unique.begin())
    );

    std::set<std::string> bob_unique;
    std::set_difference(
        bob_achievements.begin(),     bob_achievements.end(),
        alice_achievements.begin(),   alice_achievements.end(),
        std::inserter(bob_unique, bob_unique.begin())
    );

    std::cout << "Alice vs Bob common: {";
    for (const auto& value : common_values)
        std::cout << "'" << value << "'" << ", ";
    std::cout << "}" << std::endl;

    std::cout << "Alice unique: {";
    for (const auto& value : alice_unique)
        std::cout << "'" << value << "'" << ", ";
    std::cout << "}" << std::endl;

    std::cout << "Bob unique: {";
    for (const auto& value : bob_unique)
        std::cout << "'" << value << "'" << ", ";
    std::cout << "}" << std::endl;
    return 0;
}
