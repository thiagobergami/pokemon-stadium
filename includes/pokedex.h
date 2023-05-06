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

    Pokemon *getPokemon(int index);
    void Populate();
    void printPokedex();
    bool validateIndex(int &index) const;

private:
    map<int, string> m_pokemons;
    json m_data;
    void ReadJsonData();
};

#endif