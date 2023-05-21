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
    void RemovePokemon(Pokemon *aPokemon);
    void Clear();
    void printParty();
    Pokemon *GetActivatedPokemon() const;

protected:
    vector<Pokemon *> m_pokemons;
    Pokemon *m_activated_pokemon;
};

#endif