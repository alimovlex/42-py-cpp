from ex3.GameStrategy import GameStrategy


class AggressiveStrategy(GameStrategy):
    """Concrete aggressive strategy implementation"""

    def __init__(self):
        """Initialize the aggressive strategy"""
        self._name = "AggressiveStrategy"

    def disply_name(self) -> None:
        print(f"Strategy: {self.__class__.__name__}")

    def execute_turn(self, hand: list, battlefield: list) -> dict:
        """
        Execute an aggressive turn - prioritize damage and board presence.

        Args:
            hand: List of cards in hand
            battlefield: List of cards on battlefield

        Returns:
            dict: Result of turn execution
        """
        cards_played = []
        mana_used = 0
        mana_available = 10  # Assume 10 mana per turn

        # Sort hand by cost (play low-cost cards first for board presence)
        sorted_hand = sorted(hand, key=lambda card: card.cost)

        # Play as many cards as possible
        for card in sorted_hand:
            if mana_available >= card.cost:
                cards_played.append(card.name)
                mana_used += card.cost
                mana_available -= card.cost

        # Calculate damage dealt
        damage_dealt = len(cards_played) * 4

        # Target enemy player directly (aggressive strategy)
        targets_attacked = ['Enemy Player']

        return {
            'strategy': self.get_strategy_name(),
            'cards_played': cards_played,
            'mana_used': mana_used,
            'targets_attacked': targets_attacked,
            'damage_dealt': damage_dealt
        }

    def get_strategy_name(self) -> str:
        """Get the strategy name"""
        return self._name

    def prioritize_targets(self, available_targets: list) -> list:
        """
        Prioritize targets aggressively - prefer direct damage.

        Args:
            available_targets: List of available targets

        Returns:
            list: Prioritized targets (player first, then creatures)
        """
        prioritized = []

        # Attack player first (most aggressive)
        for target in available_targets:
            if 'player' in str(target).lower():
                prioritized.append(target)

        # Then attack creatures
        for target in available_targets:
            if target not in prioritized:
                prioritized.append(target)

        return prioritized
