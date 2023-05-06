#include "../includes/pokedex.h"
#include "../includes/pokemon.h"
#include <fstream>

Pokedex::Pokedex()
{
    ReadJsonData();
    Populate();
}

Pokedex::~Pokedex() {}
void Pokedex::printPokedex()
{
    for (const auto &pokemon : m_pokemons)
    {
        cout << pokemon.first << " - " << pokemon.second << endl;
    }
}

void Pokedex::ReadJsonData()
{
    ifstream file("../data/pokemonDatabase.json");
    file >> m_data;
}
void Pokedex::Populate()
{
    cout << "Loading Pokedex..." << endl;
    for (auto &element : m_data.items())
    {
        int index = stoi(element.key());
        json &pokemon_data = element.value();
        string name = pokemon_data["name"];
        m_pokemons[index] = name;
    }

    cout << "Pokedex Loaded." << endl;
}

Pokemon *Pokedex::getPokemon(int index)
{
    string key = to_string(index);
    json &pokemon_data = m_data[key];

    string name = pokemon_data["name"];

    vector<string> types = pokemon_data["type"];

    string string_hp = pokemon_data["hp"];
    int hitPoints = stoi(string_hp);

    string string_attack = pokemon_data["attack"];
    int attack = stoi(string_attack);

    string string_defense = pokemon_data["defense"];
    int defense = stoi(string_defense);

    string string_special = pokemon_data["special"];
    int special = stoi(string_special);

    map<string, double> multipliers;
    for (const auto &item : pokemon_data["multipliers"].items())
    {
        multipliers[item.key()] = stod(item.value().get<string>());
    }
    Pokemon *newPokemon = new Pokemon(
        index,
        name,
        types,
        multipliers,
        hitPoints,
        attack,
        defense,
        special);
    return newPokemon;
}

bool Pokedex::validateIndex(int &index) const
{
    for (auto &element : m_data.items())
    {
        int jsonIndex = stoi(element.key());
        if (jsonIndex == index)
        {
            return true;
        }
    }

    return false;
}
