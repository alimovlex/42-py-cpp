//
// Created by robot on 3/12/26.
//

#include "test_data_stream.hpp"

void print_any_vector(const std::vector<std::any>& databatch)
{
    std::cout << "[";
    for (const auto& element : databatch)
    {
        // adjust type as needed
        const auto& str = std::any_cast<const std::string&>(element);
        std::cout << str << ", ";
    }
    std::cout << "]" << std::endl;
}

int test_data_stream(std::unique_ptr<DataStream>& test, const std::string& stream_name,
                     const std::vector<std::any>& data, const std::string& key_one, const std::string& key_two)
{
    std::cout << test->process_batch(data) << std::endl;
    test->filter_data(data, std::nullopt);
    print_any_vector(data);
    std::map<std::string, std::variant<std::string, int, double>> dict = test->get_stats();
    std::cout << stream_name << " analysis: " << std::endl;
    std::visit([](auto&& x){ std::cout << x << " "; }, dict[key_one]);
    std::cout << key_one << ", " << key_two << ": ";
    std::visit([](auto&& x){ std::cout << x << " "; }, dict[key_two]);
    std::cout << std::endl << std::endl;
    return 0;
}