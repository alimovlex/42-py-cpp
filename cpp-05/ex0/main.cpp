//
// Created by robot on 3/12/26.
//

#include <cstddef>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <any>
#include "DataProcessor.hpp"
#include "NumericProcessor.hpp"
#include "TextProcessor.hpp"
#include "LogProcessor.hpp"

int test_data_processor(std::unique_ptr<DataProcessor>& test, const std::any& data)
{
    bool value = test->validate(data);
    std::ostringstream oss;
    oss << std::boolalpha << value;
    std::string result = oss.str();
    std::cout << test->process(data) << std::endl;
    std::cout << result << std::endl;
    std::cout << test->format_output("hello") << std::endl;
    return 0;
}

int main(int argc, char** argv)
{
    std::unique_ptr<DataProcessor> test;

    std::vector<int> list_data = {1, 2, 3, 4, 5};
    std::vector<int> new_list_data = {1, 2, 3};
    std::string str_data = "Hello Nexus World",
            data_log = "INFO: System ready, ERROR", new_str_data = "helloo Nexus",
            new_data_log = "System ready";
    std::vector<std::any> test_data = {new_list_data, new_str_data, new_data_log};

    std::cout << "=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===\n" << std::endl;
    std::cout << "Initializing Numeric Processor..." << std::endl;
    test = std::make_unique<NumericProcessor>();
    test_data_processor(test, list_data);

    std::cout << "Initializing Text Processor..." << std::endl;
    test = std::make_unique<TextProcessor>();
    test_data_processor(test, str_data);

    std::cout << "Initializing Log Processor..." << std::endl;
    test = std::make_unique<LogProcessor>();
    test_data_processor(test, data_log);
    std::cout << std::endl;

    std::cout << "=== Polymorphic Processing Demo ===\n" << std::endl;
    std::cout << "Processing multiple data types through same interface..." << std::endl;

    std::vector<std::unique_ptr<DataProcessor>> polymorf_all;
    std::vector<std::unique_ptr<DataProcessor>>::iterator i;

    polymorf_all.push_back(std::make_unique<NumericProcessor>());
    polymorf_all.push_back(std::make_unique<TextProcessor>());
    polymorf_all.push_back(std::make_unique<LogProcessor>());
    auto itr1 = polymorf_all.begin();
    auto itr2 = test_data.begin();

    for (; itr1 != polymorf_all.end() && itr2 != test_data.end(); ++itr1, ++itr2)
        test_data_processor(*itr1, *itr2);

    std::cout << "Foundation system online. Nexus ready for advanced streams." << std::endl;

    return 0;
}

/*
std::unique_ptr<DataProcessor> test = std::make_unique<NumericProcessor>();
std::unique_ptr<NumericProcessor> test(new NumericProcessor); //old form of definition
DataProcessor* test = new NumericProcessor(); //old form of definition
test = new TextProcessor();
delete test;
test = new LogProcessor();
delete test;
test = nullptr;


if (auto str_ptr = std::any_cast<std::string>(&data)) {
    std::cout << *str_ptr << "\n"; // str_ptr is non-null if cast succeeds
} else {
    std::cout << "data is not a string\n";
}
*/
