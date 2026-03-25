#ifndef TOURNAMENTCARD_H
#define TOURNAMENTCARD_H

#include "../ex0/card.h"
#include "../ex2/combatable.h"
#include "rankable.h"

struct TournamentCard {
    struct Card base;           // First interface (vptr at offset 0)
    struct Combatable combat;   // Second interface
    struct Rankable rank;       // Third interface
    int attack_power;
    int health;
    int wins;
    int losses;
    int rating;
    char* card_id;
};

struct TournamentCard* tournament_card_new(const char* name, int cost, const char* rarity, int attack, int health, const char* id);
void tournament_card_free(struct TournamentCard* self);

#endif
