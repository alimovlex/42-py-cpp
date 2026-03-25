#ifndef CARD_H
#define CARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Card;

struct CardVTable {
    void (*play)(struct Card* self);
    void (*get_card_info)(struct Card* self);
    void (*destroy)(struct Card* self);
};

struct Card {
    struct CardVTable* vptr;
    char* name;
    int cost;
    char* rarity;
};

#endif
