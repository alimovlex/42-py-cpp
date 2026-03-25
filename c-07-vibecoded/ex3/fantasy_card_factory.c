#include "fantasy_card_factory.h"
#include "../ex0/creature_card.h"
#include "../ex1/spell_card.h"
#include "../ex1/artifact_card.h"
#include <stdlib.h>

static struct Card* create_creature(struct CardFactory* self, const char* name) {
    return (struct Card*)creature_card_new(name, 5, "Rare", 5, 5);
}

static struct Card* create_spell(struct CardFactory* self, const char* name) {
    return (struct Card*)spell_card_new(name, 3, "Common", "damage");
}

static struct Card* create_artifact(struct CardFactory* self, const char* name) {
    return (struct Card*)artifact_card_new(name, 2, "Epic", 3, "Mana boost");
}

static void destroy(struct CardFactory* self) {
    fantasy_card_factory_free((struct FantasyCardFactory*)self);
}

static struct CardFactoryVTable fantasy_vtable = {
    .create_creature = create_creature,
    .create_spell = create_spell,
    .create_artifact = create_artifact,
    .destroy = destroy
};

struct FantasyCardFactory* fantasy_card_factory_new() {
    struct FantasyCardFactory* self = malloc(sizeof(struct FantasyCardFactory));
    if (!self) return NULL;
    self->base.vptr = &fantasy_vtable;
    return self;
}

void fantasy_card_factory_free(struct FantasyCardFactory* self) {
    if (self) {
        free(self);
    }
}
