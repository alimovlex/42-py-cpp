#include "Plant.h"
#include "Flower.h"
#include "Tree.h"
#include "Vegetable.h"

int main(int argc, char** argv)
{
    printf("=== Garden Plant Types ===\n");
    Flower rose, tulip;
    Flower_ctor(&rose,"Rose", 25, 30, "red");
    Flower_ctor(&tulip,"Tulip", 50, 90, "yellow");
    Flower_bloom(&rose);
    Flower_bloom(&tulip);
    Flower_dtor(&rose);
    Flower_dtor(&tulip);

    Tree oak, birch;
    Tree_ctor(&oak, "Oak", 500, 1825, 50);
    Tree_produce_shade(&oak);
    Tree_ctor(&birch, "birch", 700, 1500, 90);
    Tree_produce_shade(&birch);
    Tree_dtor(&oak);
    Tree_dtor(&birch);

    Vegetable tomato, cucumber;
    Vegetable_ctor(&tomato,"Tomato", 80, 90, "summer harvest", "vitamin C");
    Vegetable_ctor(&cucumber,"Cucumber", 50, 120, "fall harvest", "vitamin D");
    Vegetable_dtor(&tomato);
    Vegetable_dtor(&cucumber);
    return 0;
}
