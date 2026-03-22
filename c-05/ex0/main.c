//
// Created by robot on 3/12/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataProcessor.h"
#include "NumericProcessor.h"
#include "TextProcessor.h"
#include "LogProcessor.h"

int test_data_processor(struct DataProcessor* test, char* data)
{
    /*
    bool value = test->validate(data);
    std::ostringstream oss;
    oss << std::boolalpha << value;
    std::string result = oss.str();
    std::cout << test->process(data) << std::endl;
    std::cout << result << std::endl;
    std::cout << test->format_output("hello") << std::endl;
    */
    return 0;
}

int main(int argc, char** argv)
{
    struct DataProcessor* test = (struct DataProcessor*)malloc(sizeof (struct DataProcessor));
    int list_data = {1, 2, 3, 4, 5};
    int new_list_data = {1, 2, 3};
    char* str_data = "Hello Nexus World",
            data_log = "INFO: System ready, ERROR", new_str_data = "helloo Nexus",
            new_data_log = "System ready";
    //std::vector<std::any> test_data = {new_list_data, new_str_data, new_data_log};

    printf("=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===\n");
    printf("Initializing Numeric Processor...\n");
    test = (struct NumericProcessor *)malloc(sizeof (struct DataProcessor));
    //test = std::make_unique<NumericProcessor>();
    //test_data_processor(test, list_data);

    printf("Initializing Text Processor...\n");
    //(struct NumericProcessor *)test;
    test = (struct NumericProcessor *)malloc(sizeof (struct DataProcessor));
    //test = std::make_unique<TextProcessor>();
    //test_data_processor(test, str_data);

    printf("Initializing Log Processor...\n");
    test = (struct LogProcessor *)malloc(sizeof (struct DataProcessor));
    /*
    test = std::make_unique<LogProcessor>();
    test_data_processor(test, data_log);
    std::cout << std::endl;
    */
    printf("=== Polymorphic Processing Demo ===\n");
    printf("Processing multiple data types through same interface...\n");
    /*
    std::vector<std::unique_ptr<DataProcessor>> polymorf_all;
    std::vector<std::unique_ptr<DataProcessor>>::iterator i;

    polymorf_all.push_back(std::make_unique<NumericProcessor>());
    polymorf_all.push_back(std::make_unique<TextProcessor>());
    polymorf_all.push_back(std::make_unique<LogProcessor>());
    auto itr1 = polymorf_all.begin();
    auto itr2 = test_data.begin();

    for (; itr1 != polymorf_all.end() && itr2 != test_data.end(); ++itr1, ++itr2)
    test_data_processor(*itr1, *itr2);
    */
    printf("Foundation system online. Nexus ready for advanced streams.\n");

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
