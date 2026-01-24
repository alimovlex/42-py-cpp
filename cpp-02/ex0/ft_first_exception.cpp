#include <iostream>
#include <string>
#include <array>

int check_temperature(std::string& temp_str)
{
    std::cout << "Testing temperature: " << temp_str << std::endl;

    try
    {
      int temp = std::stoi(temp_str);
      if (temp > 40)
      {
          std::cout << "Error: " << temp << "°C is too hot for plants (max 40°C)" << std::endl;
          return 1;
      }
      else if (temp < 0)
      {
          std::cout << "Error: " << temp << "°C is too cold for plants (min 0°C)" << std::endl;
          return 1;
      }
        std::cout << "Temperature " << temp << "°C is perfect for plants!" << std::endl;
        return temp;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Error: '" << temp_str << "' is not a valid number" << std::endl;
        //std::cout << e.what() << std::endl;
        return 1;
    }
    /*
    catch (const std::exception& e)
    {
        std::cout << "Error: '" << temp_str << " " << e.what() << std::endl;
    }
    */

}

int main()
{
    std::cout << "=== Garden Temperature Checker ===" << std::endl;
    //std::vector<std::string> vect = {"25", "abc", "100", "-50"};
    std::array<std::string, 4> arr = {"25", "abc", "100", "-50"};
    for(auto& i: arr)
        check_temperature(i);
    std::cout << "All tests completed - program didn't crash!" << std::endl;

  return 0;
}
