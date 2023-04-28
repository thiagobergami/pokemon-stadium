""" Script to convert all csv to JSONs"""

import pandas as pd
import requests
import csv

metadata = {
    'description': 'Pokemon dataset',
    'creator': 'Your name',
    'columns': ['name', 'type', 'multipliers', 'hp', 'attack', 'defense', 'moves']
}


#df = pd.DataFrame(pokemon_dataset, columns=metadata['columns'])
pokemon_dataset = []

original_url = 'https://pokeapi.co/api/v2/pokemon/'

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
        pokemon_name = row["Name"].lower()
        pokemon_type = [row["Type1"].lower(), row["Type2"].lower()]
        """ Normal,Fire,Water,Eletric,Grass,Ice,Fight,Poison,Ground,Flying,Psychic,Bug,Rock,Ghost,Dragon """

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
        

        url = original_url+pokemon_name
        response = requests.get(url)

        # Check if the request was successful
        if response.status_code == 200:
            # Print the response data
            pokeon_response = response.json()
            for move in pokeon_response["moves"]:
                print(move["move"])
                print("////")
        else:
            # Print an error message
            print('Error: {}'.format(response.status_code))
        break
