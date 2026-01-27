#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <ranges>

int main(int argc, char** argv)
{
    std::cout << "=== Player Score Analytics ===" << std::endl;
    if (argc < 2)
        std::cout << "No scores provided. Usage: python3 ft_score_analytics.py <score1> <score2> ..." << std::endl;
    else
    {
        std::vector<int> score_list;
        int total_score = 0, score = 0;

    while(*++argv)
        try
        {
            score_list.push_back(std::stoi(*argv));
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Error: " << *argv << "is not a valid score!";
        }

    std::cout << "Scores processed: [";
    for(auto& score: score_list)
         std::cout << score << ", ";
    std::cout << "]" << std::endl;
    total_score = std::accumulate(score_list.begin(), score_list.end(), 0);
    std::cout << "Total players: " << argc - 1 << std::endl;
    std::cout << "Total score: " << total_score << std::endl;
    std::cout << "Average score: " << total_score / score_list.size() << std::endl;
    std::cout << "High score: " << *std::max_element(score_list.begin(), score_list.end()) << std::endl;
    std::cout << "Low score: " << *std::min_element(score_list.begin(), score_list.end()) << std::endl;
    auto rng = [&]() -> int
    {
        if (score_list.size() == 1)
        {
            return *std::ranges::max_element(score_list);
        }
        else
        {
            auto [min_it, max_it] = std::ranges::minmax_element(score_list);
            return *max_it - *min_it;
        }
        return 0;
    }();
    std::cout << "Score range: " << rng << std::endl;
    }
    return 0;
}
