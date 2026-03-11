cmake_minimum_required(VERSION 3.25)
project(deck)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex0  ex0/main.cpp
                    ex0/Card.cpp
                    ex0/CreatureCard.cpp)
add_executable(ex1  ex1/main.cpp
                    ex1/Deck.cpp
                    ex1/SpellCard.cpp
                    ex1/ArtifactCard.cpp
                    ex0/CreatureCard.cpp
                    ex0/Card.cpp)
add_executable(ex2  ex2/main.cpp
                    ex2/EliteCard.cpp
                    ex0/Card.cpp)
add_executable(ex3  ex3/main.cpp
                    ex3/GameEngine.cpp
                    ex3/FantasyCardFactory.cpp
                    ex3/AggressiveStrategy.cpp
                    ex1/ArtifactCard.cpp
                    ex1/SpellCard.cpp
                    ex0/Card.cpp
                    ex0/CreatureCard.cpp)
add_executable(ex4 ex4/main.cpp)