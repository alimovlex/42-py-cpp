def spell_combiner(spell1: callable, spell2: callable) -> callable:
    """ • Return a new function that calls both spells
            with the same arguments
        • The combined spell should return a tuple of both results
        • Example: combined = spell_combiner(fireball, heal)"""
    def combined_spell(*args, **kwargs):
        result1 = spell1(*args, **kwargs)
        result2 = spell2(*args, **kwargs)
        return (result1, result2)
    return combined_spell


def power_amplifier(base_spell: callable, multiplier: int) -> callable:
    """ • Return a new function that multiplies
            the base spell’s result by multiplier
        • Assume base spell returns a number (damage, healing, etc.)
        • Example: mega_fireball = power_amplifier(fireball, 3)
        """
    def spell_multiply(*args, **kwargs):
        base_result = base_spell(*args, **kwargs)
        return base_result * multiplier
    return spell_multiply


def conditional_caster(condition: callable, spell: callable) -> callable:
    """ • Return a function that only casts the spell if condition returns True
        • If condition fails, return "Spell fizzled"
        • Both condition and spell receive the same arguments
        """
    def condi_test(*args, **kwargs):
        condi = condition(*args, **kwargs)
        condi2 = spell(*args, **kwargs)
        if condi:
            return condi2
        return "Spell fizzled"
    return condi_test


def spell_sequence(spells: list[callable]) -> callable:
    """ • Return a function that casts all spells in order
        • Each spell receives the same arguments
        • Return a list of all spell results
        """
    def sequences(*args, **kwargs):
        casting = list(map(lambda spell: spell(*args, **kwargs), spells))
        return casting
    return sequences


if __name__ == "__main__":
    def fireball(name: str) -> str:
        return f"Fireball hits {name}"

    def heal(name: str) -> str:
        return f"heals {name}"

    combine_spells = spell_combiner(fireball, heal)
    print(*combine_spells("Dragon"), sep=", ")
    print()

    def basic_damage(value):
        return value

    amplified_spell = power_amplifier(basic_damage, 3)

    original = 10
    amplified = amplified_spell(original)

    print(f"Original: {original}, Amplified: {amplified}")

    # def heal(amount):
    #     return amount

    # super_heal = power_amplifier(heal, 2)
    # print(super_heal(100))  # Output: 200
    # def has_mana(mana):
    #     return mana >= 50

    # def lightning_bolt(mana):
    #     return "⚡ Lightning strikes!"

    # safe_lightning = conditional_caster(has_mana, lightning_bolt)

    # print(safe_lightning(100))  # Output: ⚡ Lightning strikes!
    # print(safe_lightning(30))   # Output: Spell fizzled

    # def fireball(damage):
    #     return f"Fireball deals {damage} damage, "

    # def heal(amount):
    #     return f"Heal restores {amount} HP, "

    # def shield(defense):
    #     return f"Shield blocks {defense} damage"

    # cast_all = spell_sequence([fireball, heal, shield])
    # results = cast_all(50)
    # print(" ".join(results))
