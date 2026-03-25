#ifndef CREATURECARD_H
#define CREATURECARD_H

#include "card.h"

struct CreatureCard {
    struct Card base;
    int attack;
    int health;
};

struct CreatureCard* creature_card_new(const char* name, int cost, const char* rarity, int attack, int health);
void creature_card_free(struct CreatureCard* self);

#endif
