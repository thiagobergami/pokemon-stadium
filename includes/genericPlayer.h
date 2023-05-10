#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "party.h"
#include "pokemon.h"
#include "move.h"

using namespace std;
class GenericPlayer : public Party
{

public:
    GenericPlayer(const string &name = "", const int &totalPokemons = 6);

    virtual ~GenericPlayer();

    bool IsDefeated() const;
    void Win() const;
    void Loss();
    Pokemon *activatePokemon(int index);
    bool validatePartyPokemon(int index);
    double CalculateDamageCalculateDamage(Move attacker_move, Pokemon *attacker_pokemon, Pokemon *defenser_pokemon, double modifier);

protected:
    string m_Name;
    bool m_isDefeated;
    int totalPokemons;
};

#endif