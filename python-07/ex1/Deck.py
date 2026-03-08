from ex0.Card import Card
from typing import Dict, List
import random


class Deck:

    def __init__(self):
        self.card_added: List[Dict] = []

    def add_card(self, cards: Card) -> None:
        self.card_added.extend(cards)

    def remove_card(self, card_name: str) -> bool:
        self.card_name = card_name
        for i, card in enumerate(self.card_added):
            if card["name"] == card_name:
                self.card_added.pop(i)
                return True
        return False

    def shuffle(self) -> None:
        random.shuffle(self.card_added)

    def draw_card(self) -> Card:
        print(f"Drew: {self.card_added[0]["name"]} "
              f"({self.card_added[0]["type"]})")
        return {
                "card_played": self.card_added[0]["name"],
                "mana_used": self.card_added[0]["cost"],
                "effect": self.card_added[0]["effect_type"]
                }

    def get_deck_stats(self) -> dict:
        self.list_cost = []
        self.creature = 0
        self.spell = 0
        self.artifact = 0
        for card in self.card_added:
            if "creature" in card["type"]:
                self.creature += 1
            elif "spell" in card["type"]:
                self.spell += 1
            elif "artifact" in card["type"]:
                self.artifact += 1

        for _, cost in enumerate(self.card_added):
            self.list_cost.append(cost["cost"])
        self.avg_card = sum(self.list_cost) / len(self.list_cost)
        return {"total_cards": len(self.card_added),
                "creature": self.creature,
                "spells": self.spell,
                "artifacts": self.artifact,
                "avg_cost": round(self.avg_card, 1)
                }
