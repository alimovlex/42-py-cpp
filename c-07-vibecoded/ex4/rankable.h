#ifndef RANKABLE_H
#define RANKABLE_H

struct Rankable;

struct RankableVTable {
    int (*calculate_rating)(struct Rankable* self);
    void (*update_wins)(struct Rankable* self, int wins);
    void (*update_losses)(struct Rankable* self, int losses);
    void (*get_rank_info)(struct Rankable* self);
    void (*destroy)(struct Rankable* self);
};

struct Rankable {
    struct RankableVTable* vptr;
};

#endif
