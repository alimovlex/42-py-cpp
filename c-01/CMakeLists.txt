cmake_minimum_required(VERSION 3.25)
project(garden)

set(CMAKE_C_STANDARD 17)

add_executable(ex0  ex0/ft_garden_intro.c)
add_executable(ex1  ex1/ft_garden_data.c
                    ex1/Plant.c)
add_executable(ex2  ex2/ft_plant_growth.c
                    ex2/Plant.c)
add_executable(ex3  ex3/ft_plant_factory.c
                    ex3/Plant.c)
add_executable(ex4  ex4/ft_garden_security.c
                    ex4/SafePlant.c)
add_executable(ex5  ex5/ft_plant_types.c
                    ex5/Flower.c
                    ex5/Tree.c
                    ex5/Vegetable.c ex5/Plant.c)
target_link_libraries(ex5 m)