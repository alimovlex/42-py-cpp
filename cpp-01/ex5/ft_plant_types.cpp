#include <iostream>
#include <string>
#include <cmath>

class Plant
{
    public:
    std::string name;
    int height;
    int days;

    Plant(std::string name, int height, int days):
    name(name), height(height), days(days) { }
};

class Flower: Plant
{
    public:
    std::string color;

    void bloom()
    {
        std::cout << this->name << " is blooming beautifully!" << std::endl;
    }

    Flower(std::string name, int height, int days, std::string color):
    Plant(name, height, days), color(color)
    {
        //this->color = color;
        std::cout << name << " (Flower): " << height << "cm, " << days << "days, ";
        std::cout << color << " color" << std::endl;
    }
};

class Tree: Plant
{
    public:
    int trunk_diameter;

    void produce_shade()
    {
        std::cout << name << " provides " << (std::pow(trunk_diameter, 2) * M_PI)/ 4 ;
        std::cout << " square meters of shade" << std::endl;
    }

    Tree(std::string name, int height, int days, int trunk_diameter):
    Plant(name, height, days), trunk_diameter(trunk_diameter)
    {
        //this->trunk_diameter = trunk_diameter;
        std::cout << name << " (Tree): " << height << "cm, " << days << "days, ";
        std::cout << trunk_diameter << "cm diameter" << std::endl;
    }
};

class Vegetable: Plant
{
    public:
    std::string harvest_season;
    std::string nutritional_value;

    Vegetable(std::string name, int height, int days,
        std::string harvest_season, std::string nutritional_value):
    Plant(name, height, days), harvest_season(harvest_season), nutritional_value(nutritional_value)
    {
        //this->harvest_season = harvest_season;
        //this->nutritional_value = nutritional_value;
        std::cout << name << " (Vegetable): " << height << "cm, " << days << "days, ";
        std::cout << harvest_season << std::endl;
        std::cout << name << " is rich in " << nutritional_value << std::endl;
    }
};

int main()
{
    std::cout << "=== Garden Plant Types ===" << std::endl;
    Flower rose = Flower("Rose", 25, 30, "red");
    Flower tulip = Flower("Tulip", 50, 90, "yellow");
    rose.bloom();
    tulip.bloom();
    std::cout << std::endl;

    Tree oak = Tree("Oak", 500, 1825, 50);
    oak.produce_shade();
    Tree birch = Tree("birch", 700, 1500, 90);
    birch.produce_shade();
    std::cout << std::endl;
    Vegetable tomato = Vegetable("Tomato", 80, 90, "summer harvest", "vitamin C");
    Vegetable cucumber = Vegetable("Cucumber", 50, 120, "fall harvest", "vitamin D");
    return 0;
}
