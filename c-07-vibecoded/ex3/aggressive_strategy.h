#ifndef AGGRESSIVESTRATEGY_H
#define AGGRESSIVESTRATEGY_H

#include "game_strategy.h"

struct AggressiveStrategy {
    struct GameStrategy base;
};

struct AggressiveStrategy* aggressive_strategy_new();
void aggressive_strategy_free(struct AggressiveStrategy* self);

#endif
