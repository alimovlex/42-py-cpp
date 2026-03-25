#ifndef DECK_H
#define DECK_H

#include "../ex0/card.h"

struct Deck {
    struct Card** cards;
    int size;
    int capacity;
};

struct Deck* deck_new();
void deck_add_card(struct Deck* self, struct Card* card);
struct Card* deck_draw_card(struct Deck* self);
void deck_free(struct Deck* self);

#endif
