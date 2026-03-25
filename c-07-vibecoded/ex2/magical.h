#ifndef MAGICAL_H
#define MAGICAL_H

struct Magical;

struct MagicalVTable {
    void (*cast_spell)(struct Magical* self, const char* spell_name, const char** targets, int target_count);
    void (*channel_mana)(struct Magical* self, int amount);
    void (*get_magic_stats)(struct Magical* self);
};

struct Magical {
    struct MagicalVTable* vptr;
};

#endif
