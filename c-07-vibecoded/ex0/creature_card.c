#include "creature_card.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void card_play(struct Card* self) {
    struct CreatureCard* creature = (struct CreatureCard*)self;
    printf("{'card_played': '%s', 'mana_used': %d, 'effect': 'Creature summoned to battlefield'}\n", 
           creature->base.name, creature->base.cost);
}

static void card_get_info(struct Card* self) {
    struct CreatureCard* creature = (struct CreatureCard*)self;
    printf("{'name': '%s', 'cost': %d, 'rarity': '%s', 'type': 'Creature', 'attack': %d, 'health': %d}\n", 
           creature->base.name, creature->base.cost, creature->base.rarity, creature->attack, creature->health);
}

static void card_destroy(struct Card* self) {
    struct CreatureCard* creature = (struct CreatureCard*)self;
    creature_card_free(creature);
}

static struct CardVTable creature_vtable = {
    .play = card_play,
    .get_card_info = card_get_info,
    .destroy = card_destroy
};

struct CreatureCard* creature_card_new(const char* name, int cost, const char* rarity, int attack, int health) {
    if (attack < 0 || health < 0) {
        fprintf(stderr, "Error: Attack and health must be non-negative.\n");
        return NULL;
    }
    struct CreatureCard* self = malloc(sizeof(struct CreatureCard));
    if (!self) return NULL;

    self->base.vptr = &creature_vtable;
    self->base.name = strdup(name);
    self->base.cost = cost;
    self->base.rarity = strdup(rarity);
    self->attack = attack;
    self->health = health;

    return self;
}

void creature_card_free(struct CreatureCard* self) {
    if (self) {
        free(self->base.name);
        free(self->base.rarity);
        free(self);
    }
}
