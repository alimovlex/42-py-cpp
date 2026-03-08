from ex0.Card import Card


class SpellCard(Card):
    """Concrete implementation of a spell card - instant magic effects"""

    def __init__(self, name: str, cost: int, rarity: str, effect_type: str):
        """
        Initialize a spell card.

        Args:
            name: The spell's name
            cost: Mana cost to cast the spell
            rarity: Rarity level of the spell
            effect_type: Type of effect (damage, heal, buff, debuff)
        """
        super().__init__(name, cost, rarity)
        # Store attributes since parent class doesn't
        self._name = name
        self._cost = cost
        self._rarity = rarity
        self._effect_type = effect_type

    @property
    def effect_type(self) -> str:
        """Get the spell's effect type"""
        return self._effect_type

    def play(self, game_state: dict) -> dict:
        """
        Play the spell card (one-time use).

        Args:
            game_state: Current state of the game

        Returns:
            dict: Result of playing the spell
        """
        result = {
            'card_played': self._name,
            'mana_used': self._cost,
            'effect': f'{self._effect_type.capitalize()} effect applied',
            'card_type': 'spell'
        }

        # Add specific effect description based on effect type
        if self._effect_type == 'damage':
            result['effect'] = f'Deal {self._cost} damage to target'
        elif self._effect_type == 'heal':
            result['effect'] = f'Heal {self._cost * 2} health'
        elif self._effect_type == 'buff':
            result['effect'] = f'Grant +{self._cost}/+{self._cost} buff'
        elif self._effect_type == 'debuff':
            result['effect'] = f'Apply -{self._cost} debuff to target'

        return result

    def resolve_effect(self, targets: list) -> dict:
        """
        Resolve the spell's effect on specific targets.

        Args:
            targets: List of targets to affect

        Returns:
            dict: Result of the effect resolution
        """
        result = {
            'spell_name': self._name,
            'effect_type': self._effect_type,
            'targets_affected': len(targets),
            'targets': targets,
            'resolved': True
        }

        if self._effect_type == 'damage':
            result['damage_dealt'] = self._cost * len(targets)
        elif self._effect_type == 'heal':
            result['health_restored'] = self._cost * 2 * len(targets)

        return result

    def __str__(self) -> str:
        """String representation of the spell card"""
        return f"{self._name} (Spell)"
