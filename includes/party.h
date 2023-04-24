#ifndef PARTY_H
#define PARTY_H
#include <vector>
#include "pokemon.h"

using std::vector;

class Party
{
public:
    Party(const int totalParty);

    virtual ~Party();

    void addPokemon(Pokemon *aPokemon);
    void Clear();

    void printParty();

protected:
    vector<Pokemon *> m_pokemons;
};

#endif