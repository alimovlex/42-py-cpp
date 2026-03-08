# flake8: noqa
from ex0.CreatureCard import CreatureCard
from ex1.SpellCard import SpellCard
from ex1.ArtifactCard import ArtifactCard
from ex0.Card import Card
from .CardFactory import CardFactory
from typing import Optional, Union
import random


class FantasyCardFactory(CardFactory):
    """Concrete factory for creating fantasy-themed cards"""

    def __init__(self):
        """Initialize the fantasy card factory"""
        self._creature_types = {
            'dragon': {'cost': 5, 'rarity': 'Rare'},
            'goblin': {'cost': 2, 'rarity': 'Common'}
        }
        self._spell_types = {
            'fireball': {'cost': 3, 'effect_type': 'damage', 'rarity': 'Common'}
        }
        self._artifact_types = {
            'mana_ring': {'cost': 2, 'durability': 5, 'effect': '+1 mana', 'rarity': 'Uncommon'}
        }

    def display_name(self) -> None:
        print(f"Factory: {self.__class__.__name__}")

    def create_creature(self, name_or_power: str | int | None = None) -> Card:
        """
        Create a fantasy creature card.

        Args:
            name_or_power: Creature type name or power level

        Returns:
            Card: Created creature card
        """
        if isinstance(name_or_power, str) and name_or_power in self._creature_types:
            creature_type = name_or_power
        else:
            # Default to random creature
            creature_type = random.choice(list(self._creature_types.keys()))

        config = self._creature_types[creature_type]
        name = f"{creature_type.capitalize()} Warrior" if creature_type == 'goblin' else f"Fire Dragon"

        return CreatureCard(
            name=name,
            cost=config['cost'],
            rarity=config['rarity'],
            attack=None,
            health=None
        )

    def create_spell(self, name_or_power: Optional[Union[str, int]] = None) -> Card:
        """
        Create a fantasy spell card.

        Args:
            name_or_power: Spell type name or power level

        Returns:
            Card: Created spell card
        """
        if isinstance(name_or_power, str) and name_or_power in self._spell_types:
            spell_type = name_or_power
        else:
            spell_type = random.choice(list(self._spell_types.keys()))

        config = self._spell_types[spell_type]
        name = f"{spell_type.capitalize().replace('_', ' ')}" if spell_type == 'fireball' else "Lightning Bolt"

        return SpellCard(
            name=name if spell_type == 'fireball' else "Lightning Bolt",
            cost=config['cost'],
            rarity=config['rarity'],
            effect_type=config['effect_type']
        )

    def create_artifact(self, name_or_power: Optional[Union[str, int]] = None) -> Card:
        """
        Create a fantasy artifact card.

        Args:
            name_or_power: Artifact type name or power level

        Returns:
            Card: Created artifact card
        """
        if isinstance(name_or_power, str) and name_or_power in self._artifact_types:
            artifact_type = name_or_power
        else:
            artifact_type = random.choice(list(self._artifact_types.keys()))

        config = self._artifact_types[artifact_type]
        name = artifact_type.replace('_', ' ').title()

        return ArtifactCard(
            name=name,
            cost=config['cost'],
            rarity=config['rarity'],
            durability=config['durability'],
            effect=config['effect']
        )

    def create_themed_deck(self, size: int) -> dict:
        """
        Create a fantasy-themed deck.

        Args:
            size: Number of cards in the deck

        Returns:
            dict: Dictionary containing the deck
        """
        deck = []

        # Create a balanced deck
        for i in range(size):
            if i % 3 == 0:
                deck.append(self.create_creature())
            elif i % 3 == 1:
                deck.append(self.create_spell())
            else:
                deck.append(self.create_artifact())

        return {
            'deck': deck,
            'size': len(deck),
            'theme': 'Fantasy',
            'factory': 'FantasyCardFactory'
        }

    def get_supported_types(self) -> dict:
        """Get supported card types"""
        return {
            'creatures': list(self._creature_types.keys()),
            'spells': list(self._spell_types.keys()),
            'artifacts': list(self._artifact_types.keys())
        }
