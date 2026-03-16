//
// Created by robot on 3/12/26.
//
#pragma once
#include "Plant.h"

typedef struct
{
    Plant super;
    char* color;
    char* name;
    int height, days;
}Flower;

void Flower_bloom(Flower* this);
void Flower_ctor(Flower* this, char* name, int height, int days, char* color);
void Flower_dtor(Flower* this);