#include "tournament_card.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cast helpers
static struct TournamentCard* get_tourney_from_card(struct Card* c) {
    return (struct TournamentCard*)c;
}

static struct TournamentCard* get_tourney_from_combat(struct Combatable* c) {
    return (struct TournamentCard*)((char*)c - offsetof(struct TournamentCard, combat));
}

static struct TournamentCard* get_tourney_from_rank(struct Rankable* r) {
    return (struct TournamentCard*)((char*)r - offsetof(struct TournamentCard, rank));
}

// Card impl
static void card_play(struct Card* self) {
    struct TournamentCard* tc = get_tourney_from_card(self);
    printf("{'card_played': '%s', 'mana_used': %d, 'effect': 'Tournament card entered'}\n", tc->base.name, tc->base.cost);
}

static void card_get_info(struct Card* self) {
    struct TournamentCard* tc = get_tourney_from_card(self);
    printf("{'name': '%s', 'id': '%s'}\n", tc->base.name, tc->card_id);
}

static void card_destroy(struct Card* self) {
    tournament_card_free(get_tourney_from_card(self));
}

// Combat impl
static void combat_attack(struct Combatable* self, const char* target) {
    struct TournamentCard* tc = get_tourney_from_combat(self);
    printf("{'attacker': '%s', 'target': '%s', 'damage': %d}\n", tc->base.name, target, tc->attack_power);
}

static void combat_defend(struct Combatable* self, int incoming) {
    struct TournamentCard* tc = get_tourney_from_combat(self);
    printf("{'defender': '%s', 'taken': %d}\n", tc->base.name, incoming);
}

static void combat_get_stats(struct Combatable* self) {
    struct TournamentCard* tc = get_tourney_from_combat(self);
    printf("{'attack': %d, 'health': %d}\n", tc->attack_power, tc->health);
}

// Rank impl
static int rank_calc_rating(struct Rankable* self) {
    struct TournamentCard* tc = get_tourney_from_rank(self);
    return tc->rating + (tc->wins * 20) - (tc->losses * 10);
}

static void rank_update_wins(struct Rankable* self, int w) {
    struct TournamentCard* tc = get_tourney_from_rank(self);
    tc->wins += w;
}

static void rank_update_losses(struct Rankable* self, int l) {
    struct TournamentCard* tc = get_tourney_from_rank(self);
    tc->losses += l;
}

static void rank_get_info(struct Rankable* self) {
    struct TournamentCard* tc = get_tourney_from_rank(self);
    printf("{'rating': %d, 'wins': %d, 'losses': %d}\n", tc->rating, tc->wins, tc->losses);
}

// VTables
static struct CardVTable tourney_card_vtable = {card_play, card_get_info, card_destroy};
static struct CombatableVTable tourney_combat_vtable = {combat_attack, combat_defend, combat_get_stats};
static struct RankableVTable tourney_rank_vtable = {rank_calc_rating, rank_update_wins, rank_update_losses, rank_get_info, NULL};

struct TournamentCard* tournament_card_new(const char* name, int cost, const char* rarity, int attack, int health, const char* id) {
    struct TournamentCard* self = malloc(sizeof(struct TournamentCard));
    if (!self) return NULL;
    
    self->base.vptr = &tourney_card_vtable;
    self->base.name = strdup(name);
    self->base.cost = cost;
    self->base.rarity = strdup(rarity);
    
    self->combat.vptr = &tourney_combat_vtable;
    self->rank.vptr = &tourney_rank_vtable;
    
    self->attack_power = attack;
    self->health = health;
    self->wins = 0;
    self->losses = 0;
    self->rating = 1200;
    self->card_id = strdup(id);
    
    return self;
}

void tournament_card_free(struct TournamentCard* self) {
    if (self) {
        free(self->base.name);
        free(self->base.rarity);
        free(self->card_id);
        free(self);
    }
}
