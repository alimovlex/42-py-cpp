#ifndef CARD_FACTORY_H
#define CARD_FACTORY_H

#include "../ex0/card.h"

struct CardFactory;

struct CardFactoryVTable {
    struct Card* (*create_creature)(struct CardFactory* self, const char* name);
    struct Card* (*create_spell)(struct CardFactory* self, const char* name);
    struct Card* (*create_artifact)(struct CardFactory* self, const char* name);
    void (*destroy)(struct CardFactory* self);
};

struct CardFactory {
    struct CardFactoryVTable* vptr;
};

#endif
