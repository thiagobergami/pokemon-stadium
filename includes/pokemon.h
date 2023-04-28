#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pokemon
{
public:
    Pokemon(const string &name,
            const vector<string> types,
            int hitPoints,
            const int attack,
            const int defense);

    ~Pokemon();

    string GetName();
    void Print();
    vector<string> GetTypes();
    int GetAttack();
    int GetDefense();
    void ressurrectPokemon();
    void takeDamage(int damage);

private:
    string m_name;
    vector<string> m_types;
    int m_hitPoints;
    bool m_isAlive;
    int m_attack;
    int m_defense;
};

#endif