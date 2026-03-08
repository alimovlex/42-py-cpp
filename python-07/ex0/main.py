from .CreatureCard import CreatureCard

if __name__ == "__main__":
    print("=== DataDeck Card Foundation ===\n")
    creature_card = CreatureCard("Fire Dragon", 5, "Legendary", 7, 5)
    print("CreatureCard Info:")
    print(creature_card.get_card_info())
    print()
    mana = 6
    print(f"Playing Fire Dragon with {mana} mana available:")
    print(f"Playable: {creature_card.is_playable(mana)}")
    game_state = {}
    print(f"Play result: {creature_card.play(game_state)}")
    print()

    print(f"{creature_card.get_card_info()["name"]} attacks Goblin Warrior:")
    print(f"Attack result: {creature_card.attack_target("Goblin Warrior")}")
    print()
    mana -= 3
    print(f"Testing insufficient mana ({mana} available)")
    print(f"Playable: {creature_card.is_valid()}")
