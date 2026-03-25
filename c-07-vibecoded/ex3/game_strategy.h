#ifndef GAMESTRATEGY_H
#define GAMESTRATEGY_H

#include "../ex0/card.h"

struct GameStrategy;

struct GameStrategyVTable {
    void (*execute_turn)(struct GameStrategy* self);
    const char* (*get_strategy_name)(struct GameStrategy* self);
    void (*destroy)(struct GameStrategy* self);
};

struct GameStrategy {
    struct GameStrategyVTable* vptr;
};

#endif
