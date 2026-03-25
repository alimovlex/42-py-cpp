#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "card_factory.h"
#include "game_strategy.h"

struct GameEngine {
    struct CardFactory* factory;
    struct GameStrategy* strategy;
};

struct GameEngine* game_engine_new();
void game_engine_configure(struct GameEngine* self, struct CardFactory* f, struct GameStrategy* s);
void game_engine_simulate_turn(struct GameEngine* self);
void game_engine_free(struct GameEngine* self);

#endif
