#include <iostream>
#include "test_watering_system.hpp"

int main(int argc, char** argv)
{
  std::cout << "=== Garden Watering System ===" << std::endl;
  test_watering_system();
  std::cout << "Cleanup always happens, even with errors!" << std::endl;
  return 0;
}
