#include <iostream>
#include <string>

class Plant
{
  public:
  std::string name;
  int height;
  int days;
  Plant(std::string name, int height, int days):
  name(name), height(height), days(days)
  {
      // this->name = name;
      // this->height = height;
      // this->days = days;
  }
  void grow(int cm) { height += cm; }
  void age(int duration) { days+=duration; }
  void get_info(){ std::cout << name << ": " << height << "cm, " << days << " days old"; }
};

int main()
{
    Plant rose("Rose", 25, 30);
    std::cout << "=== Day 1 ===" << std::endl;
    rose.get_info();
    std::cout << std::endl;
    int first_day_height = rose.height;
    std::cout << "=== Day 7 ===" << std::endl;
    rose.grow(6);
    rose.age(6);
    rose.get_info();
    std::cout << std::endl;
    std::cout << "Growth this week: +" << rose.height - first_day_height << "cm";
    std::cout << std::endl;
    return 0;
}
