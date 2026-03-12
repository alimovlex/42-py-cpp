#include <iostream>
#include <string>
#include <cmath>
#include "Plant.hpp"
#include "Flower.hpp"
#include "Tree.hpp"
#include "Vegetable.hpp"

int main(int argc, char** argv)
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
