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
    int height, days;

    void (*init)(Plant *this, char *name, int height, int age);

    void(*grow)(Plant *this, int cm);
    void(*age)(Plant *this, int duration);
    void(*get_info)(Plant *this);

    void (*deinit)(Plant *this);
};

void Plant_ctor(Plant *this, char *name, int height, int age);
void Plant_dtor(Plant *this);
void Plant_grow(Plant *this, int cm);
void Plant_age(Plant *this, int duration);
void Plant_get_info(Plant *this);
