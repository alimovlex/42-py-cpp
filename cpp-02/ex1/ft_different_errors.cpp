#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <map>

int test_number()
{
    int num = 0;
    try
    {
        num = std::stoi("abc");
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Error: '" << num << "' is not a valid number" << std::endl;
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return num;
}

int test_division()
{
    int num = 0;
    try
    {
        int divisor = 0;
        if (divisor == 0)
        {
            throw std::runtime_error("division by zero");
        }
        num /= divisor;
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Error: '" << num << "' division by zero" << std::endl;
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return num;
}

int test_file()
{
    const std::string fileName;
    std::ofstream file;
    file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try
    {
        file.open(fileName, std::ios::out);
        file << "This is awesome!" << std::endl;
    }
    catch (const std::ios_base::failure& e)
    {
        std::cerr << "Error: '" << fileName << "' is not a valid file" << std::endl;
        std::cerr << e.what() << std::endl;
        return 1;
    }
    file.close();
    return 0;
}

int test_dictionary()
{
    std::map<std::string, int> dictionary = {{"a", 1}, {"b", 2}};

    try
    {
        int value = dictionary.at("c");
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Error: '" << dictionary["c"] << "' is a nonexistent key" << std::endl;
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}

int garden_operations()
{
    int result = 0;
    result = test_number();
    result = test_division();
    result = test_file();
    result = test_dictionary();
    return result;
}

void test_error_types()
{
    std::cout << "=== Garden Operations Demo ===" << std::endl;
    int rc = garden_operations();
    if (rc == 0)
        std::cout << "All operations completed without triggering an error." << std::endl;
    else
        std::cout << "garden_operations returned error code " << rc << std::endl;
}

int main()
{
    test_error_types();
    return 0;
}
