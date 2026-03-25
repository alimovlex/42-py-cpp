#ifndef ELITECARD_H
#define ELITECARD_H

#include "card.h"
#include "combatable.h"
#include "magical.h"

struct EliteCard {
    struct Card base;           // Inherits from Card (vptr is at the start)
    struct Combatable combat;   // Secondary interface
    struct Magical magic;       // Secondary interface
    int attack_power;
    int health;
    int mana_pool;
};

// Constructor
struct EliteCard* elite_card_new(const char* name, int cost, const char* rarity, int attack, int health, int mana);
void elite_card_free(struct EliteCard* self);

#endif
