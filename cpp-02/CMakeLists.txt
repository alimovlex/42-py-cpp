cmake_minimum_required(VERSION 3.25)
project(exception)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex0  ex0/ft_first_exception.cpp
                    ex0/check_temperature.cpp)
add_executable(ex1  ex1/ft_different_errors.cpp
                    ex1/test_exception_types.cpp)
add_executable(ex2  ex2/ft_custom_errors.cpp
                    ex2/test_exceptions.cpp)
add_executable(ex3  ex3/ft_finally_block.cpp
                    ex3/test_watering_system.cpp)
add_executable(ex4  ex4/ft_raise_errors.cpp)
add_executable(ex5  ex5/ft_garden_management.cpp)