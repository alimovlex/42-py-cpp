//
// Created by robot on 3/12/26.
//
#pragma once
#include "Plant.h"

typedef struct Flower Flower;

struct Flower
{
    Plant super;
    char* color;
    char* name;
    int height, days;

    void (*init)(Flower* this, char* name, int height, int days, char* color);
    void (*deinit)(Flower* this);
    void (*bloom)(Flower* this);
};

void Flower_bloom(Flower* this);
void Flower_ctor(Flower* this, char* name, int height, int days, char* color);
void Flower_dtor(Flower* this);