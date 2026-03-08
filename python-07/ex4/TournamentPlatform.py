# flake8: noqa
from ex4.TournamentCard import TournamentCard
from typing import Dict
import random


class TournamentPlatform:
    """Platform for managing tournament matches and rankings"""

    def __init__(self):
        """Initialize the tournament platform"""
        self._cards: Dict[str, TournamentCard] = {}
        self._matches_played = 0

    def register_card(self, card: TournamentCard) -> str:
        """
        Register a card for tournament play.

        Args:
            card: Tournament card to register

        Returns:
            str: Unique card ID
        """
        # Generate a unique ID
        card_id = f"{card._name.lower().replace(' ', '_')}_{len(self._cards):03d}"
        self._cards[card_id] = card
        return card_id

    def create_match(self, card1_id: str, card2_id: str) -> dict:
        """
        Create and simulate a match between two cards.

        Args:
            card1_id: ID of first card
            card2_id: ID of second card

        Returns:
            dict: Match result
        """
        if card1_id not in self._cards or card2_id not in self._cards:
            return {
                'error': 'Invalid card ID',
                'message': 'One or both cards not found'
            }

        card1 = self._cards[card1_id]
        card2 = self._cards[card2_id]

        # Simulate combat
        combat1 = card1.get_combat_stats()
        combat2 = card2.get_combat_stats()

        # Determine winner (higher power rating wins)
        power1 = combat1['power_rating']
        power2 = combat2['power_rating']

        # Add some randomness
        power1 += random.randint(-2, 2)
        power2 += random.randint(-2, 2)

        if power1 > power2:
            winner_id = card1_id
            loser_id = card2_id
            winner = card1
            loser = card2
        else:
            winner_id = card2_id
            loser_id = card1_id
            winner = card2
            loser = card1

        # Update ratings
        winner.update_wins(1)
        loser.update_losses(1)

        self._matches_played += 1

        return {
            'winner': winner_id,
            'loser': loser_id,
            'winner_rating': winner._rating,
            'loser_rating': loser._rating
        }

    def get_leaderboard(self) -> list:
        """
        Get the current tournament leaderboard.

        Returns:
            list: Sorted list of cards by rating
        """
        # Sort cards by rating (descending)
        sorted_cards = sorted(
            self._cards.items(),
            key=lambda x: x[1]._rating,
            reverse=True
        )

        leaderboard = []
        for rank, (card_id, card) in enumerate(sorted_cards, start=1):
            rank_info = card.get_rank_info()
            leaderboard.append({
                'rank': rank,
                'name': rank_info['name'],
                'rating': rank_info['rating'],
                'record': rank_info['record'],
                'card_id': card_id
            })

        return leaderboard

    def generate_tournament_report(self) -> dict:
        """
        Generate a comprehensive tournament report.

        Returns:
            dict: Tournament statistics
        """
        if not self._cards:
            return {
                'total_cards': 0,
                'matches_played': 0,
                'avg_rating': 0,
                'platform_status': 'empty'
            }

        total_rating = sum(card._rating for card in self._cards.values())
        avg_rating = total_rating // len(self._cards)

        return {
            'total_cards': len(self._cards),
            'matches_played': self._matches_played,
            'avg_rating': avg_rating,
            'platform_status': 'active' if self._matches_played > 0 else 'ready'
        }
