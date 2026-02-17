def validate_ingredients(ingredients: str) -> str:
    valid_ingredients = ""
    if ingredients in ("fire", "water", "earth", "air", "fire air"):
        valid_ingredients += ingredients
        return (f"{ingredients} - VALID")
    else:
        return (f"{ingredients} - INVALID")
