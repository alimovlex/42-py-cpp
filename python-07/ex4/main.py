# flake8: noqa
"""
DataDeck Tournament Platform Demonstration
Showcases advanced interface composition with multiple inheritance
"""

from ex4.TournamentCard import TournamentCard
from ex4.TournamentPlatform import TournamentPlatform


def main():
    """Demonstrate the tournament platform"""
    print("\n=== DataDeck Tournament Platform ===")
    platform = TournamentPlatform()
    print()
    print("Registering Tournament Cards...\n")
    fire_dragon = TournamentCard(
        name="Fire Dragon",
        cost=5,
        rarity="Legendary",
        attack_power=7,
        defense=5
    )
    ice_wizard = TournamentCard(
        name="Ice Wizard",
        cost=4,
        rarity="Rare",
        attack_power=5,
        defense=4
    )

    dragon_id = platform.register_card(fire_dragon)
    wizard_id = platform.register_card(ice_wizard)

    print(f"{fire_dragon._name} (ID: {dragon_id}):")
    print("- Interfaces: [Card, Combatable, Rankable]")
    print(f"- Rating: {fire_dragon._rating}")
    print(f"- Record: {fire_dragon._wins}-{fire_dragon._losses}")

    print(f"\n{ice_wizard._name} (ID: {wizard_id}):")
    print("- Interfaces: [Card, Combatable, Rankable]")
    print(f"- Rating: {ice_wizard._rating}")
    print(f"- Record: {ice_wizard._wins}-{ice_wizard._losses}")

    print("\nCreating tournament match...")
    match_result = platform.create_match(dragon_id, wizard_id)
    print(f"Match result: {match_result}")

    print("\nTournament Leaderboard:")
    leaderboard = platform.get_leaderboard()
    for entry in leaderboard:
        print(f"{entry['rank']}. {entry['name']} - Rating: {entry['rating']} ({entry['record']})")

    print("\nPlatform Report:")
    report = platform.generate_tournament_report()
    print(f"{report}")

    print("\n=== Tournament Platform Successfully Deployed! ===")
    print("All abstract patterns working together harmoniously")


if __name__ == "__main__":
    main()
