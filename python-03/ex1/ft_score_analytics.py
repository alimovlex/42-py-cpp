#!/usr/bin/env python3

import sys

if __name__ == "__main__":
    print("=== Player Score Analytics ===")

    if len(sys.argv) < 2:
        print(
            "No scores provided. Usage: python3 "
            "ft_score_analytics.py <score1> <score2> ..."
        )
    else:
        score_list = []
        for arg in sys.argv[1:]:
            try:
                score_list += [int(arg)]
            except ValueError:
                print(f"Error: {arg} is not a valid score!")

        print(f"Scores processed: {score_list}")
        total_score = sum(score_list)
        high_score = max(score_list)
        low_score = min(score_list)

        print(f"Total players: {len(sys.argv) - 1}")
        print(f"Total score: {total_score}")
        print(f"Average score: {total_score / len(score_list)}")
        print(f"High score: {high_score}")
        print(f"Low score: {low_score}")

        score_range = 0
        if len(score_list) == 1:
            score_range = high_score
        else:
            score_range = high_score - low_score
        print(f"Score range: {score_range}")
