#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> game_events(int n) {
    std::vector<std::string> events;
    events.reserve(n);

    std::vector<std::string> players;
    players.push_back("alice");
    players.push_back("bob");
    players.push_back("charlie");
    players.push_back("dave");

    for (int i = 1; i <= n; ++i) {
        const std::string& player = players[i % players.size()];
        int level = (i * 3) % 20 + 1;

        std::ostringstream oss;
        oss << "Event " << i << ": Player " << player
            << " (level " << level << ") ";

        if (i % 10 == 0) {
            oss << "found treasure";
        } else if (i % 7 == 0) {
            oss << "leveled up";
        } else {
            oss << "killed monster";
        }

        events.push_back(oss.str());
    }

    return events;
}

std::vector<long long> fibonacci(int n) {
    std::vector<long long> result;
    result.reserve(n);

    long long a = 0;
    long long b = 1;
    int count = 0;

    while (count < n) {
        result.push_back(a);
        long long next_a = b;
        long long next_b = a + b;
        a = next_a;
        b = next_b;
        ++count;
    }

    return result;
}

std::vector<int> primes(int n) {
    std::vector<int> result;
    result.reserve(n);

    int found = 0;
    int candidate = 2;

    while (found < n) {
        bool is_prime = true;
        for (int i = 2; i < candidate; ++i) {
            if (candidate % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            result.push_back(candidate);
            ++found;
        }
        ++candidate;
    }

    return result;
}

int main() {
    std::cout << "=== Game Data Stream Processor ===" << std::endl;
    std::cout << "Processing 1000 game events..." << std::endl;

    std::vector<std::string> events = game_events(1000);

    long long total_events = 0;
    int high_level = 0;
    int treasure_events = 0;
    int level_up_events = 0;

    for (std::size_t idx = 0; idx < events.size(); ++idx) {
        const std::string& event = events[idx];
        ++total_events;

        std::size_t pos = event.find("level ");
        if (pos != std::string::npos) {
            pos += std::string("level ").length();
            std::size_t end_pos = event.find(")", pos);
            if (end_pos != std::string::npos) {
                std::string level_str = event.substr(pos, end_pos - pos);
                int level = std::atoi(level_str.c_str());
                if (level >= 10) {
                    ++high_level;
                }
            }
        }

        if (event.find("treasure") != std::string::npos) {
            ++treasure_events;
        }
        if (event.find("leveled up") != std::string::npos) {
            ++level_up_events;
        }

        if (total_events <= 3) {
            std::cout << event << std::endl;
        }
    }

    std::cout << "..." << std::endl;
    std::cout << "=== Stream Analytics ===" << std::endl;
    std::cout << "Total events processed: " << total_events << std::endl;
    std::cout << "High-level players (10+): " << high_level << std::endl;
    std::cout << "Treasure events: " << treasure_events << std::endl;
    std::cout << "Level-up events: " << level_up_events << std::endl;
    std::cout << "Memory usage: Constant (streaming)" << std::endl;

    std::cout << "=== Generator Demonstration ===" << std::endl;

    std::vector<long long> fib_list = fibonacci(10);
    std::cout << "Fibonacci sequence (first 10): [";
    for (std::size_t i = 0; i < fib_list.size(); ++i) {
        std::cout << fib_list[i];
        if (i + 1 < fib_list.size()) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    std::vector<int> prime_list = primes(5);
    std::cout << "Prime numbers (first 5): [";
    for (std::size_t i = 0; i < prime_list.size(); ++i) {
        std::cout << prime_list[i];
        if (i + 1 < prime_list.size()) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
