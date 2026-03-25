#include "aggressive_strategy.h"
#include <stdio.h>
#include <stdlib.h>

static void execute_turn(struct GameStrategy* self) {
    printf("{'action': 'attack_all', 'priority': 'highest_damage', 'strategy': 'Aggressive'}\n");
}

static const char* get_strategy_name(struct GameStrategy* self) {
    return "Aggressive";
}

static void destroy(struct GameStrategy* self) {
    aggressive_strategy_free((struct AggressiveStrategy*)self);
}

static struct GameStrategyVTable aggressive_vtable = {
    .execute_turn = execute_turn,
    .get_strategy_name = get_strategy_name,
    .destroy = destroy
};

struct AggressiveStrategy* aggressive_strategy_new() {
    struct AggressiveStrategy* self = malloc(sizeof(struct AggressiveStrategy));
    if (!self) return NULL;
    self->base.vptr = &aggressive_vtable;
    return self;
}

void aggressive_strategy_free(struct AggressiveStrategy* self) {
    if (self) {
        free(self);
    }
}
