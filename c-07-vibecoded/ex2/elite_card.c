#include "elite_card.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper to get EliteCard from interface pointers
static struct EliteCard* get_elite_from_card(struct Card* c) {
    return (struct EliteCard*)c;
}

static struct EliteCard* get_elite_from_combat(struct Combatable* c) {
    // Offset calculation for secondary interface
    return (struct EliteCard*)((char*)c - offsetof(struct EliteCard, combat));
}

static struct EliteCard* get_elite_from_magic(struct Magical* m) {
    // Offset calculation for secondary interface
    return (struct EliteCard*)((char*)m - offsetof(struct EliteCard, magic));
}

// Card Implementation
static void card_play(struct Card* self) {
    struct EliteCard* elite = get_elite_from_card(self);
    printf("{'card_played': '%s', 'mana_used': %d, 'effect': 'Elite card entered the battlefield'}\n", 
           elite->base.name, elite->base.cost);
}

static void card_get_info(struct Card* self) {
    struct EliteCard* elite = get_elite_from_card(self);
    printf("{'name': '%s', 'cost': %d, 'rarity': '%s'}\n", 
           elite->base.name, elite->base.cost, elite->base.rarity);
}

static void card_destroy(struct Card* self) {
    struct EliteCard* elite = get_elite_from_card(self);
    elite_card_free(elite);
}

// Combatable Implementation
static void combat_attack(struct Combatable* self, const char* target) {
    struct EliteCard* elite = get_elite_from_combat(self);
    printf("{'attacker': '%s', 'target': '%s', 'damage': %d, 'combat_type': 'melee'}\n",
           elite->base.name, target, elite->attack_power);
}

static void combat_defend(struct Combatable* self, int incoming_damage) {
    struct EliteCard* elite = get_elite_from_combat(self);
    const int blocked = 3;
    int taken = incoming_damage - blocked;
    if (taken < 0) {
        taken = 0;
    }
    elite->health -= taken;
    
    if (elite->health > 0) {
        elite->health = 1; // Following the C++ logic: if (health > 0) health = 1; else health = 0;
    } else {
        elite->health = 0;
    }

    printf("{'defender': '%s', 'damage_taken': %d, 'damage_blocked': %d, 'still_alive': %d}\n",
           elite->base.name, taken, blocked, elite->health);
}

static void combat_get_stats(struct Combatable* self) {
    struct EliteCard* elite = get_elite_from_combat(self);
    printf("{'attack': %d, 'health': %d}\n", elite->attack_power, elite->health);
}

// Magical Implementation
static void magic_cast_spell(struct Magical* self, const char* spell_name, const char** targets, int target_count) {
    struct EliteCard* elite = get_elite_from_magic(self);
    int mana_cost = 4;
    elite->mana_pool -= mana_cost;
    printf("{'caster': '%s', 'spell': '%s', 'targets_count': %d, 'mana_used': %d}\n",
           elite->base.name, spell_name, target_count, mana_cost);
}

static void magic_channel_mana(struct Magical* self, int amount) {
    struct EliteCard* elite = get_elite_from_magic(self);
    elite->mana_pool += amount;
    printf("{'channeled': %d, 'total_mana': %d}\n", amount, elite->mana_pool);
}

static void magic_get_stats(struct Magical* self) {
    struct EliteCard* elite = get_elite_from_magic(self);
    printf("{'mana_pool': %d}\n", elite->mana_pool);
}

// VTables (defined as static for the translation unit)
static struct CardVTable elite_card_vtable = {
    .play = card_play,
    .get_card_info = card_get_info,
    .destroy = card_destroy
};

static struct CombatableVTable elite_combat_vtable = {
    .attack = combat_attack,
    .defend = combat_defend,
    .get_combat_stats = combat_get_stats
};

static struct MagicalVTable elite_magic_vtable = {
    .cast_spell = magic_cast_spell,
    .channel_mana = magic_channel_mana,
    .get_magic_stats = magic_get_stats
};

struct EliteCard* elite_card_new(const char* name, int cost, const char* rarity, int attack, int health, int mana) {
    struct EliteCard* self = malloc(sizeof(struct EliteCard));
    if (!self) return NULL;

    // Initialize Card part
    self->base.vptr = &elite_card_vtable;
    self->base.name = strdup(name);
    self->base.cost = cost;
    self->base.rarity = strdup(rarity);

    // Initialize Combatable part
    self->combat.vptr = &elite_combat_vtable;

    // Initialize Magical part
    self->magic.vptr = &elite_magic_vtable;

    // Initialize EliteCard specific fields
    self->attack_power = attack;
    self->health = health;
    self->mana_pool = mana;

    return self;
}

void elite_card_free(struct EliteCard* self) {
    if (self) {
        free(self->base.name);
        free(self->base.rarity);
        free(self);
    }
}
