from alchemy import grimoire

if __name__ == "__main__":
    print("=== Circular Curse Breaking ===\n")
    print("Testing ingredient valadation:")
    print(
        f'validate_ingredients("fire air"): {grimoire.validate_ingredients("fire air")}'
    )
    print(
        f'validate_ingredients("dragon scales"): '
        f"{grimoire.validator.validate_ingredients('dragon scales')}"
    )
    print()
    print("Testing spell recording with validation:")
    print(
        f'record_spell("Fireball", "fire air"): '
        f"{grimoire.spellbook.record_spell('Fireball', 'fire air')}"
    )
    print(
        f'record_spell("Dark Magic", "shadow"): '
        f"{grimoire.spellbook.record_spell('Dark Magic', 'shadow')}"
    )
    print()
    print("Testing late import technique:")
    print(
        f'record_spell("Lightning", "air"): '
        f"{grimoire.spellbook.record_spell('Lightning', 'air')}"
    )
    print()
    print("Circular dependency curse avoided using late imports!")
    print("All spells processed safely!")
