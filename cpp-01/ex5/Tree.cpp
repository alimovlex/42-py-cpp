//
// Created by robot on 3/12/26.
//

#include "Tree.hpp"

Tree::Tree(std::string name, int height, int days, int trunk_diameter):
        Plant(name, height, days), trunk_diameter(trunk_diameter)
{
    //this->trunk_diameter = trunk_diameter;
    std::cout << name << " (Tree): " << height << "cm, " << days << "days, ";
    std::cout << trunk_diameter << "cm diameter" << std::endl;
}

void Tree::produce_shade()
{
    std::cout << name << " provides " << (std::pow(trunk_diameter, 2) * M_PI)/ 4 ;
    std::cout << " square meters of shade" << std::endl;
}
