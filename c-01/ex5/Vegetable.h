//
// Created by robot on 3/12/26.
//
#pragma once
#include "Plant.h"

typedef struct Vegetable Vegetable;

struct Vegetable
{
    char* harvest_season;
    char* nutritional_value;
    char* name;
    Plant super;
    int height, days;

    void (*init)(Vegetable* this, char* name, int height, int days, char* harvest_season, char* nutritional_value);
    void (*deinit)(Vegetable * this);
};


void Vegetable_ctor(Vegetable* this, char* name, int height, int days, char* harvest_season, char* nutritional_value);
void Vegetable_dtor(Vegetable* this);