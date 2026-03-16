//
// Created by robot on 3/12/26.
//
#pragma once
#include "Plant.h"

typedef struct
{
    Plant super;
    char* name;
    int trunk_diameter, height, days;
}Tree;

void Tree_produce_shade(Tree* this);
void Tree_ctor(Tree* this ,char* name, int height, int days, int trunk_diameter);
void Tree_dtor(Tree* this);