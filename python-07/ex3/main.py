from .FantasyCardFactory import FantasyCardFactory
from .AggressiveStrategy import AggressiveStrategy
from .GameEngine import GameEngine

if __name__ == "__main__":

    print("\n=== DataDeck Game Engine ===\n")
    print("Configuring Fantasy Card Game...")
    fantasy = FantasyCardFactory()
    agressive = AggressiveStrategy()
    fantasy.display_name()
    agressive.disply_name()
    print(f"Available types: {fantasy.get_supported_types()}")
    print()
    game_engine = GameEngine()
    game_engine.configure_engine(fantasy, agressive)
    print("Simulating aggressive turn...")
    result = game_engine.simulate_turn()
    print(f"Hand: {result["hand"]}")
    print()
    print("Turn execution:")
    turn_exec = result['turn_execution']
    print(f"Strategy: {turn_exec['strategy']}")
    print(f"Actions: {{'cards_played': "
          f"{turn_exec['cards_played']}, "
          f"'mana_used': {turn_exec['mana_used']}, "
          f"'targets_attacked': {turn_exec['targets_attacked']}, "
          f"'damage_dealt': {turn_exec['damage_dealt']}}}")
    print()
    print("Game Report:")
    status = game_engine.get_engine_status()
    print(f"{{'turns_simulated': {status['turns_simulated']}, "
          f"'strategy_used': '{status['strategy_used']}', "
          f"'total_damage': {status['total_damage']}, "
          f"'cards_created': {status['cards_created']}}}")

    print("\nAbstract Factory + Strategy Pattern: "
          "Maximum flexibility achieved!")
