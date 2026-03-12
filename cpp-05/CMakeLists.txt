cmake_minimum_required(VERSION 3.25)
project(processor)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex0  ex0/main.cpp
                    ex0/NumericProcessor.cpp
                    ex0/TextProcessor.cpp
                    ex0/LogProcessor.cpp
                    ex0/template_functions.cpp)
add_executable(ex1  ex1/main.cpp
                    ex1/SensorStream.cpp
                    ex1/TransactionStream.cpp
                    ex1/EventStream.cpp
                    ex1/StreamProcessor.cpp
                    ex1/test_data_stream.cpp)
add_executable(ex2  ex2/main.cpp
                    ex2/InputStage.cpp
                    ex2/TransformStage.cpp
                    ex2/OutputStage.cpp
                    ex2/ProcessingPipeline.cpp
                    ex2/JSONAdapter.cpp
                    ex2/CSVAdapter.cpp
                    ex2/StreamAdapter.cpp
                    ex2/NexusManager.cpp)