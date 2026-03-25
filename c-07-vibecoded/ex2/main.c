#include "elite_card.h"
#include <stdio.h>

int main(int argc, char** argv) {
    printf("=== DataDeck Ability System (C Version) ===\n");
    printf("EliteCard capabilities:\n");
    printf("- Card: ['play', 'get_card_info', 'is_playable']\n");
    printf("- Combatable: ['attack', 'defend', 'get_combat_stats']\n");
    printf("- Magical: ['cast_spell', 'channel_mana', 'get_magic_stats']\n\n");

    // Constructor call
    struct EliteCard* warrior = elite_card_new("Arcane Warrior", 6, "Epic", 5, 10, 4);
    if (!warrior) return 1;

    // Upcasting to interfaces (polymorphism)
    struct Card* card_ptr = (struct Card*)warrior;
    struct Combatable* combat_ptr = &warrior->combat;
    struct Magical* magic_ptr = &warrior->magic;

    printf("Playing Arcane Warrior (Elite Card):\n");
    // Virtual call via vtable
    card_ptr->vptr->play(card_ptr);

    printf("\nCombat phase:\n");
    printf("Attack result: ");
    // Virtual call via vtable
    combat_ptr->vptr->attack(combat_ptr, "Enemy");

    printf("Defense result: ");
    // Virtual call via vtable
    combat_ptr->vptr->defend(combat_ptr, 5);

    printf("\nMagic phase:\n");
    const char* targets[] = {"Enemy1", "Enemy2"};
    printf("Spell cast: ");
    // Virtual call via vtable
    magic_ptr->vptr->cast_spell(magic_ptr, "Fireball", targets, 2);

    printf("Mana channel: ");
    // Virtual call via vtable
    magic_ptr->vptr->channel_mana(magic_ptr, 3);

    printf("\nPolymorphic Destroy:\n");
    // Virtual destructor call
    card_ptr->vptr->destroy(card_ptr);

    printf("Multiple interface implementation successful!\n");

    return 0;
}
