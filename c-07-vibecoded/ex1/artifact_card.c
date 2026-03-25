#include "artifact_card.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void card_play(struct Card* self) {
    struct ArtifactCard* artifact = (struct ArtifactCard*)self;
    printf("{'card_played': '%s', 'mana_used': %d, 'effect': 'Artifact deployed: %s'}\n", 
           artifact->base.name, artifact->base.cost, artifact->effect);
}

static void card_get_info(struct Card* self) {
    struct ArtifactCard* artifact = (struct ArtifactCard*)self;
    printf("{'name': '%s', 'cost': %d, 'rarity': '%s', 'type': 'Artifact', 'durability': %d}\n", 
           artifact->base.name, artifact->base.cost, artifact->base.rarity, artifact->durability);
}

static void card_destroy(struct Card* self) {
    struct ArtifactCard* artifact = (struct ArtifactCard*)self;
    artifact_card_free(artifact);
}

static struct CardVTable artifact_vtable = {
    .play = card_play,
    .get_card_info = card_get_info,
    .destroy = card_destroy
};

struct ArtifactCard* artifact_card_new(const char* name, int cost, const char* rarity, int durability, const char* effect) {
    struct ArtifactCard* self = malloc(sizeof(struct ArtifactCard));
    if (!self) return NULL;

    self->base.vptr = &artifact_vtable;
    self->base.name = strdup(name);
    self->base.cost = cost;
    self->base.rarity = strdup(rarity);
    self->durability = durability;
    self->effect = strdup(effect);

    return self;
}

void artifact_card_free(struct ArtifactCard* self) {
    if (self) {
        free(self->base.name);
        free(self->base.rarity);
        free(self->effect);
        free(self);
    }
}
