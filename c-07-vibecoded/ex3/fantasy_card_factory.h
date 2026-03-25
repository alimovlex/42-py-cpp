#ifndef FANTASYCARD_FACTORY_H
#define FANTASYCARD_FACTORY_H

#include "card_factory.h"

struct FantasyCardFactory {
    struct CardFactory base;
};

struct FantasyCardFactory* fantasy_card_factory_new();
void fantasy_card_factory_free(struct FantasyCardFactory* self);

#endif
