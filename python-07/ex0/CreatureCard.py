# flake8: noqa
from ex0.Card import Card


class CreatureCard(Card):
    def __init__(self, name: str, cost: int, rarity: str, attack: int, health: int):
        super().__init__(name, cost, rarity)
        self.attack = attack
        self.health = health

    def play(self, game_state: dict) -> dict:
        self.game_state = game_state
        game_state = {
                      "card_played": self.name,
                      "mana_used": self.cost,
                      "effect": "Creature summoned to battlefield"
                      }
        return game_state

    def get_card_info(self) -> dict:

        return {
                    "name": self.name,
                    "cost": self.cost,
                    "rarity": self.rarity,
                    "type": "Creature",
                    "attack": self.attack,
                    "health": self.health
                }

    def is_playable(self, available_mana: int) -> bool:
        self.available_mana = available_mana
        if available_mana >= self.cost:
            return True
        return False

    def attack_target(self, target) -> dict:
        self.target = target
        return {"attacker": self.name,
                "target": target,
                "combat_resolved": True
                }

    def is_valid(self) -> bool:
        self.available_mana -= self.cost
        if self.available_mana < self.cost:
            return self.is_playable(self.available_mana)
        if self.attack and self.health < 0:
            return False
