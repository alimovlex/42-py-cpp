from ex0.Card import Card
from .Combatable import Combatable
from .Magical import Magical


class EliteCard(Card, Combatable, Magical):

    def play(self, game_state: dict) -> dict:
        self.game_state = game_state

        return {
            'card_played': self.name,
            'mana_used': self.cost,
            'effect': 'Elite card summoned with combat and magic abilities',
            'card_type': 'elite'
        }

    def attack(self, target) -> dict:
        self.target = target
        return {
                "attacker": self.name,
                "target": self.target,
                "damage": self.cost,
                "combat_type": "melee"
                }

    def defend(self, incoming_damage: int) -> dict:
        self.incoming_damage = incoming_damage
        return {
                "defender": self.name,
                "damage_taken": incoming_damage - 2,
                "damage_blocked": incoming_damage - 1,
                "still_alive": True
                }

    def get_combat_stats(self) -> dict:
        pass

    def cast_spell(self, spell_name: str, targets: list) -> dict:
        self.spell_name = spell_name
        self.targets = targets
        return {
                "caster": self.name,
                "spell": self.spell_name,
                "targets":  self.targets,
                "mana_used": self.cost
                }

    def channel_mana(self, amount: int) -> dict:
        self.amount = amount
        return {"channeled": self.amount,
                "total_mana": self.amount + self.cost
                }

    def get_magic_stats(self) -> dict:
        return {
            'mana_pool': self._mana_pool,
            'current_mana': self._current_mana
        }
