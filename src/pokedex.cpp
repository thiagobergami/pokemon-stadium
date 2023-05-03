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
    int i = 1;
    for (json &obj : m_data)
    {
        string name = obj["name"];
        m_pokemons[i] = name;
        ++i;
    }

    cout << "Pokedex Loaded." << endl;
}

Pokemon Pokedex::getPokemon(string pokemon)
{
    for (json &obj : m_data)
    {
        string name = obj["name"];
        if (name == pokemon)
        {
            vector<string> types = obj["type"];

            string string_hp = obj["hp"];
            int hitPoints = stoi(string_hp);

            string string_attack = obj["attack"];
            int attack = stoi(string_attack);

            string string_defense = obj["defense"];
            int defense = stoi(string_defense);

            string string_special = obj["special"];
            int special = stoi(string_special);

            map<string, double> multipliers;
            for (const auto &item : obj["multipliers"].items())
            {
                multipliers[item.key()] = stod(item.value().get<string>());
            }
        
            return Pokemon(
                name,
                types,
                multipliers,
                hitPoints,
                attack,
                defense,
                special);
        }
    }
};
