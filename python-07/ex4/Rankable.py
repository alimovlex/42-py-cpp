from abc import ABC, abstractmethod


class Rankable(ABC):
    """Abstract interface for ranking and tournament capabilities"""

    @abstractmethod
    def calculate_rating(self) -> int:
        """
        Calculate the current rating based on performance.

        Returns:
            int: Current rating
        """
        pass

    @abstractmethod
    def update_wins(self, wins: int) -> None:
        """
        Update the number of wins.

        Args:
            wins: Number of wins to add
        """
        pass

    @abstractmethod
    def update_losses(self, losses: int) -> None:
        """
        Update the number of losses.

        Args:
            losses: Number of losses to add
        """
        pass

    @abstractmethod
    def get_rank_info(self) -> dict:
        """
        Get ranking information.

        Returns:
            dict: Ranking information including wins, losses, and rating
        """
        pass
