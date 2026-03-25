cmake_minimum_required(VERSION 3.25)
project(deck C)

set(CMAKE_C_STANDARD 11)

add_executable(ex0  ex0/main.c
                    ex0/creature_card.c)

add_executable(ex1  ex1/main.c
                    ex1/deck.c
                    ex1/spell_card.c
                    ex1/artifact_card.c
                    ex0/creature_card.c)

add_executable(ex2  ex2/main.c
                    ex2/elite_card.c
                    ex0/creature_card.c)

add_executable(ex3  ex3/main.c
                    ex3/game_engine.c
                    ex3/fantasy_card_factory.c
                    ex3/aggressive_strategy.c
                    ex1/artifact_card.c
                    ex1/spell_card.c
                    ex0/creature_card.c)

add_executable(ex4  ex4/main.c
                    ex4/tournament_platform.c
                    ex4/tournament_card.c
                    ex0/creature_card.c)