# Dictionary of players with their sports and achievements details
players = {
    "Serena Williams": {"sport": "Tennis", "achievements": 23},
    "Lionel Messi": {"sport": "Soccer", "achievements": 7},
    "Michael Phelps": {"sport": "Swimming", "achievements": 23},
    "Usain Bolt": {"sport": "Athletics", "achievements": 8},
    "Roger Federer": {"sport": "Tennis", "achievements": 20},
    "Cristiano Ronaldo": {"sport": "Soccer", "achievements": 5}
}

# Example 1: Lionel Messi
player_name = "Lionel Messi"
sport = players[player_name]["sport"]
achievements = players[player_name]["achievements"]

if achievements > 10:
    print(f"\n{player_name} plays {sport} and has {achievements} achievements.")
else:
    print(f"{player_name} does not have more than 10 achievements.")

print()

# Example 2: Usain Bolt
player_name = "Usain Bolt"
sport = players[player_name]["sport"]
achievements = players[player_name]["achievements"]

if achievements < 10 and sport != "Soccer":
    print(f"{player_name} plays {sport} and has only {achievements} achievements.")
else:
    print(f"{player_name} does not meet the criteria.")

print()

# Example 3: Roger Federer
player_name = "Roger Federer"
sport = players[player_name]["sport"]
achievements = players[player_name]["achievements"]

if sport == "Tennis" or achievements == 20:
    print(f"{player_name} meets the criteria! They play {sport} and have {achievements} achievements.\n")
else:
    print(f"{player_name} does not meet the criteria.")
