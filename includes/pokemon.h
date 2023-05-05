#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "moves.h"

using namespace std;

class Pokemon
{
public:
    Pokemon(const int &index,
            const string &name,
            const vector<string> types,
            const map<string, double> multipliers,
            const int hitPoints,
            const int attack,
            const int defense,
            const int special);

    ~Pokemon();

    string GetName();
    void Print();
    vector<string> GetTypes();
    int GetAttack();
    int GetDefense();
    void ressurrectPokemon();
    void takeDamage(int damage);
    void printPartyFormat();
    int GetIndex();

private:
    int m_index;
    string m_name;
    vector<string> m_types;
    map<string, double> m_multipliers;
    int m_hitPoints;
    bool m_isAlive;
    int m_attack;
    int m_defense;
    int m_special;
    vector<Moves *> m_moves;
};

#endif