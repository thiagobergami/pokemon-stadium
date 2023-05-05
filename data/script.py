import pandas as pd
import requests
import csv
import time
import json

def makeARequest(url):
    response = requests.get(url)

    if response.status_code == 200:
        return response.json()
    else:
        print('Error: {}'.format(response.status_code))


metadata = {
    'description': 'Pokemon dataset',
    'creator': 'Your name',
    'columns': ['name', 'type', 'multipliers', 'hp', 'attack', 'defense', 'special', 'moves']
}
pokemon_dataset = {}

original_url = 'https://pokeapi.co/api/v2/pokemon/'
start_running = time.time()
# Define the path to the CSV file
csv_path = 'FirstGenPokemon.csv'

# Define the column you want to iterate over
column_name = "Name"

# Open the CSV file
with open(csv_path, 'r') as csvfile:
    # Create a CSV reader object
    csvreader = csv.DictReader(csvfile)

    # Iterate over each row in the CSV file
    for row in csvreader:
        start_time = time.time()
        pokemon_number = row["Number"]
        pokemon_name = row["Name"].lower()
        pokemon_type = [row["Type1"].lower(), row["Type2"].lower()]
        """ Normal,Fire,Water,Eletric,Grass,Ice,Fight,Poison,Ground,Flying,Psychic,Bug,Rock,Ghost,Dragon """
        print("Generating "+pokemon_name + " moves...")

        multipliers = {
            'normal': row["Normal"],
            'fire': row["Fire"],
            'water': row["Water"],
            'eletric': row["Eletric"],
            'grass': row["Grass"],
            'ice': row["Ice"],
            'fight': row["Fight"],
            'posion': row["Poison"],
            'ground': row["Ground"],
            'flying': row["Flying"],
            'psychic': row['Psychic'],
            'bug': row['Bug'],
            'rock': row['Rock'],
            'ghost': row['Ghost'],
            'dragon': row['Dragon']
        }
        pokemon_hp = row["HP"]
        pokemon_attack = row["Attack"]
        pokemon_defense = row["Defense"]
        pokemon_special = row["Special"]
        url = original_url+pokemon_name
        response = makeARequest(url)
        pokemon_moves = []

        count = 0
        for move in response["moves"]:
            pokemon_move = move["move"]["name"]
            move_url = move["move"]["url"]

            move_response = makeARequest(move_url)
            move_type = move_response["type"]["name"]
            move_power = move_response["power"]
            move_class = move_response["damage_class"]["name"]

            pokemon_moves.append({
                'name': pokemon_move,
                'type': move_type,
                'power': move_power,
                'class': move_class
            })
            count += 1
        end_time = time.time()
        execution_time = end_time - start_time
        print(pokemon_name+" moves generated: " + str(count))
        print("Execution time:", execution_time, "seconds")

        pokemon = {
            'name': pokemon_name,
            'type': pokemon_type,
            'multipliers': multipliers,
            'hp': pokemon_hp,
            'attack': pokemon_attack,
            'defense': pokemon_defense,
            'special': pokemon_special,
            'moves': pokemon_moves
        }
        pokemon_dataset[pokemon_number] = pokemon


json_string = json.dumps(pokemon_dataset, indent=2)

with open('pokedex2.json', 'w') as file:
    file.write(json_string)

end_running = time.time()
running_time = end_running - start_running
print("Script time:", running_time, "seconds")
