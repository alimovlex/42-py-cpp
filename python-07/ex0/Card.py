from abc import ABC, abstractmethod


class Card(ABC):
    def __init__(self, name: str, cost: int, rarity: str):
        self.name = name
        self.cost = cost
        self.rarity = rarity

    @abstractmethod
    def play(self, game_state: dict) -> dict:
        pass

    def get_card_info(self) -> dict:
        return {
                    "name": self.name,
                    "cost": self.cost,
                    "rarity": self.rarity,
                    "type": "Creature",
                }

    def is_playable(self, available_mana: int) -> bool:
        self.available_mana = available_mana
        if available_mana >= self.cost:
            return True
        return False
