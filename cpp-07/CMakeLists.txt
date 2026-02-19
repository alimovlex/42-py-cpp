cmake_minimum_required(VERSION 3.25)
project(deck)

set(CMAKE_CXX_STANDARD 17)

add_executable(creature_card ex0/main.cpp
                             ex0/CreatureCard.cpp
                             ex0/Card.cpp)

