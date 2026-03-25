#include "spell_card.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void card_play(struct Card* self) {
    struct SpellCard* spell = (struct SpellCard*)self;
    printf("{'card_played': '%s', 'mana_used': %d, 'effect': 'Spell cast: %s'}\n", 
           spell->base.name, spell->base.cost, spell->effect_type);
}

static void card_get_info(struct Card* self) {
    struct SpellCard* spell = (struct SpellCard*)self;
    printf("{'name': '%s', 'cost': %d, 'rarity': '%s', 'type': 'Spell', 'effect_type': '%s'}\n", 
           spell->base.name, spell->base.cost, spell->base.rarity, spell->effect_type);
}

static void card_destroy(struct Card* self) {
    struct SpellCard* spell = (struct SpellCard*)self;
    spell_card_free(spell);
}

static struct CardVTable spell_vtable = {
    .play = card_play,
    .get_card_info = card_get_info,
    .destroy = card_destroy
};

struct SpellCard* spell_card_new(const char* name, int cost, const char* rarity, const char* effect_type) {
    struct SpellCard* self = malloc(sizeof(struct SpellCard));
    if (!self) return NULL;

    self->base.vptr = &spell_vtable;
    self->base.name = strdup(name);
    self->base.cost = cost;
    self->base.rarity = strdup(rarity);
    self->effect_type = strdup(effect_type);

    return self;
}

void spell_card_free(struct SpellCard* self) {
    if (self) {
        free(self->base.name);
        free(self->base.rarity);
        free(self->effect_type);
        free(self);
    }
}
