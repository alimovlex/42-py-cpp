#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

int main(int argc, char** argv)
{
    std::cout << "=== Player Score Analytics ===" << std::endl;
    if (argc < 2)
        std::cout << "No scores provided. Usage: a.out <score1> <score2> ..." << std::endl;
    else
    {
        std::vector<int> score_list;
        int total_score = 0, score = 0, range = 0, max = 0, min = 0;

    while(*++argv)
        try
        {
            score_list.push_back(std::stoi(*argv));
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Error: " << *argv << "is not a valid score!" << std::endl;
        }

    std::cout << "Scores processed: [";
    for(auto& score: score_list)
         std::cout << score << ", ";
    std::cout << "]" << std::endl;
    total_score = std::accumulate(score_list.begin(), score_list.end(), 0);
    max = *std::max_element(score_list.begin(), score_list.end());
    min = *std::min_element(score_list.begin(), score_list.end());
    std::cout << "Total players: " << argc - 1 << std::endl;
    std::cout << "Total score: " << total_score << std::endl;
    std::cout << "Average score: " << total_score / score_list.size() << std::endl;
    std::cout << "High score: " << max << std::endl;
    std::cout << "Low score: " << min << std::endl;
    if (score_list.size() == 1)
        range = max;
    else
        range = max - min;
    std::cout << "Score range: " << range << std::endl;
    }
    return 0;
}
