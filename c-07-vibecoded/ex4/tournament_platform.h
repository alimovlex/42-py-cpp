#ifndef TOURNAMENTPLATFORM_H
#define TOURNAMENTPLATFORM_H

#include "tournament_card.h"

struct TournamentPlatform {
    struct TournamentCard** cards;
    int size;
    int capacity;
};

struct TournamentPlatform* tournament_platform_new();
void tournament_platform_register(struct TournamentPlatform* self, struct TournamentCard* card);
void tournament_platform_report(struct TournamentPlatform* self);
void tournament_platform_free(struct TournamentPlatform* self);

#endif
