# flake8: noqa
from ex0.Card import Card
from ex2.Combatable import Combatable
from ex4.Rankable import Rankable


class TournamentCard(Card, Combatable, Rankable):
    """Tournament card combining Card, Combatable, and Rankable interfaces"""

    def __init__(self, name: str, cost: int, rarity: str, attack_power: int, defense: int):
        """
        Initialize a tournament card.

        Args:
            name: Card name
            cost: Mana cost
            rarity: Card rarity
            attack_power: Attack strength
            defense: Defense capability
        """
        super().__init__(name, cost, rarity)
        # Store base attributes
        self._name = name
        self._cost = cost
        self._rarity = rarity
        # Combat attributes
        self._attack_power = attack_power
        self._defense = defense
        # Tournament attributes
        self._wins = 0
        self._losses = 0
        self._base_rating = 1200
        self._rating = self._base_rating

    # Card interface implementation
    def play(self, game_state: dict) -> dict:
        """Play the tournament card"""
        return {
            'card_played': self._name,
            'mana_used': self._cost,
            'effect': 'Tournament card played',
            'card_type': 'tournament',
            'rating': self._rating
        }

    def get_card_info(self) -> dict:
        """Get card information"""
        return {
            'name': self._name,
            'cost': self._cost,
            'rarity': self._rarity,
            'type': 'tournament',
            'rating': self._rating
        }

    def is_playable(self, available_mana: int) -> bool:
        """Check if card is playable"""
        return available_mana >= self._cost

    # Combatable interface implementation
    def attack(self, target) -> dict:
        """Perform an attack"""
        return {
            'attacker': self._name,
            'target': target,
            'damage': self._attack_power,
            'combat_type': 'tournament_combat'
        }

    def defend(self, incoming_damage: int) -> dict:
        """Defend against damage"""
        damage_blocked = min(self._defense, incoming_damage)
        damage_taken = incoming_damage - damage_blocked

        return {
            'defender': self._name,
            'damage_taken': damage_taken,
            'damage_blocked': damage_blocked,
            'survived': damage_taken < self._defense
        }

    def get_combat_stats(self) -> dict:
        """Get combat statistics"""
        return {
            'attack': self._attack_power,
            'defense': self._defense,
            'power_rating': self._attack_power + self._defense
        }

    # Rankable interface implementation
    def calculate_rating(self) -> int:
        """Calculate current rating based on wins and losses"""
        # Simple ELO-like calculation
        win_value = 16
        self._rating = self._base_rating + (self._wins * win_value) - (self._losses * win_value)
        return self._rating

    def update_wins(self, wins: int) -> None:
        """Update wins"""
        self._wins += wins
        self.calculate_rating()

    def update_losses(self, losses: int) -> None:
        """Update losses"""
        self._losses += losses
        self.calculate_rating()

    def get_rank_info(self) -> dict:
        """Get ranking information"""
        return {
            'name': self._name,
            'rating': self._rating,
            'wins': self._wins,
            'losses': self._losses,
            'record': f"{self._wins}-{self._losses}"
        }

    def get_tournament_stats(self) -> dict:
        """Get comprehensive tournament statistics"""
        return {
            'card_info': self.get_card_info(),
            'combat_stats': self.get_combat_stats(),
            'rank_info': self.get_rank_info()
        }

    def __str__(self) -> str:
        """String representation"""
        return f"{self._name} (Tournament Card)"
