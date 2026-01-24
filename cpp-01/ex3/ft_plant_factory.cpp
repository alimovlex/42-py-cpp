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
        instance_count++;
        std::cout << "Created: " << name << " (" << height << "cm, " << age <<  " days)";
        std::cout << std::endl;
    }
    static std::size_t get_objects_count() { return instance_count; }
    private:
    static std::size_t instance_count;
};

std::size_t Plant::instance_count = 0;

int main()
{
    std::cout << "=== Plant Factory Output ===" << std::endl;
    Plant rose("Rose", 25, 30);
    Plant oak("Oak", 200, 365);
    Plant cactus("Cactus", 5, 90);
    Plant sunflower("Sunflower", 80, 45);
    Plant fern("Fern", 15, 120);
    std::cout << std::endl;
    std::cout << "Total plants created: " << Plant::get_objects_count() << std::endl;
    return 0;
}
