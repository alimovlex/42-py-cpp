#include <algorithm>
#include <iostream>
#include <string>
#include <set>

class Player
{
    public:
    std::set<std::string> achievements;

    void print_achievemets()
    {
        for(auto& str: this->achievements)
            std::cout << "'" << str << "'" << ", ";
        std::cout << " }" << std::endl;
    }

    Player(std::set<std::string>& achievements): achievements(achievements) { }
};

int main(void)
{
    std::cout << "=== Achievement Tracker System ===" << std::endl;
    std::set<std::string>::iterator it;
    std::set<std::string> unique_values;
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

    std::set<std::string> temp;
    std::set_union(
        unique_values.begin(),   unique_values.end(),
        charlie_achievements.begin(), charlie_achievements.end(),
        std::inserter(temp, temp.begin())
    );
    unique_values.swap(temp);

    std::cout << "All unique achievements: { ";
    for(auto& value: unique_values)
        std::cout << "'" << value << "'" << ", ";
    std::cout << " }" << std::endl;
    std::cout << "Total unique achievements: " << unique_values.size() << std::endl;
    return 0;
}
