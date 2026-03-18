#include "Plant.h"
#include "Flower.h"
#include "Tree.h"
#include "Vegetable.h"

int main(int argc, char** argv)
{
    printf("=== Garden Plant Types ===\n");
    Flower rose = {.init = Flower_ctor, .deinit = Flower_dtor, .bloom = Flower_bloom };
    Flower tulip = {.init = Flower_ctor, .deinit = Flower_dtor, .bloom = Flower_bloom};
    rose.init(&rose,"Rose", 25, 30, "red");
    tulip.init(&tulip,"Tulip", 50, 90, "yellow");
    rose.bloom(&rose);
    tulip.bloom(&tulip);
    rose.deinit(&rose);
    tulip.deinit(&tulip);

    Tree oak = {.init = Tree_ctor, .deinit = Tree_dtor, .produce_shade = Tree_produce_shade };
    Tree birch = {.init = Tree_ctor, .deinit = Tree_dtor, .produce_shade = Tree_produce_shade };
    oak.init(&oak, "Oak", 500, 1825, 50);
    oak.produce_shade(&oak);
    birch.init(&birch, "birch", 700, 1500, 90);
    birch.produce_shade(&birch);
    oak.deinit(&oak);
    birch.deinit(&birch);

    Vegetable tomato = {.init = Vegetable_ctor, .deinit = Vegetable_dtor };
    Vegetable cucumber = {.init = Vegetable_ctor, .deinit = Vegetable_dtor };
    tomato.init(&tomato,"Tomato", 80, 90, "summer harvest", "vitamin C");
    cucumber.init(&cucumber,"Cucumber", 50, 120, "fall harvest", "vitamin D");
    tomato.deinit(&tomato);
    cucumber.deinit(&cucumber);
    return 0;
}
