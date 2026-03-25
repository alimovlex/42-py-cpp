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

// Static-like functions (no prefix, but take self)
static inline int is_playable(struct Card* self, int available_mana) {
    if (available_mana >= self->cost) {
        return 1;
    }
    return 0;
}

static inline const char* getName(struct Card* self) {
    return self->name;
}

static inline int getCost(struct Card* self) {
    return self->cost;
}

#endif
