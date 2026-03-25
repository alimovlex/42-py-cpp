#include "deck.h"
#include <stdlib.h>

struct Deck* deck_new() {
    struct Deck* self = malloc(sizeof(struct Deck));
    if (!self) return NULL;
    self->size = 0;
    self->capacity = 10;
    self->cards = malloc(sizeof(struct Card*) * self->capacity);
    return self;
}

void deck_add_card(struct Deck* self, struct Card* card) {
    if (self->size >= self->capacity) {
        self->capacity *= 2;
        self->cards = realloc(self->cards, sizeof(struct Card*) * self->capacity);
    }
    self->cards[self->size++] = card;
}

struct Card* deck_draw_card(struct Deck* self) {
    if (self->size <= 0) return NULL;
    return self->cards[--self->size];
}

void deck_free(struct Deck* self) {
    if (self) {
        for (int i = 0; i < self->size; i++) {
            self->cards[i]->vptr->destroy(self->cards[i]);
        }
        free(self->cards);
        free(self);
    }
}
