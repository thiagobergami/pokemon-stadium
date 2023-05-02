#include "../includes/pokedex.h"
#include "../includes/pokemon.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

using namespace std;

Pokedex::Pokedex(const int totalPokemons) : Party(totalPokemons)
{
    m_pokemons.reserve(totalPokemons);
    Populate();
}

Pokedex::~Pokedex() {}

void Pokedex::Populate()
{
    cout << "Loading Pokedex..." << endl;
    ifstream file("../data/pokemonDatabase.json");
    json data;
    file >> data;

    for (json &obj : data)
    {
        string name = obj["name"];
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

        m_pokemons.push_back(new Pokemon(
            name,
            types,
            multipliers,
            hitPoints,
            attack,
            defense,
            special));
    }

    cout << "Pokedex Loaded." << endl;
}