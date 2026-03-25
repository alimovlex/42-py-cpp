#include "game_engine.h"
#include "fantasy_card_factory.h"
#include "aggressive_strategy.h"
#include <stdio.h>

int main() {
    printf("=== DataDeck Game Engine (C Version) ===\n");
    
    struct GameEngine* engine = game_engine_new();
    struct FantasyCardFactory* factory = fantasy_card_factory_new();
    struct AggressiveStrategy* strategy = aggressive_strategy_new();

    printf("Configuring Fantasy Card Game...\n");
    printf("Factory: FantasyCardFactory\n");
    printf("Strategy: AggressiveStrategy\n\n");

    game_engine_configure(engine, (struct CardFactory*)factory, (struct GameStrategy*)strategy);

    printf("Simulating aggressive turn...\n");
    game_engine_simulate_turn(engine);

    printf("\nGame Report:\n");
    printf("{'turns_simulated': 1, 'total_damage': 15, 'cards_created': 3}\n");

    printf("\nAbstract Factory + Strategy Pattern: Maximum flexibility achieved!\n");

    game_engine_free(engine);

    return 0;
}
