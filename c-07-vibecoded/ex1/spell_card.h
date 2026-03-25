#ifndef SPELLCARD_H
#define SPELLCARD_H

#include "../ex0/card.h"

struct SpellCard {
    struct Card base;
    char* effect_type;
};

struct SpellCard* spell_card_new(const char* name, int cost, const char* rarity, const char* effect_type);
void spell_card_free(struct SpellCard* self);

#endif
