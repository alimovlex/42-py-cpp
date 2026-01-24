#include <iostream>
#include <string>

class Plant
{
    public:
    std::string name;
    int height;
    int age;
    Plant(std::string name, int height, int age):
    name(name), height(height), age(age)
    {
        // this->name = name;
        // this->height = height;
        // this->age = age;
        std::cout << name << ": " << height << "cm, " << age <<  " days old";
        std::cout << std::endl;
    }
};

int main()
{
    std::cout << "=== Garden Plant Registry ===" << std::endl;
    Plant rose("Rose", 25, 30);
    Plant sunflower("Sunflower", 80, 45);
    Plant cactus("Cactus", 15, 120);
    return 0;
}
