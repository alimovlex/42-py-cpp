# flake8: noqa
from ex3.CardFactory import CardFactory
from ex3.GameStrategy import GameStrategy
from typing import Optional


class GameEngine:
    """Game engine orchestrator that coordinates factory and strategy"""

    def __init__(self):
        """Initialize the game engine"""
        self._factory: Optional[CardFactory] = None
        self._strategy: Optional[GameStrategy] = None
        self._turns_simulated = 0
        self._total_damage = 0
        self._cards_created = 0

    def configure_engine(self, factory: CardFactory, strategy: GameStrategy) -> None:
        """
        Configure the game engine with factory and strategy.

        Args:
            factory: Card factory to use
            strategy: Game strategy to use
        """
        self._factory = factory
        self._strategy = strategy

    def simulate_turn(self) -> dict:
        """
        Simulate a game turn using the configured factory and strategy.

        Returns:
            dict: Result of the turn simulation
        """
        if not self._factory or not self._strategy:
            return {
                'error': 'Engine not configured',
                'message': 'Call configure_engine() first'
            }

        # Create a hand of cards using the factory
        hand = [
            self._factory.create_creature(),
            self._factory.create_creature('goblin'),
            self._factory.create_spell()
        ]
        self._cards_created += len(hand)

        # Simulate battlefield (empty for now)
        battlefield = []

        # Execute turn using strategy
        turn_result = self._strategy.execute_turn(hand, battlefield) or {}

        # Update engine stats
        self._turns_simulated += 1
        self._total_damage += turn_result.get('damage_dealt', 0)

        return {
            'hand': [f"{card.name} ({card.cost})" for card in hand],
            'turn_execution': turn_result
        }

    def get_engine_status(self) -> dict:
        """
        Get current engine status.

        Returns:
            dict: Engine status information
        """
        return {
            'turns_simulated': self._turns_simulated,
            'strategy_used': self._strategy.get_strategy_name() if self._strategy else 'None',
            'total_damage': self._total_damage,
            'cards_created': self._cards_created,
            'factory_configured': self._factory is not None,
            'strategy_configured': self._strategy is not None
        }
