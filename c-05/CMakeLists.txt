cmake_minimum_required(VERSION 3.25)
project(processor)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex0  ex0/main.c
                    ex0/NumericProcessor.c
                    ex0/TextProcessor.c
                    ex0/LogProcessor.c
                    ex0/template_functions.c)
add_executable(ex1  ex1/main.c
                    ex1/SensorStream.c
                    ex1/TransactionStream.c
                    ex1/EventStream.c
                    ex1/StreamProcessor.c
                    ex1/test_data_stream.c)
