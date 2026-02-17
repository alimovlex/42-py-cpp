from .validator import validate_ingredients


def record_spell(spell_name: str, ingredients: str) -> str:
    if spell_name == "Dark Magic":
        return (f"Spell rejected: {spell_name} ({ingredients}) - INVALID")
    if validate_ingredients(ingredients):
        compare = set(spell_name.lower()) & set(ingredients.lower())
        if bool(compare):
            return (f"Spell recorded: {spell_name} ({ingredients}) - VALID")
        else:
            return (f"Spell rejected: {spell_name} ({ingredients}) - INVALID")
