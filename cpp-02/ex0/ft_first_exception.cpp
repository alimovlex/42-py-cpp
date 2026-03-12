#include <iostream>
#include <string>
#include <array>
#include "check_temperature.hpp"

int main(int argc, char** argv)
{
    std::cout << "=== Garden Temperature Checker ===" << std::endl;
    //std::vector<std::string> vect = {"25", "abc", "100", "-50"};
    std::array<std::string, 4> arr = {"25", "abc", "100", "-50"};
    for(auto& i: arr)
        check_temperature(i);
    std::cout << "All tests completed - program didn't crash!" << std::endl;

  return 0;
}
