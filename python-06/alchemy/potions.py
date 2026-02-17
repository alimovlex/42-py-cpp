from .elements import create_water
from .elements import create_fire
from .elements import create_earth
from .elements import create_air

water = create_water()
fire = create_fire()
earth = create_earth()
air = create_air()


def healing_potion() -> str:
    return (f"Healing potion brewed with {fire} and {water}")


def strength_potion() -> str:
    return (f"trength potion brewed with {earth} and {fire}")


def invisibility_potion() -> str:
    return (f"Invisibility potion brewed with {air} and {water}")


def wisdom_potion() -> str:
    return (f"Wisdom potion brewed with all elements:"
            f"{water, fire, earth, air}")
