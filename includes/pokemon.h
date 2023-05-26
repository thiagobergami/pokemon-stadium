#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "move.h"

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
            const int special,
            const vector<Move> moves);

    ~Pokemon();

    string GetName() const;
    void Print();
    vector<string> GetTypes();
    vector<Move> GetMoves();
    Move GetMoveByIndex(int index);
    int GetAttack();
    int GetDefense();
    int GetSpecial();
    void ressurrectPokemon();
    void TakeDamage(double damage);
    void printPartyFormat();
    int GetIndex();
    double GetMultiplier(const string type);

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
    vector<Move> m_moves;
};

#endif