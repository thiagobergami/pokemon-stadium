#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <vector>

#include "PokemonType.h"

using namespace std;

class Pokemon
{
public:
    Pokemon(const string &name,
            const vector<PokemonType *> &types,
            int hitPoints,
            const int attack, const int defense);

    ~Pokemon();

    string GetName();
    void Print();
    vector<PokemonType *> GetTypes();
    int GetAttack();
    int GetDefense();

private:
    string m_name;
    vector<PokemonType *> m_types;
    int m_hitPoints;
    int m_attack;
    int m_defense;
};

#endif