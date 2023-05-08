#ifndef POKEDEX_H
#define POKEDEX_H

#include "pokemon.h"
#include "move.h"

#include <iostream>
#include <map>
#include <nlohmann/json.hpp>
#include <fstream>

#include <random>
#include <chrono>

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
    vector<Move> DefineMoves(const int hand_cap, vector<Move> all_moves, vector<string> types_to_choose);

    vector<string> m_types{"normal",
                           "fire",
                           "water",
                           "eletric",
                           "grass",
                           "ice",
                           "fight",
                           "posion",
                           "ground",
                           "flying",
                           "psychic",
                           "bug",
                           "rock",
                           "ghost",
                           "dragon"};

private:
    map<int, string>
        m_pokemons;
    json m_data;
    void ReadJsonData();
};

#endif