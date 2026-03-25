#include "creature_card.h"
#include <stdio.h>

int main() {
    printf("=== DataDeck Card Foundation (C Version) ===\n");
    printf("Testing Abstract Base Class Design:\n\n");

    struct CreatureCard* dragon = creature_card_new("Fire Dragon", 5, "Legendary", 7, 5);
    if (!dragon) return 1;

    struct Card* card_ptr = (struct Card*)dragon;

    printf("CreatureCard Info:\n");
    card_ptr->vptr->get_card_info(card_ptr);

    printf("\nPlaying Fire Dragon with 6 mana available:\n");
    int mana = 6;
    printf("Playable: ");
    if (is_playable(card_ptr, mana)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    printf("Play result: ");
    card_ptr->vptr->play(card_ptr);

    printf("\nFire Dragon attacks Goblin Warrior:\n");
    printf("Attack result: {'attacker': '%s', 'target': 'Goblin Warrior', 'damage_dealt': %d, 'combat_resolved': 1}\n",
           card_ptr->name, dragon->attack);

    printf("\nTesting insufficient mana (3 available):\n");
    mana = 3;
    printf("Playable: ");
    if (is_playable(card_ptr, mana)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    printf("\nAbstract pattern successfully demonstrated!\n");
    
    card_ptr->vptr->destroy(card_ptr);

    return 0;
}
