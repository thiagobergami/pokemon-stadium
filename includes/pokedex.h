#ifndef POKEDEX_H
#define POKEDEX_H

#include "pokemon.h"

#include <iostream>
#include <map>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class Pokedex
{
public:
    Pokedex();

    virtual ~Pokedex();

    Pokemon getPokemon(string pokemon);
    void Populate();
    void printPokedex();

private:
    map<int, string> m_pokemons;
    json m_data;
    void ReadJsonData();
};

#endif