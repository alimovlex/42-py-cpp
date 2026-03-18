//
// Created by robot on 3/12/26.
//
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Plant Plant;

struct Plant
{
    char* name;
    int height, age;

    void (*init)(Plant *this, char *name, int height, int age);
    void (*deinit)(Plant *this);
    size_t (*get_objects_count)();
};
static int instance_count;
void Plant_ctor(Plant *this, char *name, int height, int age);
void Plant_dtor(Plant* this);
size_t Plant_get_objects_count();
