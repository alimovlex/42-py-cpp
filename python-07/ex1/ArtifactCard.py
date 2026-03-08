# flake8: noqa
from ex0.Card import Card
from typing import Dict


class ArtifactCard(Card):
    """Concrete implementation of an artifact card - permanent game modifiers"""

    def __init__(self, name: str, cost: int, rarity: str, durability: int, effect: str):
        """
        Initialize an artifact card.
        
        Args:
            name: The artifact's name
            cost: Mana cost to play the artifact
            rarity: Rarity level of the artifact
            durability: How long the artifact lasts (turns/uses)
            effect: Description of the artifact's permanent ability
        """
        super().__init__(name, cost, rarity)
        self._name = name
        self._cost = cost
        self._rarity = rarity
        self._durability = durability
        self._effect = effect
        self._current_durability = durability
    
    @property
    def durability(self) -> int:
        """Get the artifact's maximum durability"""
        return self._durability
    
    @property
    def current_durability(self) -> int:
        """Get the artifact's current durability"""
        return self._current_durability
    
    @property
    def effect(self) -> str:
        """Get the artifact's effect description"""
        return self._effect
    
    def play(self, game_state: dict) -> dict:
        """
        Play the artifact card (remains in play).
        
        Args:
            game_state: Current state of the game
            
        Returns:
            dict: Result of playing the artifact
        """
        result = {
            'card_played': self._name,
            'mana_used': self._cost,
            'effect': f'Permanent: {self._effect}',
        }
        
        return result
    
    def activate_ability(self) -> dict:
        """
        Activate the artifact's ongoing ability.
        
        Returns:
            dict: Result of ability activation
        """
        if self._current_durability <= 0:
            return {
                'artifact_name': self._name,
                'activated': False,
                'message': 'Artifact is destroyed (no durability remaining)'
            }
        
        self._current_durability -= 1
        
        result = {
            'artifact_name': self._name,
            'activated': True,
            'effect': self._effect,
            'durability_remaining': self._current_durability,
            'destroyed': self._current_durability <= 0
        }
        
        return result
    
    def repair(self, amount: int) -> None:
        """
        Repair the artifact, restoring durability.
        
        Args:
            amount: Amount of durability to restore
        """
        self._current_durability = min(self._current_durability + amount, self._durability)
    
    def __str__(self) -> str:
        """String representation of the artifact card"""
        return f"{self._name} (Artifact)"
