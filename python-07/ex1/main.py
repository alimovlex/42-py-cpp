#!/usr/bin/env python3
# flake8: noqa
"""
DataDeck Deck Builder System Demonstration
Showcases polymorphism with different card types using the same interface
"""
from ex1.Deck import Deck


if __name__ == "__main__":
    
    cards = [ 
                {"type": "spell", "name": "Lightning Bolt", "cost": 3, "rarity": "Common", "effect_type": "damage"},
                {"type": "artifact", "name": "Mana Crystal", "cost": 2, "rarity": "Common", "durability": 5, "effect_type": "Permanent: +1 mana per turn"},
                {"type": "creature", "name": "Fire Dragon", "cost": 5, "rarity": "Legendary", "attack": 7, "health": 5, "effect_type": "Creature summoned to battlefield"}
            ]

    print("=== DataDeck Deck Builder ===\n")
    print("Building deck with different card types...")
    deck = Deck()
    deck.add_card(cards)
    print(f"Deck stats: {deck.get_deck_stats()}")
    print()
    print("Drawing and playing cards:")
    print()
    print(f"Play result: {deck.draw_card()}")
    deck.remove_card("Lightning Bolt")
    print()
    print(f"Play result: {deck.draw_card()}")
    deck.remove_card("Mana Crystal")
    print()
    print(f"Play result: {deck.draw_card()}")
    print()
    # print(f"Deck stats: {deck.get_deck_stats()}")
    print("Polymorphism in action: Same interface, different card behaviors!")









































# def main():
#     """Demonstrate the deck builder system"""
#     print("=== DataDeck Deck Builder ===\n")
#     print("Building deck with different card types...")
    
#     # Create a new deck
#     deck = Deck()
    
#     # Add different types of cards
#     # Creature card (only uses name, cost, rarity)
#     fire_dragon = CreatureCard(
#         name="Fire Dragon",
#         cost=5,
#         rarity="Rare"
#     )
#     deck.add_card(fire_dragon)
    
#     # Spell card
#     lightning_bolt = SpellCard(
#         name="Lightning Bolt",
#         cost=3,
#         rarity="Common",
#         effect_type="damage"
#     )
#     deck.add_card(lightning_bolt)
    
#     # Artifact card
#     mana_crystal = ArtifactCard(
#         name="Mana Crystal",
#         cost=2,
#         rarity="Uncommon",
#         durability=5,
#         effect="+1 mana per turn"
#     )
#     deck.add_card(mana_crystal)
    
#     # Show deck statistics
#     stats = deck.get_deck_stats()
#     print(f"Deck stats: {stats}")
    
#     # Shuffle the deck
#     deck.shuffle()
    
#     # Draw and play cards
#     print("\nDrawing and playing cards:")
#     print()
#     game_state = {'mana_available': 10, 'battlefield': []}
    
#     while len(deck) > 0:
#         card = deck.draw_card()
#         if card:
#             print(f"Drew: {card}")
#             result = card.play(game_state)
#             print(f"Play result: {result}")
    
#     print("\nPolymorphism in action: Same interface, different card behaviors!")


# if __name__ == "__main__":
#     main()
