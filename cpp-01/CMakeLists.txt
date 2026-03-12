cmake_minimum_required(VERSION 3.25)
project(garden)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex0  ex0/ft_garden_intro.cpp)
add_executable(ex1  ex1/ft_garden_data.cpp
                    ex1/Plant.cpp)
add_executable(ex2  ex2/ft_plant_growth.cpp
                    ex2/Plant.cpp)
add_executable(ex3  ex3/ft_plant_factory.cpp
                    ex3/Plant.cpp)
add_executable(ex4  ex4/ft_garden_security.cpp
                    ex4/SafePlant.cpp)
add_executable(ex5  ex5/ft_plant_types.cpp
                    ex5/Flower.cpp
                    ex5/Tree.cpp
                    ex5/Vegetable.cpp)
add_executable(ex6  ex6/ft_garden_analytics.cpp
                    ex6/Plant.cpp
                    ex6/FloweringPlant.cpp
                    ex6/PrizeFlower.cpp
                    ex6/Garden.cpp
                    ex6/GardenManager.cpp
                    ex6/GardenStats.cpp)