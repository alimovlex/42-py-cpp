#include "tournament_platform.h"
#include <stdlib.h>
#include <stdio.h>

struct TournamentPlatform* tournament_platform_new() {
    struct TournamentPlatform* self = malloc(sizeof(struct TournamentPlatform));
    if (!self) return NULL;
    self->size = 0;
    self->capacity = 10;
    self->cards = malloc(sizeof(struct TournamentCard*) * self->capacity);
    return self;
}

void tournament_platform_register(struct TournamentPlatform* self, struct TournamentCard* card) {
    if (self->size >= self->capacity) {
        self->capacity *= 2;
        self->cards = realloc(self->cards, sizeof(struct TournamentCard*) * self->capacity);
    }
    self->cards[self->size++] = card;
}

void tournament_platform_report(struct TournamentPlatform* self) {
    printf("Tournament Leaderboard:\n");
    for (int i = 0; i < self->size; i++) {
        struct TournamentCard* tc = self->cards[i];
        int rating = tc->rank.vptr->calculate_rating(&tc->rank);
        printf("%d. %s - Rating: %d (Wins: %d, Losses: %d)\n", i+1, tc->base.name, rating, tc->wins, tc->losses);
    }
}

void tournament_platform_free(struct TournamentPlatform* self) {
    if (self) {
        for (int i = 0; i < self->size; i++) {
            struct Card* c = (struct Card*)self->cards[i];
            c->vptr->destroy(c);
        }
        free(self->cards);
        free(self);
    }
}
