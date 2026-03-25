#include "tournament_platform.h"
#include <stdio.h>

int main() {
    printf("=== DataDeck Tournament Platform (C Version) ===\n");
    printf("Registering Tournament Cards...\n\n");

    struct TournamentPlatform* platform = tournament_platform_new();
    
    struct TournamentCard* dragon = tournament_card_new("Fire Dragon", 5, "Legendary", 7, 5, "dragon_001");
    struct TournamentCard* wizard = tournament_card_new("Ice Wizard", 4, "Rare", 3, 4, "wizard_001");

    tournament_platform_register(platform, dragon);
    tournament_platform_register(platform, wizard);

    printf("Fire Dragon (ID: dragon_001):\n");
    printf("- Rating: %d\n", dragon->rank.vptr->calculate_rating(&dragon->rank));

    printf("\nSimulating match: Dragon wins!\n");
    dragon->rank.vptr->update_wins(&dragon->rank, 1);
    wizard->rank.vptr->update_losses(&wizard->rank, 1);

    tournament_platform_report(platform);

    printf("\n=== Tournament Platform Successfully Deployed! ===\n");
    
    tournament_platform_free(platform);

    return 0;
}
