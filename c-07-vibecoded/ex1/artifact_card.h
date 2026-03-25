#ifndef ARTIFACTCARD_H
#define ARTIFACTCARD_H

#include "../ex0/card.h"

struct ArtifactCard {
    struct Card base;
    int durability;
    char* effect;
};

struct ArtifactCard* artifact_card_new(const char* name, int cost, const char* rarity, int durability, const char* effect);
void artifact_card_free(struct ArtifactCard* self);

#endif
