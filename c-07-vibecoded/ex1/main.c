#include "deck.h"
#include "../ex0/creature_card.h"
#include "spell_card.h"
#include "artifact_card.h"
#include <stdio.h>

int main() {
    printf("=== DataDeck Deck Builder (C Version) ===\n");
    printf("Building deck with different card types...\n\n");

    struct Deck* deck = deck_new();

    deck_add_card(deck, (struct Card*)creature_card_new("Fire Dragon", 5, "Legendary", 7, 5));
    deck_add_card(deck, (struct Card*)spell_card_new("Lightning Bolt", 3, "Rare", "damage"));
    deck_add_card(deck, (struct Card*)artifact_card_new("Mana Crystal", 2, "Common", 5, "Permanent: +1 mana per turn"));

    printf("Drawing and playing cards:\n\n");

    for (int i = 0; i < 3; i++) {
        struct Card* card = deck_draw_card(deck);
        if (card) {
            printf("Drew: %s\n", card->name);
            card->vptr->play(card);
            card->vptr->destroy(card);
        }
    }

    printf("\nPolymorphism in action: Same interface, different card behaviors!\n");

    // Clear remaining if any (should be empty now)
    deck_free(deck);

    return 0;
}
