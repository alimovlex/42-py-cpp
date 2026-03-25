#ifndef COMBATABLE_H
#define COMBATABLE_H

struct Combatable;

struct CombatableVTable {
    void (*attack)(struct Combatable* self, const char* target);
    void (*defend)(struct Combatable* self, int incoming_damage);
    void (*get_combat_stats)(struct Combatable* self);
};

struct Combatable {
    struct CombatableVTable* vptr;
};

#endif
