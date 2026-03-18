//
// Created by robot on 3/12/26.
//
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Plant Plant;

struct Plant
{
    char* name;
    int height, age;

    void (*init)(Plant *this, char *name, int height, int age);
    void (*deinit)(Plant *this);
};

void Plant_ctor(Plant *this, char *name, int height, int age);
void Plant_dtor(Plant *this);