# flake8: noqa
from ex2.EliteCard import EliteCard

if __name__ == "__main__":

    cards = [
                {"name": "Fireball", "cost": 4, "rarity": "Uncommon", "effect_type": "damage"},
                {"caster": "Arcane Warrior", "cost": 8, "rarity": "Uncommon", "effect_type": "damage"}
            ]

    targett = ['Enemy1', 'Enemy2']

    print("\n=== DataDeck Ability System ===\n")
    elit_card = EliteCard("Arcane Warrior", 4, "")
    print("EliteCard capabilities:")
    print("- Card: ['play', 'get_card_info', 'is_playable']")
    print("- Combatable: ['attack', 'defend', 'get_combat_stats']")
    print("- Magical: ['cast_spell', 'channel_mana', 'get_magic_stats']")
    print()
    print("Playing Arcane Warrior (Elite Card):")
    print()
    print("Combat phase:")
    print(f"Attack result: {elit_card.attack("Enemy")}")
    print(f"Defense result: {elit_card.defend(5)}")
    print()
    print("Magic phase:")
    print(f"Spell cast: {elit_card.cast_spell("Fireball", targett)}")
    print(f"Mana channel: {elit_card.channel_mana(3)}")
    print()
    print("Multiple interface implementation successful")