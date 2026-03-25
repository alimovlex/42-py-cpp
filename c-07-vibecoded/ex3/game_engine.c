#include "game_engine.h"
#include <stdlib.h>
#include <stdio.h>

struct GameEngine* game_engine_new() {
    struct GameEngine* self = malloc(sizeof(struct GameEngine));
    if (!self) return NULL;
    self->factory = NULL;
    self->strategy = NULL;
    return self;
}

void game_engine_configure(struct GameEngine* self, struct CardFactory* f, struct GameStrategy* s) {
    if (self->factory) self->factory->vptr->destroy(self->factory);
    if (self->strategy) self->strategy->vptr->destroy(self->strategy);
    self->factory = f;
    self->strategy = s;
}

void game_engine_simulate_turn(struct GameEngine* self) {
    if (!self->strategy) return;
    printf("Simulating turn with strategy: %s\n", self->strategy->vptr->get_strategy_name(self->strategy));
    self->strategy->vptr->execute_turn(self->strategy);
}

void game_engine_free(struct GameEngine* self) {
    if (self) {
        if (self->factory) self->factory->vptr->destroy(self->factory);
        if (self->strategy) self->strategy->vptr->destroy(self->strategy);
        free(self);
    }
}
